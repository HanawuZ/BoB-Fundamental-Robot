/* ############################ BoB ############################
 *  Progress 15/7/2022 15:30
 *  ทำให้ BoB ทักทาย , ดีใจ , หลับ , แสดงรหัส นศ และพูด I love you ได้
 *  --------------------------------------------------------
 *  
 *  Progress 16/7/2022 16:40
 *  ทำให้ BoB นับเลข 0-9 ได้
 *  ทำให้ BoB พูดว่า display Temp ได้
 *  ทำให้ BoB ทำงานตามคำสั่งจาก Serial input ได้
 *  ย้ายข้อความคำพูดไปแสดงใน MAX7219 แทน
 *  --------------------------------------------------------
 *  
 *  Progress 18/7/2022 23:00
 *  ทำให้ BoB แสดงอุณหภูมิและความชื้นได้
 *  ทำให้ BoB นับเลข 0-99 ได้
 *  ทำให้ BoB พูดว่า "Sorry sir I just sleeping" ได้เมื่อตื่น
 *  --------------------------------------------------------
 *  
 *  Progress 19/7/2022 21:30
 *  Objective:  
 *  /- เมื่อกดครั้งแรก ให้ BoB แสดงอุณหภูมิและความชื้นค้างไว้ เมื่อกดอีกรอบให้ BoB หยุดแสดง
 *  /- เมื่อรับคำสั่ง ShowTempAndHumid จาก Serial input ให้แสดง แสดงอุณหภูมิและความชื้นค้างไว้ เมื่อกดอีกรอบให้ BoB หยุดแสดง
 *  ?- ให้ BoB นับเลข ให้มีรูปแบบการนับจาก Serial input เช่น "Count num from 10-20 by 2"
 *  ?- ถ้า BoB อยู่เฉยๆ นานเกินไป ให้มันหลับ
 *  (Partial)- ปรับปรุง code ให้สั้นลง และดูง่ายขึ้น
 *  
 *  / เมื่อรับคำสั่ง "convert celcius to farenheit" หรือ "convert C to F" 
 *  - ให้ BoB พูดว่า convert celcius to farenheit แล้วแสดงอุณหภูมิในหน่วย F แทน
 *  
 *  / เมื่อรับคำสั่ง "convert celcius to kelvin" หรือ "convert C to K" 
 *  - ให้ BoB พูดว่า convert celcius to kelvin แล้วแสดงอุณหภูมิในหน่วย K แทน
 *  
 *  --------------------------------------------------------
 *  Progress 20/7/2022 23:26
 *  Objective: 
 *  o? ปรับปรุง code ให้สั้นลงและดูง่ายขึ้น เพื่อลดการใช้พื้นที่หน่วยความจำ 
 *  o/ กำหนดปุ่มเพื่อกดรีเซ็ตการทำงานของ BoB
 *  
 *  o/ ให้ BoB แสดงเวลาปัจจุบันโดย
 *  - Serial input ว่า "BoB show time" หรือ "Show time" 
 *  
 *  o?(Partial) ให้ BoB พูดว่า "I can't understand" , "Hey I don't understand" เมื่อเราใส่คำสั่งที่ไม่ได้เขียนในโค๊ดใน Serial input
 *  
 *  oX Serial input ว่า "Enable calculation" ให้ BoB เป็นเครื่องคิดเลข 
 *    จากนั่นให้ BoB คำนวนตามคำสั่งที่เราใส่ เช่น 2+6 ให้ BoB แสดงว่า 2+6 = 8 เป็นต้น
 *  
 *  --------------------------------------------------------
 *  Progress 23/7/2022 22:55
 *  Objective:
 *  o/ เพิ่ม Tm1638 อีก 1 ตัว
 *  o/ ทำให้ BoB สลับไปปรากฏใน Tm1638 ได้ผ่านการกดปุ่ม
 *  o/ ทำให้ BoB เชื่อมต่อ Wifi ผ่านการกดปุ่มบน Tm1638 ตัวที่ 2 ได้
 *  o/ ทำให้ BoB หยุดเชื่อมต่อ Wifi ได้ผ่าน serial input
 *  
 *  o/ ให้ BoB แสดงว่า "Failed to obtain time" ถ้าแสดงเวลาไม่ผ่าน
 *  o? ให้ BoB แสดง วดป เช่น 01.07.2022
 *  o/ ใช้ เซ็นเซอร์วัดแสง วัดค่าแสงได้
 *  o? ปรับปรุง code ให้สั้นลงและดูง่ายขึ้น เพื่อลดการใช้พื้นที่หน่วยความจำ
 *  
 *  --------------------------------------------------------
 *  Progress 24/7/2022 13:27
 *  Objective:
 *  o/ วัดค่าอุณหภูมิและความชื้น แล้วบันทึกลงใน speadsheet ผ่าน https://ifttt.com/
 *  o/ เพิ่ม Task สำหรับการส่งค่าอุณหภูมิและความชื้น แล้วบันทึกลงใน speadsheet
 *  o? เขียนโค๊ด python เพื่อพยากรณ์อุณหภูมิในช่วงเวลาถัดๆไป โดยใช้ linear regression
 *  
 *  --------------------------------------------------------
 *  Progress 26/7/2022 23:00
 *  Objectives:
 *  o/ ปรับโค๊ด ให้สามารถกดปุ่มเพื่อยกเลิกการส่งค่าอุณหภูมิเข้าไปใน speadsheet ผ่าน IFTTT ได้
 *  o/ เขียนโค๊ด python เพื่อพยากรณ์อุณหภูมิในช่วงเวลาถัดๆไป โดยใช้ linear regression
 *  o? ปรับปรุง code ให้สั้นลงและดูง่ายขึ้น เพื่อลดการใช้พื้นที่หน่วยความจำ
*/  
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
//############################ The interrupt handling function ############################
void IRAM_ATTR handleInterrupt() { 
    portENTER_CRITICAL_ISR(&mux); 
    clear7Seg_max7219();
    sleep_status = 0; mouth_status = 1;
    wakeup_status = 1;
    portEXIT_CRITICAL_ISR(&mux); 
    vTaskResume(IdleFaceTask);
} 
//==================================================================================================

