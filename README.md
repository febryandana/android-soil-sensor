---
description: A microcontroller-based soil fertility detection system.
---

# Dekatanah

### Abstract

Soil is the most used plant growth medium. However, due to various soil conditions, not all plants are also suitable for the particular soil to be used, so a tool or sensor is needed that can read and measure soil fertility. Simple soil fertility measurement can be measured from 2 elements of soil fertility attributes, namely the soil pH element and the soil moisture element. Most of the available soil fertility detection instruments or systems only use one of the soil fertility elements and the data on the detection results can't be stored for a long period, making the readings less effective. From these problems, we conducted research to build a soil fertility detection system that uses a soil pH sensor and a soil moisture sensor that is connected to the Arduino Nano microcontroller and can be run with an application on a smartphone. The results of this study are in the form of a soil fertility detection tool and system that can read soil pH and soil moisture content and an Android smartphone application that is connected to the device via the USB-OTG feature. With this application, a test location is obtained where the soil is tested and then stored in the TinyDB database in the application so that data will not be lost even if the tool is turned off.

**Keywords**: _soil, fertility, pH sensor, moisture sensor, microcontroller, Android application_

### Hardware Specifications

1\. Arduino Nano microcontroller

![Arduino Nano microcontroller](https://raw.githubusercontent.com/febryandana/dekatanah/main/arduino-nano.png)

2\. Soil pH meter sensor

![Soil pH meter sensor](https://raw.githubusercontent.com/febryandana/dekatanah/main/ph-sensor.png)

3\. Capacitive soil moisture sensor

![Capacitive soil moisture sensor](https://raw.githubusercontent.com/febryandana/dekatanah/main/capacitive-soil-moisture-sensor.png)

4\. LED lamp indicator

5\. Active Buzzer

6\. Voltage Regulator

7\. Switch/Push button

8\. Diode

9\. Jumper cable

10\. USB-OTG Adapter

11\. Micro USB / Type C USB cable (depends on smartphone USB port)

12\. Printed Circuit Board

13\. Case

14\. Smartphone with support for USB On-The-Go, GPS, and Location Sensor

### System Design

#### System Block Diagram

![System block diagram](https://raw.githubusercontent.com/febryandana/dekatanah/main/en\_block-diagram.png)

#### Hardware Schematic

![Hardware schematic](https://raw.githubusercontent.com/febryandana/dekatanah/main/hardware-schematic.png)

#### Hardware System Flowchart

![Hardware system flowchart](https://raw.githubusercontent.com/febryandana/dekatanah/main/flowchart-microcontroller.png)

#### Android App Main Program Flowchart

![Android main flowchart](https://raw.githubusercontent.com/febryandana/dekatanah/main/android-flowchart/main-program.png)

#### Android App Sub Program Flowchart

* Serial communication

![Serial communication](https://raw.githubusercontent.com/febryandana/dekatanah/main/android-flowchart/sub-serial-comm.png)

* Clock

![Clock](https://raw.githubusercontent.com/febryandana/dekatanah/main/android-flowchart/sub-clock.png)

* Location sensor

![Location sensor](https://raw.githubusercontent.com/febryandana/dekatanah/main/android-flowchart/sub-location-sensor.png)

* Show map marker

![Show map marker](https://raw.githubusercontent.com/febryandana/dekatanah/main/android-flowchart/sub-show-map.png)

* Save data

![Save data](https://raw.githubusercontent.com/febryandana/dekatanah/main/android-flowchart/sub-save-data.png)

* Delete data

![Delete data](https://raw.githubusercontent.com/febryandana/dekatanah/main/android-flowchart/sub-delete-data.png)

* Save data list

![Save data list](https://raw.githubusercontent.com/febryandana/dekatanah/main/android-flowchart/sub-save-list-data.png)

***

### Prototype Implementation

#### Hardware prototype

* PCB design

![PCB design](https://raw.githubusercontent.com/febryandana/dekatanah/main/pcb-design.png)

* Final prototype

![Final prototype](https://raw.githubusercontent.com/febryandana/dekatanah/main/prototype.png)

* Prototype on use

![Prototype on use](https://raw.githubusercontent.com/febryandana/dekatanah/main/hardware-usage.png)

#### Arduino Program

{% embed url="https://gist.github.com/febryandana/9620aa1c822348e4fca90ce2e922e684" %}

#### Android Application Program

This Android application uses Kodular Blocks, read more: [https://docs.kodular.io/](https://docs.kodular.io)

The full image of these blocks can be seen on: [`kodular-blocks/kodular-blocks.png`](https://raw.githubusercontent.com/febryandana/dekatanah/main/kodular-blocks/kodular\_blocks.png).

* Main program initialization

![Main program initialization](https://raw.githubusercontent.com/febryandana/dekatanah/main/kodular-blocks/main-program-initialization.png)

* 0pen serial connection

![0pen serial connection](https://raw.githubusercontent.com/febryandana/dekatanah/main/kodular-blocks/open-serial-conn.png)

* Read serial data

![Read serial data](https://raw.githubusercontent.com/febryandana/dekatanah/main/kodular-blocks/read-serial-data.png)

* Get location

![Get location](https://raw.githubusercontent.com/febryandana/dekatanah/main/kodular-blocks/get-location.png)

* Address input

![Address input](https://raw.githubusercontent.com/febryandana/dekatanah/main/kodular-blocks/address-input.png)

* Show location map

![Show location map](https://raw.githubusercontent.com/febryandana/dekatanah/main/kodular-blocks/show-map.png)

* Save data and list

![Save data and list](https://raw.githubusercontent.com/febryandana/dekatanah/main/kodular-blocks/save-data.png)

* Delete data

![Delete data](https://raw.githubusercontent.com/febryandana/dekatanah/main/kodular-blocks/delete-data.png)

#### Android Application User Interface

![App 1](https://raw.githubusercontent.com/febryandana/dekatanah/main/app-1.png)

![App 2](https://raw.githubusercontent.com/febryandana/dekatanah/main/app-2.png)

![App 3](https://raw.githubusercontent.com/febryandana/dekatanah/main/app-3.png)

### **End Notes**

This is a simple college project for Praktik Kerja Lapangan which is supervised by a lecturer. There is still much room for improvement.
