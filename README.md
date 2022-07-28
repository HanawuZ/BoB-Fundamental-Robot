# BoB Robot Code
This is my first project of coding robot. Its name's "BoB". 

# Features
## Software & Hardware uses
- Arduino IDE
- ESP32
- 2 TM1638 8-Digit 7 Segment Display with 8 LED and 8 Push Switches
- MAX7219 7 Segment 8-Digit
- DHT-11 Digital Temperature and Humidity Sensor

**Image**
![image](https://user-images.githubusercontent.com/110051299/181417498-72e24c76-344a-4ac0-9d73-9c3f393806d7.png)

## Face
- Idle face
- Speaking face
- Cheering face
- Happy face
- Sleep face

## Abilities
- Connecting to WiFi
- Using FreeRTOS multitasking for BoB's facial expression
- Show local time from NTP-server via MAX7219 7-segments
- Show Current date/month/year via Serial monitor
- Say "Hello"
- Show student's ID on MAX7219 7-segments
- Say "I love you"
- Count number from 0-99
- Show Temperature and Humidity on on MAX7219 7-segments
- Change posistion between first TM1638 and second TM1638
- Sleeping
- Waking up BoB via **interrupt pin**
- Say "Sorry sir I just sleeping" after BoB has woken up
- Sending Temperature & Humidity value to IFTTT 

## Code Explaination
**Initialize Libraries & Variable**
```c++
//==================================================================================================
#include <WiFi.h>     // WiFi Library provides method for calling to connect to network.
#include "time.h"     // Library for getting date and time from NTP-server

#include <HTTPClient.h>                         // Library for HTTP GET, POST and PUT requests to a web server.
#define WebHooksKey "dlkwtXM2TQ7EMfQArqQqd6"    // Define your WebHooks Key
#define WebHooksEventName "Temp&Humid_Sheet"    // Define your WebHooks Event name

const char* ssid = "Hanawu";                    // Your WiFi name
const char* password = "hanawu547821801821";    // WiFi password
const char* ntpServer = "pool.ntp.org";         // address of the NTP Server 
const long  gmtOffset_sec = 25200;              // UTC offset
const int   daylightOffset_sec = 0;             // Daylight offset
#define delaytime 250                           // Define delay time using to delay programs

//######################## Declare pins for TM1638 ########################
#include <TM1638plus.h>         // Includes Library to control TM1638 7-segments modules
#define Brd_STB 15              // strobe = GPIO connected to strobe line of module 
#define Brd_CLK 27              // clock = GPIO connected to clock line of module 
#define Brd_DIO 4               // data = GPIO connected to data line of module 

#define Brd_STB_2 5             // strobe = GPIO connected to strobe line of module 
#define Brd_CLK_2 18            // clock = GPIO connected to clock line of module 
#define Brd_DIO_2 19            // data = GPIO connected to data line of module 
bool high_freq = true;          // default false,, If using a high freq CPU > ~100 MHZ set to true.

// Initialize variable for using 2 TM1638 modules
TM1638plus tm(Brd_STB, Brd_CLK , Brd_DIO, high_freq);         
TM1638plus tm2(Brd_STB_2, Brd_CLK_2 , Brd_DIO_2, high_freq); 

//######################## Declare pins for MAX7219 7-segment ########################
#define DIN 13                  // this pin is connected to DataIn 
#define CS 12                   // this pin is connected to LOAD 
#define CLK 14                  // this pin is connected to CLK 
#include "LedController.hpp"    // Includes Library for controlling MAX7219 7-segments
LedController lc;               // Declare variable named "lc" for controlling MAX7219 7-segments
  
//######################## Declare pins for DHT-11 ########################
#include "DHTesp.h"             // Includes Library for using DHT-11
#define DHT_pin 23              // Define pin for DHT11
DHTesp dht;                     // Declare variable named "dht" for using DHT-11

#define wakeUpBtn 0             // Define interrupt pin (using Boot button on ESP32)
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED; 
//==================================================================================================

//==================================================================================================
int Time_Obtain_status = 0;     // Integer for specify Time obtaining status
int BoB_position = 0;           // Integer for specify BoB's posistion on TM1638
int strLength;                  // String length
int sleep_status = 0;           // Integer for specify Sleeping status
int wakeup_status = 0;          // Integer for specify Wake up status
int blink_status = 0;           // Integer for specify Blinking eye status
int mouth_status = 0;           // Integer for specify Month status while it's speaking

String Sid = "b6302245";        // Student ID
String strInput;                // String for getting String from serial input
  
int count = 0;                  // Integer for store count 

int IFTTT_status = 0;           // Integer for IFTTT status

//############################ Task varibles ############################
TaskHandle_t IdleFaceTask = NULL;
TaskHandle_t SpeakingTask = NULL;
TaskHandle_t SendingToSheetTask = NULL;
TaskHandle_t IdleTextTask = NULL;

//==================================================================================================
```

**Another description will coming soon....**