void WifiSetup(){
    delay(50);
    Serial.printf("Connecting to %s ", ssid);   // Serial monitor shows "Connecting to [Wifi name]"
    WiFi.begin(ssid, password);                 
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" CONNECTED");
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer); // Get date and time from an NTP server.
} 


char Time[9];   // Time = "12:45:31"

char day[3];
char month[12]; // month = "July"  
char year[5];   // year = "2022"
    
char date[12];  // date = "5/2/2022"

/////////////////////// Time ///////////////////////
void getDate(){
    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)) {
        Serial.println("Failed to obtain date");
        return;
    }
    else {
        int month_num;
        strftime(day, sizeof(day), "%d", &timeinfo);
        strftime(month, sizeof(month), "%B", &timeinfo);
        strftime(year, sizeof(year), "%Y", &timeinfo);
        date[11] = '\0';
        
        if (strcmp(month , "January") == 0) month_num = 1;
        else if (strcmp(month , "Febuary") == 0) month_num = 2;
        else if (strcmp(month , "March") == 0) month_num = 3;
        else if (strcmp(month , "April") == 0) month_num = 4;
        else if (strcmp(month , "May") == 0) month_num = 5;
        else if (strcmp(month , "June") == 0) month_num = 6;
        else if (strcmp(month , "July") == 0) month_num = 7;
        else if (strcmp(month , "August") == 0) month_num = 8;
        else if (strcmp(month , "September") == 0) month_num = 9;
        else if (strcmp(month , "October") == 0) month_num = 10;
        else if (strcmp(month , "November") == 0) month_num = 11;
        else if (strcmp(month , "December") == 0) month_num = 12;

        // Setting date
        sprintf(date, "%s/%d/%s" , day , month_num ,year);
        Serial.println(date);
        Time_Obtain_status = 1;
    }
}

void getLocalTime() {
    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)) {
        Serial.println("Failed to obtain time");
        return;
    }
    else {
        Time_Obtain_status = 1;
        // Setting Time
        strftime(Time, sizeof(Time), "%H:%M:%S", &timeinfo);
        Serial.println(Time);
    }
}

