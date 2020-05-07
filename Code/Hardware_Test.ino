/*

Tools/Boards: ESP32 Dev Module
Install the Ucglib SSD1331 library 
  
*/
#include <SPI.h>
#include "Ucglib.h"

#define Buzzer 12
#define Button_0 15
#define Button_1 4
#define Button_2 14

int BTN_0 = 0;
int BTN_1 = 0;
int BTN_2 = 0;

Ucglib_SSD1331_18x96x64_UNIVISION_SWSPI ucg(/*sclk=*/ 18, /*data=*/ 23, /*cd=*/ 19, /*cs=*/ 5, /*reset=*/ 2);

void setup(void)
{
  Serial.begin(9600);
  delay(1000);
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.clearScreen();

  pinMode(Buzzer,   OUTPUT);
  pinMode(Button_0,   INPUT);
  pinMode(Button_1,   INPUT);
  pinMode(Button_2,   INPUT);
}

void loop(void)
{
  BTN_0 = digitalRead(Button_0); 
  BTN_1 = digitalRead(Button_1); 
  BTN_2 = digitalRead(Button_2);  

  
  ucg.setRotate180();
  ucg.setFont(ucg_font_ncenR12_tr);
  //ucg.setColor(255, 255, 255);  //white text
  ucg.setColor(0, 255, 0);    //Green Text
  //ucg.setColor(1, 255, 0,0);    //no idea 
  
  ucg.setPrintPos(0,25);
  ucg.print("Button test");
  delay(50); 

  while (BTN_0 == HIGH) 
  {
   Serial.println("BTN_0 is high"); 
   Buzz();
   ucg.setColor(255, 255, 255);  //white text
   ucg.setPrintPos(0,65);
   ucg.print("*");
   delay(50); 
   BTN_0 = 0; 
  }
 

  while (BTN_1 == HIGH) 
  {
   Serial.println("BTN_1 is high"); 
   Buzz();
   ucg.setColor(255, 255, 255);  //white text
   ucg.setPrintPos(30,65);
   ucg.print("*");
   delay(50);
   BTN_1 = 0; 
  }

  while (BTN_2 == HIGH) 
  {
   Serial.println("BTN_2 is high"); 
   Buzz();
   ucg.setColor(255, 255, 255);  //white text
   ucg.setPrintPos(90,65);
   ucg.print("*");
   delay(50);
   BTN_2 = 0;  
  }

   
   Serial.println("Waiting"); 
   ucg.setColor(0, 0, 0);  //black text
   ucg.setPrintPos(0,65);
   ucg.print("*");
   
   ucg.setPrintPos(30,65);
   ucg.print("*");
   
   ucg.setPrintPos(90,65);
   ucg.print("*");   
}

void Buzz()
{ 
 digitalWrite(Buzzer, HIGH);
 delay(150);
 digitalWrite(Buzzer, LOW);
}
