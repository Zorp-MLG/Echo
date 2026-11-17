# DevLog 1

## What I did

I started with putting in all the sensors I wanted, which was these:

1. MQ-135 (gas sensor, to be able to "smell" solder fumes)
2. MQ-2 (smoldering fumes and more, related to solder fumes of MQ-135, but fills the holes MQ-135 can't do)
3. DHT-22 (humidity and temperature)
4. SEEDSTUDIO R24D FMCW LITE (it looks for people and is able to see if they are sitting down, laying, or walking around and their distance and speed)
5. TSL2561T (ambient light sensor)
6. BME680 (air quality, helps with soldering fumes)
7. PMS7003 (ultrafine particle sensor, helps with soldering fumes)
8. INMP441 (microphone)
9. Xiao ESP32s3 (microcontroller)
10. Xiao ESP32s3 sense (camera)

That's pretty much all.

## What went wrong

A few of the schematic symbols didn't have PCB symbols, I had to change them.

## What I will add next time

- Fans
- TFT screens

## How many hours (counted with lapse)

3 hours, 9 minutes, 20 seconds.

Look at picture 2.

## Picture 1

<img width="603" height="527" alt="image" src="https://github.com/user-attachments/assets/1400c560-fb48-4753-9832-3b5a839f7f31" />

## Picture 2

<img width="1439" height="802" alt="image" src="https://github.com/user-attachments/assets/6ab7f950-0121-4afc-805d-0cb0ad02f1ae" />

---

# DevLog 2

## 2026-09-11

## What I did

I added:

- MAX7219 modules (a screen that has big pixels, so it looks more like pixel art)
- 3x female USB A modules (for the fans that I want the AI to be able to control)
- 3x MOSFETS (so the microcontroller/AI can control the fans)
- 1x male USB A module (will change it to USB C tomorrow) (for a power supply/just a charger that can deliver enough power to the female USBs and the screen)

## What went wrong

I did a male USB A when I should have done male USB C.

## What I will add next time

Change the USB model and maybe start designing the PCB.

## How many hours (counted with lapse)

1 hour and 49 minutes

Look at picture 2.

## Picture 1

<img width="706" height="641" alt="image" src="https://github.com/user-attachments/assets/bffff330-4705-48f4-87b8-f1b7f397fe47" />

## Picture 2

<img width="1465" height="728" alt="image" src="https://github.com/user-attachments/assets/06d9d5a8-2f02-443d-b2c6-662cb6dcc3b3" />

## Picture 3 (how a MAX7219 looks)

<img width="607" height="237" alt="image" src="https://github.com/user-attachments/assets/c656e76e-087b-4344-8d8a-9375f984394a" />

---

# DevLog 3

## Sept 26: Starting the PCB design

I finished the schematic!

It looks a little messy but it works!

<img width="1653" height="1170" alt="Schematic_Echo_2026-09-26" src="https://github.com/user-attachments/assets/0e06967f-7609-4a98-8fa0-27face0ced54" />

I will make it better looking later on :sob:

I remade this so many times lol.

But now I also started the PCB layout and even started some of the routing!

<img width="650" height="457" alt="image" src="https://github.com/user-attachments/assets/64e3ab4a-b474-4551-b5d3-f16e46f5e9b9" />

I think the routing looks pretty good right now! But all PCBs look good at the start though lol.

**Total time spent: 2.5 hours**

---

# DevLog 4

## Nov 14: Almost finished

I finished the routing!

I used autorouter, since it works fine for this :sob:

<img width="563" height="389" alt="image" src="https://github.com/user-attachments/assets/6be85f37-6e1d-42ff-8101-f1e06d8c3293" />
<img width="817" height="568" alt="image" src="https://github.com/user-attachments/assets/525902cf-af16-4c22-99cf-0ca24d917213" />

(the 3D render kinda sucks lol)

I did a different layout than the one in the devlog before, I made it slightly better!

Next devlog will be the last one probably! I will finish the repo, maybe do some art?

**Total time spent: 20 minutes**

---

# DevLog 5

## Nov 17: finished!

I fully finished the repo, sch, and pcb!

I sent in the application

<img width="1688" height="767" alt="picture of repo" src="https://github.com/user-attachments/assets/ef6b0e2a-4b74-4507-8d69-bea14c447af0" />