//####################################################
void sendTempAndHumidToSheet(){
    float humidity = dht.getHumidity(); 
    float temperature = dht.getTemperature(); 
    float temp_F = 1.8*temperature + 32;
    String serverName = "http://maker.ifttt.com/trigger/" + String(WebHooksEventName) + "/with/key/" + String(WebHooksKey); 
    String httpRequestData = "value1=" + String(temperature) + "&value2=" + String(temp_F) + "&value3=" + String(humidity); 
    Serial.println(); 
    Serial.println("Server Name >> " + serverName); 
    Serial.println("json httpRequestData >> " + httpRequestData); 
    if (WiFi.status() == WL_CONNECTED) { 
        HTTPClient http; 
        http.begin(serverName); 
        http.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
        int httpResponseCode = http.POST(httpRequestData); 
        Serial.print("HTTP Response code: "); 
        Serial.println(httpResponseCode); 
        http.end(); 
        if (httpResponseCode == 200) Serial.println(" --> Successfully sent"); 
        else Serial.println(" --> Failed!"); 
    } 
    else { Serial.println("WiFi Disconnected"); } 
    int WaitTime = 60; 
    Serial.print(" >> Wait for next time --> "); 
    for (int i = WaitTime; i >= 0; i -= 5) { 
        Serial.print(","); 
        Serial.print(i); 
        delay(5000); 
    }
}

//################ Function show time ################
void showTime(){ 
    getLocalTime();
    vTaskSuspend(IdleFaceTask);        // Stop showing idle face 
    vTaskSuspend(IdleTextTask); // Stop saying "...."
    if (Time_Obtain_status == 1){
        while(1) {
            getLocalTime();     // Obtain local time : Time = "12:45:31"
            delay(10);
            lc.setChar(0,7,Time[0],false); lc.setChar(0,6,Time[1],true); 
            lc.setChar(0,5,Time[3],false); lc.setChar(0,4,Time[4],true);
            lc.setChar(0,3,Time[6],false); lc.setChar(0,2,Time[7],false);
            String textCmd;
            textCmd = Serial.readString();
            if(textCmd == "Stop show time") {
                clear7Seg_max7219();
                Time_Obtain_status = 0;
                break; 
            }
        }
    }
    else {
        startSpeaking();
        sayFailedtoObtainTime();    // Say "Failed to Obtain Time"
    }
    stopSpeaking();
}


void showDate(){
   getDate();
   if (Time_Obtain_status == 1){
        while(1) {
            delay(10);
            String textCmd;
            textCmd = Serial.readString();
            if(textCmd == "Stop show date" || textCmd == "Stop" || textCmd == "stop") {
                clear7Seg_max7219();
                Time_Obtain_status = 0;
                break; 
            }
        }
    }
    else {
        startSpeaking(); 
        sayFailedtoObtainTime();
    }
    stopSpeaking();
}

/////////////////////// Clear 7-Segments Function ///////////////////////
void clear7Seg_Tm1(){
    for(int i = 0 ; i < 8 ; i++) tm.display7Seg(i , 0b00000000);
}
void clear7Seg_Tm2(){
    for(int i = 0 ; i < 8 ; i++) tm2.display7Seg(i , 0b00000000);
}

void clear7Seg(){
    for(int i = 4 ; i < 8 ; i++) tm.display7Seg(i , 0b00000000);
}

void clear7Seg_max7219(){
    for(int i = 7 ; i > -1 ; i--) lc.setRow(0, i ,B00000000);
}
/////////////////////////////////////////////////////////////////////
void showHappyFace(){
    mouth_status = 1;
    if (BoB_position == 0) {
        //                 0btgfedcba
        clear7Seg_Tm2();
        tm.display7Seg(0 , 0b00100011); // left eye
        tm.display7Seg(2 , 0b00100011); // right eye
    }
    else if (BoB_position == 1){
        clear7Seg_Tm1();
        tm2.display7Seg(0 , 0b00100011); // left eye
        tm2.display7Seg(2 , 0b00100011); // right eye
    }
}

void showCheeringFace(){
    mouth_status = 1;
    if (BoB_position == 0) {
        clear7Seg_Tm2();
        tm.display7Seg(0 , 0b00100011); // left eye
        tm.display7Seg(2 , 0b00100011); // right eye
    }
    else if (BoB_position == 1){
        clear7Seg_Tm1();
        tm2.display7Seg(0 , 0b00100011); // left eye
        tm2.display7Seg(2 , 0b00100011); // right eye
    }
    
}

