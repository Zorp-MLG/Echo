<img width="2000" height="2000" alt="ECHO LOGO" src="https://github.com/user-attachments/assets/cf5f9310-f723-4a03-9de5-2fa5271e829f" />


# ECHO AI


---
# What is echo?

Its an half embodied ai, it doesnt have legs, but it has servos so the ai can move the camera.
Echo also has speakers and microphones, so you can "talk" with it.
You can use both local ai, and APIs!

# Why did you make echo?

I wanted something that can help me solder, by using the sensors to see if the iron is too hot, or if im doing anything wrong!


# Who should use echo?

Anywhere from students/teachers, factories/business to hobbyist.

students and teachers can use it to learn better by using something that knows the theory.

Factorys and business can use it to help workers know what to do.

Hobbyistcan use it for the same reasons of students!


# How does it look?
(bare pcb)
<img width="527" height="353" alt="2D PCB" src="https://github.com/user-attachments/assets/05e22f23-43d7-474f-9d24-99fa6e9252d4" />
<img width="839" height="704" alt="3D PCB SIDE" src="https://github.com/user-attachments/assets/86f7523a-0658-4e92-ac18-4ffd30411a3a" />
<img width="823" height="588" alt="3D PCB TOP" src="https://github.com/user-attachments/assets/30601d92-c07a-497c-8b24-c5bde0c6a142" />

# Wheres the files to remake this?
In main branch

# How do i recreate this?

1.Get PCB files.
2.Fabricate it.
3.buy all the semiconductors/modules.
4.solder it together.
5.download all the software you need(esp32, ai etc etc).
6.connect the microcontroller via usb to your PC.
7.transfer all the files/Set it up.
8. done.

# BOM:

| ITEMS:             | PRICE ESTIMATE: | UNITS: | TOTAL:  |   
|--------------------|-----------------|--------|---------|
| XIAO_ESP32S3       | 20 USD          | 2      |         | 
| XIAO_ESP32S3 SENSE | 20 USD          | 2      |         |  
| MQ-2               | 5 USD           | 1      |         |
| MQ-135             | 5 USD           | 1      |         |
| INMP441            | 5 USD           | 2      |         |
| PMS7003            | 30 USD          | 1      |         |
| TSL2561T           | 10 USD          | 1      |         |   
| BME680             | 10 USD          | 1      |         |  
| MAX7219            | 15 USD          | 1      |         |  
| CD74HCT125E        | 1 USD           | 1      |         |   
| SG90-SERVO         | 5 USD           | 4      |         |  
| 100k RES           | 0.10 USD        | 7      |         |  
| MOSFET             | 0.69 USD        | 3      |         |  
| USB C              | 0.50 USD        | 4      |         |   
| 1N5819             | 0.10 USD        | 3      |         |   
| 100uF CAP          | 0.48 USD        | 1      |         |  
|                    |                 |        | $191.55 |
|                    |                 |        |         |


# How it works together 

Each sensor sends data to the Microcontrollers, and those Microcontrollers sends data to an AI in an prompt. The prompt includes each sensors data, and the prompt gets updated after a set amount of time. 

The AI decides what to do with the data. The AI can for example move the camera or turn on a fan via keywords in the firmware of the Microcontroller.

The Microcontroller reads thru the message and registers that the ai used an keyword like "Turn_on_fan", and the Microcontroller turns on the fan.

# Picture of schematic:
<img width="711" height="502" alt="image" src="https://github.com/user-attachments/assets/7ea82394-01a3-4ad3-9d91-a9e1d259310d" />

# PDF of schematic:
[Schematic_Echo_2026-11-21.pdf](https://github.com/user-attachments/files/35217184/Schematic_Echo_2026-11-21.pdf)

