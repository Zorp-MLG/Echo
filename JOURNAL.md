Hi! the first two Developer logs sadly wont be the forge format, since i forgot to do it (lol)

I hope the two non forge format dev logs are still good!

# DevLog_1
# 2026-09-10


# What i did
I started with putting in all the sensors i wanted, which was these:
1. MQ-135 (gas sensor, to be able to "smell" solder fumes)
2. MQ-2 (smoldering fumes and more, related to solder fumes of MQ-135, but fills the holes MQ-135 cant do)
3. DHT-22 (humidity and temperature)
4. SEEDSTUDIO R24D FMCW LITE ( It looks for people and is able to see if they are sitting down, laying, or walking around and their distance and speed)
5. TSL2561T (ambient light sensor)
6. BME680 (air quality, helps with soldering fumes)
7. PMS7003 (ultrafine particle sensor, helps with soldering fumes)
8. INMP441 (microphone)
9. Xiao ESP32s3 (microcontroller)
10. Xiao ESP32s3 sense(camera)
thats pretty much all.


# What went wrong
A few of the schematic symbols didnt have pcb symbols, I had to change them.


# What I will add next time
Fans
TFT screens

# How many hours (counted with lapse)
3 hours, 9 minutes, 20 seconds.

look at picture 2.

# picture 1.
<img width="603" height="527" alt="image" src="https://github.com/user-attachments/assets/1400c560-fb48-4753-9832-3b5a839f7f31" />


# picture 2.

<img width="1439" height="802" alt="image" src="https://github.com/user-attachments/assets/6ab7f950-0121-4afc-805d-0cb0ad02f1ae" />
 ---- -----
# DevLog_2

# 2026-09-11


# What i did
I added 
-MAX7219 modules (a screen that has big pixels, so it looks more like pixel art)
-3x female USB A modules (for the fans that i want the ai to be able to control)
-3x MOSFETS (so the micocontroller/ai can control the fans)
-1x male usb a module(will change it to usb c tomorrow) (for a power supply/just an charger that can delivery enough power to the female usbs and the screen)



# What went wrong
I did a male usb A when i should have done male usb C. 

# What I will add next time
Change the usb model and Maybe start designing the pcb.


# How many hours (counted with lapse)
1 hour and 49 minutes

look at picture 2.


# picture 1.
<img width="706" height="641" alt="image" src="https://github.com/user-attachments/assets/bffff330-4705-48f4-87b8-f1b7f397fe47" />


# picture 2.
<img width="1465" height="728" alt="image" src="https://github.com/user-attachments/assets/06d9d5a8-2f02-443d-b2c6-662cb6dcc3b3" />


# picture 3. (how a MAX7219 looks)

<img width="607" height="237" alt="image" src="https://github.com/user-attachments/assets/c656e76e-087b-4344-8d8a-9375f984394a" />

Now the good format!

---
title: "Echo"
author: "Mustafa Berisha"
description: "An ai assitant"
created_at: "2026-09-26"
---

# sept 26: starting the PCB design
I Finished the schematic!

It looks a little messy but it works!
<img width="1653" height="1170" alt="Schematic_Echo_2026-09-26" src="https://github.com/user-attachments/assets/0e06967f-7609-4a98-8fa0-27face0ced54" />

I will make it better looking later on : sob: 

I remade this so many times lol.

But now i also started the PCB layout and even started some of the routing!


<img width="650" height="457" alt="image" src="https://github.com/user-attachments/assets/64e3ab4a-b474-4551-b5d3-f16e46f5e9b9" />

I think the routing looks pretty good right now! But all PCBs look good at the start though lol.
**Total time spent: 2.5 hours**