void showIdleFace(){
    if (BoB_position == 0){
      // eye open
        clear7Seg_Tm2(); delay(50);
        if (blink_status %2 == 0) {
            blink_status++;
            tm.display7Seg(0 , 0b01100011);
            tm.display7Seg(2 , 0b01100011);
            delay(delaytime*4);
        }
        
        // eye close
        else {
            blink_status--;
            //                 0btgfedcba
            tm.display7Seg(0 , 0b01000000);
            tm.display7Seg(2 , 0b01000000);
            
        }
    }
    else if (BoB_position == 1) {
      // eye open
        clear7Seg_Tm1(); delay(50);
        if (blink_status %2 == 0) {
            blink_status++;
            tm2.display7Seg(0 , 0b01100011);
            tm2.display7Seg(2 , 0b01100011);
            delay(delaytime*4);
        }
        
        // eye close
        else {
            blink_status--;
            //                  0btgfedcba
            tm2.display7Seg(0 , 0b01000000);
            tm2.display7Seg(2 , 0b01000000);
        }
    }  
    delay(100);
    tm.display7Seg(1 , 0b00001000);   // Idle mouth
}


void showSpeaking(){
    if (BoB_position == 0) {
        clear7Seg_Tm2();
        // mouth open
        if (mouth_status %2 == 0) {
            mouth_status++;
            tm.display7Seg(1 , 0b01011100);
        }
        // mouth close
        else {
            mouth_status--;
            //                 0btgfedcba
            tm.display7Seg(1 , 0b00001000);
        }
    }
    else if (BoB_position == 1) {
        clear7Seg_Tm1();
        // mouth open
        if (mouth_status %2 == 0) {
            mouth_status++;
            tm2.display7Seg(1 , 0b01011100);
        }
        // mouth close
        else {
            mouth_status--;
            //                 0btgfedcba
            tm2.display7Seg(1 , 0b00001000);
        }
    }
    delay(delaytime-50);
}

void showSleepFace(){
    if (BoB_position == 0){
        clear7Seg_Tm2();
        tm.display7Seg(0 , 0b01000000);
        tm.display7Seg(1 , 0b00001000);
        tm.display7Seg(2 , 0b01000000);
    }
    else if (BoB_position == 1){
        clear7Seg_Tm1();
        tm2.display7Seg(0 , 0b01000000);
        tm2.display7Seg(1 , 0b00001000);
        tm2.display7Seg(2 , 0b01000000);
    }
}

void returnIdleFace(){
    if (BoB_position == 0){
        clear7Seg_Tm2();
        tm.display7Seg(0 , 0b01100011);
        tm.display7Seg(1 , 0b00001000);
        tm.display7Seg(2 , 0b01100011);
    }
    else if (BoB_position == 1){
        clear7Seg_Tm1();
        tm2.display7Seg(0 , 0b01100011);
        tm2.display7Seg(1 , 0b00001000);
        tm2.display7Seg(2 , 0b01100011);
    }
     
}
//////////////////////////////////////////////////
void saySendingToIFTTT(){
    String text[] = {"Sending" , "to" , "IFTTT"};
    delay(delaytime); 
    for (int i = 0 ; i < 3 ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
            lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }
}

void sayStopSendingToIFTTT(){
    String text[] = {"Stop" , "Sending" , "to" , "IFTTT"};
    delay(delaytime); 
    for (int i = 0 ; i < 4 ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
            lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }
}

void sayHello(){
    /* Bob will say "Hi Bob Here"*/
    String text[] = {"Hi" , "Bob" , "Here"};
    delay(delaytime); 
    for (int i = 0 ; i < 3 ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
            lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }
}
void sayFailedtoObtainTime(){
    String text[] = {"Failed" ,"to" , "Obtain" , "tinne"};
    delay(delaytime); 
    for (int i = 0 ; i < 4 ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
            lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }
}
void saySetupWIFI(){
    String text[] = {"Setup" , "UUifi"};
    delay(delaytime); 
    for (int i = 0 ; i < 2 ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
            lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }
      
}
void sayReset(){
    String text[] = {"begin" , "reset"};
    delay(delaytime); 
    for (int i = 0 ; i < 2 ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
            lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }
}
void sayIdleText(){
    for (int i = 7 ; i > 3 ; i--){
        delay(delaytime);
        lc.setChar(0, i , '.' , false);
    }
    delay(delaytime);
    clear7Seg_max7219();
   
}

void saySleepText(){
    // Say "ZZZZ"
    for (int i = 7 ; i > 3 ; i--) {
        lc.setChar(0 , i , 'Z' , false); delay(delaytime+100);
    }
     
    // Clear "ZZZZ"
    for (int i = 7 ; i > 3 ; i--) {
        lc.setRow(0, i ,B00000000); delay(delaytime+100);
    }
}

