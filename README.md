# Intefacing of PushButton with ESP8266 Node MCU


## Content
- 1.[Overview](#overview)
- 2.[Components Required](#components-reaquired)
- 3.[Project Flow](#project-flow)
- 4.[Circuit Diagram](#circuit-diagram)
- 5.[Summary](#summary)
  





## Overview
- This project is based on ESP8266 Node MCU

## Components Reaquired 
- ESP8266 Node MCU
- PushButton
- USB cable
- Jumper Wire
- Bread Board

 ## Project Flow
  ### 1.Hardware Setup
  #### i.Gather Components
 - ESP8266 NodeMCU
 - PushButton
 - Bread board & Jumper wire
 - USB cable

  #### ii.Hardware connectins
 - VCC of PushButton to 3.3V of NodeMCU
 - Gnd of PushButton to GND of NodeMCU
 - Connect Data pins of PushButton to digital pins on NodeMCU
 - Connect the NodeMCU to computer thruough usb cable

 ### 2.Software Setup
  #### i. install Required ide
 - Install the VS code 
 - Install the platfomIO extention
 - Creat the new project
 - Select the ESP8266 NodeMCU board
 - Install  required libraries



     
   #### ii.Thingspeak  Setup
 - Open Thingspeak
 - Creat new channel
 - Select  no of fields required
 - Add api key and and chnnel no in source code

  #### iii.Wifi Setup
 - Turn on the Wifi
 - Add SSID and passward in source code







 #### iv.Debug & compile the code
   - Dump the code in Node MCU
   - open the seril monitor to see the result
   - wait untill the the nodeMCU connects to the wifi

#### v.OUTPUT
- See output on ThingSpeak channel feild
     
## Circuit Diagram
![Circuit Diagram](./



 ## Summary
 To interface a PushButton with the ESP8266 NodeMCU and upload data to ThingSpeak, start by connecting the sensor VCC to the NodeMCU 3.3V pin, GND to GND, and Data to a digital pin Install the ESP8266WiFi and sensor libraries in the Platform IO IDE. Write or upload code to read data from the sensor, connect to Wi-Fi, and send data to ThingSpeak using its API. Finally, compile and upload the code to the NodeMCU and monitor the uploaded data on the ThingSpeak channel.
