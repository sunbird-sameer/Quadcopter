
 
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "_G-ks9Jmig88_2l6VQ6U1qH22EkYsUFL";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ssid";
char pass[] = "password";

void setup()
{
  // Debug console
  Serial.begin(9600);
pinMode(D0,OUTPUT);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
pinMode(D5,INPUT);
pinMode(D6,INPUT);
pinMode(D7,INPUT);
pinMode(D8,INPUT);
pinMode(A0,OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{// up&down
  int d8In ; 
 d8In= digitalRead(D8);
 if (d8In == HIGH){
    digitalWrite(D1,HIGH);//right
    digitalWrite(D2,HIGH);//right
    digitalWrite(D3,HIGH);//left
    digitalWrite(D4,HIGH);//left
  }else{
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
    digitalWrite(D4,LOW);
  }
  //right&down
  int d7in;
 d7in= digitalRead(D7);
  if (d7in == HIGH){
   
    digitalWrite(D1,HIGH);//right
    digitalWrite(D2,HIGH);//right 
    }else{
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
    digitalWrite(D4,LOW);
    }
  //left&down
  int d6in;
  d6in= digitalRead(D6);
   
  if( d6in ==HIGH){
    digitalWrite(D3,HIGH);//left
    digitalWrite(D4,HIGH);//left 
    }else{
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
    digitalWrite(D4,LOW) ;
    }Blynk.run();
  }
  