void sayWakeUp(){
    String text[] = {"Sorry" , "Sir" , "I" , "Just" , "sleeping"};
    delay(delaytime); 
    for (int i = 0 ; i < 5 ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
            lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }
}

void sayYesSir(){
    String text[] = {"Yes" , "Sir" , "Can" , "I" , "Help" , "You"};
    delay(delaytime); 
    for (int i = 0 ; i < 6 ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
            lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }
}
void sayILoveYou(){
    String text[] = {"I" , "love" , "You"};
    delay(delaytime); 
    for (int i = 0 ; i < 3 ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
            lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }
}

void sayCountNum(){
    String text[] = {"Let" , "count" , "Integer"};
    delay(delaytime); 
    for (int i = 0 ; i < 3 ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
            lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }
}

void sayShowId(){
    String text[] = {"Show" , "ID"};
    delay(delaytime); 
    for (int i = 0 ; i < 2 ; i++) {
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++){
            tm.displayASCII(4+j , text[i][j]); 
        }
        delay(delaytime);
        clear7Seg();
        delay(delaytime);
    }
}

void sayDisplayTemp(){
    String text[] = {"enable" , "DHT11"};
    delay(delaytime); 
    for (int i = 0 ; i < 2 ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
            lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }
}

void sayStopDisplayTemp(){
    String text[] = {"Stop" , "DHT11"};
    delay(delaytime); 
    for (int i = 0 ; i < 2 ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
            lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }
}

void sayConvert(char temp_unit){
    if (temp_unit = 'F') {
        String text[] = {"Convert" , "Celcius" , "to" , "Fahrenheit"};
        delay(delaytime); 
        for (int i = 0 ; i < 4 ; i++){
            strLength = text[i].length();
            for (int j = 0 ; j < strLength ; j++) {
                lc.setChar(0,7-j,text[i][j],false);
            }
            delay(delaytime);
            clear7Seg_max7219();
            delay(delaytime);
        }
    }

    if (temp_unit = 'C') {
        String text[] = {"Convert" , "Fahrenheit" , "to" , "Celcius"};
        delay(delaytime); 
        for (int i = 0 ; i < 4 ; i++){
            strLength = text[i].length();
            for (int j = 0 ; j < strLength ; j++) {
                lc.setChar(0,7-j,text[i][j],false);
            }
            delay(delaytime);
            clear7Seg_max7219();
            delay(delaytime);
        }
    }
}

void sayDontUnderstand(){
    String text[] = {"I" , "dont" , "get it"}; 
    delay(delaytime-100); 
    for (int i = 0 ; i < sizeof(text)/sizeof(text[0]) ; i++){
        strLength = text[i].length();
        for (int j = 0 ; j < strLength ; j++) {
             lc.setChar(0,7-j,text[i][j],false);
        }
        delay(delaytime);
        clear7Seg_max7219();
        delay(delaytime);
    }  
}

////////////////////////////////////////////
void greetingCommand(){
    startSpeaking();
    showHappyFace();
    sayYesSir();
    stopSpeaking();
}

void showStudentID(){
    startSpeaking();
    sayShowId();                // Say "Show ID"
    vTaskSuspend(SpeakingTask);        // Stop speaking
    returnIdleFace();           // Return idle face
    vTaskResume(IdleFaceTask);         // Continue showing idle face     
    for (int i = 0 ; i < 8 ; i++) {
        delay(delaytime); lc.setChar(0, 7-i , Sid[i] , false);
    }

    for (int i = 0 ; i < 8 ; i++) {
        delay(delaytime); lc.setRow(0, 7-i ,B00000000);
    }
    vTaskResume(IdleTextTask);  // saying "...."
}

////////////////////////////////////////////

