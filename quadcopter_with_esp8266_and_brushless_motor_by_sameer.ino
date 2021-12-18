/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = " Ab5Fob_qCKMVPmiUgjSon22XRBPeSwyO";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "belkin.f11";
char pass[] = "fa444f43";

Servo BLDC1,BLDC2,BLDC3,BLDC4;

void setup()
{
  // Debug console
 WiFi.begin(ssid, pass);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println(".");
  }
   Serial.begin(9600);
  BLDC1.attach(D4);    //Pins are attatched to the D2,D3,D4,D5 pins of the NODEMCU which produces pwm//
  BLDC2.attach(D5);
  BLDC3.attach(D6);
  BLDC4.attach(D7);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  if(WiFi.status() != WL_CONNECTED){
    Serial.println("0");
  BLDC1.write(0);
  BLDC2.write(0);
  BLDC3.write(0);
  BLDC4.write(0);
    
  }
  
}


int value;
BLYNK_WRITE(V1)
{
  value = param.asInt(); // Get value as integer
   Serial.println(value);
  BLDC1.write(value);
  BLDC2.write(value);
  BLDC3.write(value);
  BLDC4.write(value);
}


int valus;
BLYNK_WRITE(V3)
{
  valus = param.asInt();// Get value as integer   
   if(valus>=128){
    BLDC1.write(value+valus-128);
    BLDC3.write(valus+valus-128);
    BLDC2.write(value);
    BLDC4.write(value);
   }
   if(valus<128){
    BLDC2.write(value+127-valus);
    BLDC4.write(value+127-valus);
    BLDC3.write(value);
    BLDC1.write(value);
  }
}




int valua;
BLYNK_WRITE(V2)
{
  valua = param.asInt();// Get value as integer   
   if(valua>=128){
    BLDC3.write(value+valua-128);
    BLDC4.write(value+valua-128); 
     BLDC1.write(value);
     BLDC2.write(value);
   }
  
     if(valua<128){
    BLDC1.write(value+127-valua);
    BLDC2.write(value+127-valua);
     BLDC3.write(value);
     BLDC4.write(value);
  }
}
}
