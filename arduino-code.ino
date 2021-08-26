/*
Hasil Kalibrasi Sensor Moisture 5V
Air = 698 ~ 719
Lembab = 719 ~ 852
Kering = 852 ~ 876
Nilai sensor pH
Asam = < 6
Netral = 6 ~ 7
Basa = > 7
 */

//Control panel alat dan pembacaan sensor
#define data 100
int toleransiMoist = 20;
float toleransipH = 0.2;
int delay_pembacaan = 20;

//Output debug
bool debugMode = false;
float nilaiPHDebug = 5;
int nilaiMoistDebug = 850;

//Define PIN yang digunakan
#define analogMoisture A2
#define analogPH A0
#define sw 2
#define buzzer 4

//Nilai default untuk alat
int looping = 0;
int nilaimoist[data] = {0};
float nilaipH[data] = {0};
bool started = false;
float nilaiSensorpH = 0.0;

//Machine state
int state = 0;

//Untuk debouncing switch interrupt
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 2000;

//Interrupt, dengan debouncing tombol
void interrupt_routine() {
    if((millis() - lastDebounceTime) > debounceDelay && started) {
        lastDebounceTime = millis();
        state = 1;
    }
}

//Buzzer beep
void check() {
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
}

//Output serial ke smartphone
void output(int inputMoistRef, float inputPHRef) {
    int inputMoist;
    float inputPH;
    if(debugMode) {
        inputMoist = nilaiMoistDebug;
        inputPH = nilaiPHDebug;
    } else {
        inputMoist = inputMoistRef;
        inputPH = inputPHRef;
    }

    //data bahasa
    String keadaanKelembaban[4] = {"ERROR_", "kering", "lembab", "basah"};
    String keadaanPH[4] = {"ERROR_", "netral", "terlalu asam", "terlalu basa"};

    //integer untuk output
    int outKelembaban = 0, outPH = 0;

    //Setting output kelembaban
    //Kering = 876 ~ 852
    if(inputMoist > 852) {
        outKelembaban = 1;
        }
    
    //Lembab = 852 ~ 719
    else if(inputMoist <= 852 && inputMoist > 719) {
        outKelembaban = 2;
    }
    
    //Basah = 719 ~ 698
    else if(inputMoist <= 719 && inputMoist > 698) {
        outKelembaban = 3;
    }

    //Setting output pH
    //Netral (6 ~ 7)
    if(inputPH >= 6 && inputPH <= 7) {
        outPH = 1;
    }

    //Terlalu asam (< 6)
    else if(inputPH >= 0 && inputPH < 6) {
        outPH = 2;
    }

    //Terlalu basa (> 7)
    else if(inputPH > 7 && inputPH <= 14) {
        outPH = 3;
    }
 
    //Output status tanah
    while(digitalRead(sw)) {
        Serial.print("Status tanah ");
        Serial.print(keadaanPH[outPH]);
        Serial.print(" pH ");
        Serial.print(inputPH);
        Serial.print(" dan ");
        Serial.print(keadaanKelembaban[outKelembaban]);
        if(outKelembaban == 0) {
            Serial.print(inputMoist);
        }
        Serial.println(".");
        delay(1000);
    }
    check();
    delay(500);
}

//State 1, mengukur
void mengukur() {
    //User feedback
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
 
    //Mulai pengukuran
    //Sensor kelembaban
    while(looping != data) {
        if(analogRead(analogMoisture) - nilaimoist[0] > toleransiMoist || nilaimoist[0] - analogRead(analogMoisture) > toleransiMoist) {
            looping = 0;
            nilaimoist[0] = analogRead(analogMoisture);
        } else {
            nilaimoist[looping] = analogRead(analogMoisture);
            looping++;
        }
        delay(delay_pembacaan);
    }
    looping = 0;

    //Sensor pH
    while(looping != data) {
        nilaiSensorpH = (-0.0693*analogRead(analogPH))+7.3855
        if(nilaiSensorpH - nilaipH[0] > toleransipH || nilaipH[0] - nilaiSensorpH > toleransipH) {
            looping = 0;
            nilaipH[0] = nilaiSensorpH;
        } else {
            nilaipH[looping] = nilaiSensorpH;
            looping++;
        }
        delay(delay_pembacaan);
    }
    looping = 0;

    //User feedback
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);

    //Output serial
    output(nilaimoist[0], nilaipH[0]);

    //state 0
    state = 0;
}

void setup() {
    pinMode(sw, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
    check();
    attachInterrupt(digitalPinToInterrupt(sw), interrupt_routine, FALLING);
}

void loop() {
    //sebagai syarat interrupt
    started = true;

    //state machine
    switch(state) {
        case 1:
            mengukur();
        break;
        default:
        break;
    }
}