void countNum(int count_status){
/* ฟังก์ชันให้ BoB นับเลข 
 * - ให้ BoB นับเลข ให้มีรูปแบบการนับจาก Serial input เช่น "Count num from 10-20 by 2"
 */
    clear7Seg_max7219(); delay(delaytime);
    startSpeaking();
    sayCountNum();              // Say "Let count Integer"
    vTaskSuspend(SpeakingTask);        // Stop speaking
    returnIdleFace();           // Show idle face
    vTaskResume(IdleFaceTask);         // Continue showing idle face 
    String strCount;
    if (count_status == 0) {
        while (count < 10) {
            strCount = String(count);
            lc.setChar(0 , 7 , strCount[0] ,false); delay(delaytime);
            clear7Seg_max7219();
            count++;
        }
        while (count < 100) {
            strCount = String(count);
            lc.setChar(0 , 7 , strCount[0] ,false); 
            lc.setChar(0 , 6 , strCount[1] ,false);
            delay(delaytime);
            clear7Seg_max7219();
            count++;
        }
    }

    else {
    }
    vTaskResume(IdleTextTask); // Continue saying "...."
}

////////////////////////////////////////////
void getTemp_and_Humid(char temp_unit){
    if (temp_unit == 'C'){
        String temp = String(dht.getTemperature());  
        String humid = String(dht.getHumidity());   
        lc.setChar(0 , 7 , temp[0] , false); lc.setChar(0 , 6 , temp[1] , true); 
        lc.setChar(0 , 5 , temp[3] , false); lc.setChar(0 , 4 , 'C' , false);
        
        lc.setChar(0 , 3 , humid[0] , false); lc.setChar(0 , 2 , humid[1] , true); 
        lc.setChar(0 , 1 , humid[3] , false); lc.setChar(0 , 0 , 'H' , false);
        Serial.print("Temperature: "); Serial.print(temp); Serial.println(" C");
        Serial.print("Humidity: "); Serial.println(humid);
    }

    else if (temp_unit == 'F'){
        float temp_F = 1.8*(dht.getTemperature()) + 32;
        String Str_temp_F = String(temp_F);
        String humid = String(dht.getHumidity()); 
        lc.setChar(0 , 7 , Str_temp_F[0] , false); lc.setChar(0 , 6 , Str_temp_F[1] , true); 
        lc.setChar(0 , 5 , Str_temp_F[3] , false); lc.setChar(0 , 4 , 'F' , false);

        lc.setChar(0 , 3 , humid[0] , false); lc.setChar(0 , 2 , humid[1] , true); 
        lc.setChar(0 , 1 , humid[3] , false); lc.setChar(0 , 0 , 'H' , false);
        Serial.print("Temperature: "); Serial.print(Str_temp_F); Serial.println(" F");
        Serial.print("Humidity: "); Serial.println(humid);
    }
    Serial.println();
}

char temp_unit = 'C';

void showTempAndHumid(){
    temp_unit = 'C';
    startSpeaking();
    sayDisplayTemp();           // Say "Enable DHT-11"
    vTaskSuspend(SpeakingTask);        // Stop speaking
    returnIdleFace();
    vTaskResume(IdleFaceTask);         // Continue idle face
    while (1) {
        String textCmd;
        textCmd = Serial.readString();  // String for Serial input command
        int SwInput = tm.readButtons(); 

        //------------ Statements for stop showing Temperature & Humidity ------------
        if (SwInput == 0x10 || textCmd == "Stop show temp & humid" 
        || textCmd == "Stop show temperature and humidity") { 
            clear7Seg_max7219();
            vTaskSuspend(IdleFaceTask);        // Stop showing idle face
            vTaskResume(SpeakingTask);         // Start speaking   
            sayStopDisplayTemp();       // Say "Stop display temp"
            vTaskSuspend(SpeakingTask);        // Stop speaking
            vTaskResume(IdleFaceTask);         // Continue idle face
            vTaskResume(IdleTextTask);  // saying "...."
            break; 
        }

        //------------ Statements for convert celcius to farenheit ------------
        else if (textCmd == "convert celcius to farenheit" || textCmd == "convert C to F" ){ 
            clear7Seg_max7219();        
            vTaskSuspend(IdleFaceTask);        // Stop showing idle face
            vTaskResume(SpeakingTask);         // Start speaking   
            String text[] = {"Convert" , "Celcius" , "to" , "Fahrenheit"};
            delay(delaytime); 
            for (int i = 0 ; i < 4 ; i++){
                strLength = text[i].length();
                for (int j = 0 ; j < strLength ; j++) {
                    lc.setChar(0,7-j,text[i][j],false);
                }
                delay(delaytime);
                clear7Seg_max7219();
                delay(delaytime);
            }
            
            temp_unit = 'F';
            vTaskSuspend(SpeakingTask);        // Stop speaking
            vTaskResume(IdleFaceTask);         // Continue idle face
            delay(delaytime);
        }

        //------------ Statements for convert fahrenheit to celcius ------------
        else if (textCmd == "convert fahrenheit to celcius" || textCmd == "convert F to C" ){
            clear7Seg_max7219();
            vTaskSuspend(IdleFaceTask);        // Stop showing idle face
            vTaskResume(SpeakingTask);         // Start speaking
            String text[] = {"Convert" , "Fahrenheit" , "to" , "Celcius"};
            delay(delaytime); 
            for (int i = 0 ; i < 4 ; i++){
                strLength = text[i].length();
                for (int j = 0 ; j < strLength ; j++) {
                    lc.setChar(0,7-j,text[i][j],false);
                }
                delay(delaytime);
                clear7Seg_max7219();
                delay(delaytime);
            }
            temp_unit = 'C'; 
            vTaskSuspend(SpeakingTask);        // Stop speaking
            vTaskResume(IdleFaceTask);         // Continue idle face
            delay(delaytime);
        }
        getTemp_and_Humid(temp_unit);   // Show Temperature & Humidity depend on temp's unit(C or F)
        delay(50);
     }
}
///////////////////////////////////////////////////////////////////
void startSpeaking(){
    returnIdleFace();           // Show idle face
    vTaskSuspend(IdleFaceTask);        // Stop showing idle face 
    vTaskSuspend(IdleTextTask); // Stop saying "...."
    vTaskResume(SpeakingTask);         // Start speaking   
}

