/*   
HC05 - Bluetooth AT-Command mode  
modified on 10 Feb 2019 
by Saeed Hosseini 
https://electropeak.com/learn/ 
*/ 
#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(3, 4); // RX | TX 
int flag = 0; 
boolean motion = false;
const byte motion_pin = 5;
void setup() 
{   
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 pinMode(motion_pin, INPUT); 
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 

void resolve_state()
{

  int count = 0;
  while (count < 3)
  {
    motion = digitalRead(motion_pin);
    if(motion == false){ delay(5000); return;}
    delay(1000);
    count++;
  }
  
   Serial.println("Move Detected");
   motion = false; 
   delay(10000);
 
}

void loop() 
{ 
  motion = digitalRead(motion_pin);
 if (motion == true) 
 { 
  
  resolve_state();
  
 } 
 
}  
