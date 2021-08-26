# Proyek Praktik Kerja Lapangan

## Soil Fertility Detection System

### Hardware Specification

- Microcontroller
  - Arduino Nano  
    ![Arduino Nano](arduino-nano.png)

- Sensor
  - Soil Ph Meter Sensor  
    ![Soil Ph Meter Sensor](ph-sensor.png)

  - Capacitive Soil Moisture Sensor  
    ![Capacitive Soil Moisture Sensor](capacitive-soil-moisture-sensor.png)
  
  - GPS & Location Sensor (smartphone built in)

- Actuator
  - Serial communication
  - LED
  - Buzzer

- Smartphone
  - Android smartphone with support for GPS, Location, and USB On-The-Go

### Images

System Block Diagram  
![System block diagram](./blok-diagram.png)

Android App Flowchart  
![Android flowchart](flowchart-android.png)

Hardware Flowchart  
![Hardware flowchart](flowchart-microcontroller.png)

Hardware Schematic  
![Hardware Schematic](hardware-schematic.png)

System Prototype  
![Prototype](prototype.png)

### Arduino Program code

To run the system, we need to built program to fetch the data from sensor. We using Arduino IDE to program the Arduino Nano. You can look the code in [arduino-code.ino](arduino-code.ino) file.

### Android Application code

We using Kodular to build the Android application. This platform are great and very easy to use to create simple Android application because it using block code. You can look the code blocks below.  
![Kodular code](kodular_blocks.png)

### Android Application UI

![App 1](app-1.png)

![App 2](app-2.png)

![App 3](app-3.png)