void stopSpeaking(){
    returnIdleFace();           // Show idle face
    vTaskResume(IdleFaceTask);         // Continue showing idle face 
    vTaskSuspend(SpeakingTask);        // Stop speaking
    vTaskResume(IdleTextTask);  // Continue saying "...."
}
///////////////////////////////////////////////////////////////////

void setup() {
    Serial.begin(115200); 
    delay(50);
    
    // ################## SETTING INTERRUPT PIN ##################
    attachInterrupt(digitalPinToInterrupt(wakeUpBtn), handleInterrupt, FALLING); 
    delay(50);
    
    // ################## SETTING MULTITASK ##################
    xTaskCreatePinnedToCore(func_IdleFaceTask, "IdleFaceTask", 2048 , NULL , tskIDLE_PRIORITY , &IdleFaceTask ,0);
    xTaskCreatePinnedToCore(func_SpeakingTask, "SpeakingTask", 2048 , NULL , tskIDLE_PRIORITY , &SpeakingTask ,0);
    xTaskCreatePinnedToCore(func_SendingToSheetTask, "SendingToSheetTask", 2048 , NULL , tskIDLE_PRIORITY , &SendingToSheetTask ,1);
    xTaskCreatePinnedToCore(func_IdleTextTask, "IdleTextTask", 2048 , NULL , tskIDLE_PRIORITY , &IdleTextTask ,0);

    vTaskSuspend(IdleFaceTask); vTaskSuspend(SpeakingTask); vTaskSuspend(SendingToSheetTask); vTaskSuspend(IdleTextTask);
    delay(50);

    // ################## Set up LedController(Max7219) ##################
    lc = LedController(DIN, CLK, CS, 1);
    lc.activateAllSegments();
    lc.setIntensity(8);
    lc.clearMatrix();

    // ################## Set up TM1638 ##################
    tm.displayBegin();  tm2.displayBegin();
    delay(50); 

    // ################## Set up DHT11 ##################
    dht.setup(DHT_pin, DHTesp::DHT11);  
    delay(50); 
    
    startSpeaking();
    sayHello();                 // BoB say "Hello"
    delay(delaytime);     
    //saySetupWIFI();             // Say "Setup WIFI"
    stopSpeaking(); 
    //WifiSetup();                // #! Don't change statement's location
    
    // ################## Show happy face ##################
    greetingCommand();
    returnIdleFace();
    delay(100); 
}

void loop() {
    int SwInput = tm.readButtons(); // ประกาศตัวแปร int รับค่าจากการกดปุ่มบน TM1638
    int SwInput_2 = tm2.readButtons();
    delay(delaytime);
    if (Serial.available() > 0) {
        strInput = Serial.readString(); // รับค่า String จาก Serial input
        if (strInput == "Show temperature and humidity" || strInput == "Show temp and humid" 
        || strInput == "Show temp & humid"){
            showTempAndHumid();
        }

        else if (strInput == "Hello" || strInput == "Hey" || strInput == "Hey BoB" || strInput == "Yolo" ||
        strInput == "Hi") {
            greetingCommand();
        }

        else if (strInput == "BoB please show ID" || strInput == "Show studentID" || strInput == "show ID") {
            clear7Seg_max7219(); delay(delaytime);
            showStudentID();
        }
        
        else if (strInput == "BoB please count num" || strInput == "BoB count number") countNum(0);   
        
        else if (strInput == "Show time" || strInput == "BoB show time" || strInput == "time now" ||
        strInput == "show time BoB" || strInput == "please show time" || strInput == "show time") {
            showTime();
        }

        else if (strInput == "Get date" || strInput == "show date" || strInput == "get date now"){
            getDate();
        }
        
        //  ################## Let BoB say don't understand  ##################
        else {
            startSpeaking();
            sayDontUnderstand();        // Say "I dont get it"
            stopSpeaking();
        }
    }
    
    // ################## Show happy face & say hello ##################
    if (SwInput == 0x01) {
        clear7Seg_max7219(); delay(delaytime);
        startSpeaking();        // Start speaking 
        showHappyFace();        // Show happy face
        sayYesSir();            // Say "Yes sir can I help you"
        stopSpeaking();         // Stop speaking, let BoB show idle face
    }

    // ################## Let bob show student id ##################
    else if (SwInput == 0x02) {
        clear7Seg_max7219(); delay(delaytime);
        showStudentID();
    }

    // ################## Show cheering face ##################
    else if (SwInput == 0x04) {
        clear7Seg_max7219(); delay(delaytime);
        startSpeaking();
        showCheeringFace();         
        sayILoveYou();
        stopSpeaking();
    }

    // ################## Let bob count number ##################
    else if (SwInput == 0x08) {
        returnIdleFace();           // Show idle face 
        countNum(0);    
    }

    // ################## Let bob show temperature & humidity ##################
    else if (SwInput == 0x10) showTempAndHumid(); 

    // ################## Let bob read BMP280 ##################
    else if (SwInput == 0x20) {
    } 

    // ################## Swap BoB position to first TM1638 ##################
    else if (SwInput == 0x40) BoB_position = 0;
    
    // ################## Button for letting bob sleep ##################
    else if (SwInput == 0x80) {
        sleep_status = 1;
        vTaskSuspend(IdleTextTask); // Stop saying "...."
        vTaskSuspend(IdleFaceTask);        // Stop showing idle face 
    }

    // ################## BoB sleeping ##################
    while(sleep_status) {
        clear7Seg_max7219(); delay(50);
        showSleepFace();
        saySleepText();
    }

    // ################## Let bob wake up ##################
    if(wakeup_status) {
        startSpeaking(); 
        sayWakeUp();                // Say "Wake up"
        wakeup_status = 0;          
        stopSpeaking();
    }
    // =================================================================================
    // ################### BUTTOM FROM 2nd TM1638 ################## 
    else if (SwInput_2 == 0x02){
        IFTTT_status++;
        if (IFTTT_status%2 != 0) {
            startSpeaking();
            saySendingToIFTTT();        // Say "Sending to IFTTT"
            returnIdleFace();           // Show idle face
            vTaskResume(IdleFaceTask);         // Continue showing idle face 
            vTaskSuspend(SpeakingTask);        // Stop speaking
            vTaskResume(SendingToSheetTask);         // Start Task for sending to IFTTT
        }                           
        else {
            clear7Seg_max7219();
            startSpeaking();
            sayStopSendingToIFTTT();    // Say "Stop Sending To IFTTT"
            stopSpeaking();
            vTaskSuspend(SendingToSheetTask);        // Stop Task for sending to IFTTT
        }
    }
    
    else if (SwInput_2 == 0x80) BoB_position = 1;
}

// Idle face Task
void func_IdleFaceTask(void *param){
    while(1) showIdleFace(); 
}

// Speaking Task
void func_SpeakingTask(void *param){
    while(1) showSpeaking(); 
}

// ################ IFTTT Task ################
void func_SendingToSheetTask(void *param){
    while(1){
        getTemp_and_Humid(temp_unit);     // Show Temperature & Humidity on MAX7219
        sendTempAndHumidToSheet();        // Send Temperature & Humidity to google sheet
    }
}

// Say Idle text Task
void func_IdleTextTask(void *param){
    while(1) sayIdleText(); 
}
