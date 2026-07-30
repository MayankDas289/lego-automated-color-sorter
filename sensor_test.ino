
#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;
int ledR=10;
int ledG=9;
int ledB=3;
void setup()
{
  Serial.begin(115200);
pinMode(ledR,OUTPUT);
pinMode(ledG,OUTPUT);
pinMode(ledB,OUTPUT);
  if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");

  //enable color sensing mode
  apds.enableColor(true);

  apds.setADCGain(APDS9960_AGAIN_16X); 
  apds.setADCIntegrationTime(219);
}

void loop() {
  //create some variables to store the color data in
  uint16_t r, g, b, c;
  
  //wait for color data to be ready
  while(!apds.colorDataReady()){
    
  }

  //get the data and print the different channels
  apds.getColorData(&r, &g, &b, &c);
  Serial.print("red: ");
  Serial.print(r);
  
  Serial.print(" green: ");
  Serial.print(g);
  
  Serial.print(" blue: ");
  Serial.print(b);
  
  Serial.print(" clear: ");
  Serial.println(c);
  Serial.println();
  
  if (c<200&&c>100) 
  {
    // Too dark / no part present - turn off all LEDs
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, LOW);
  }
  else if(r>g&&r>b)
  {
    digitalWrite(ledR,HIGH);
    digitalWrite(ledG,LOW);
    digitalWrite(ledB,LOW);
  }
  
  else if(b>g&&b>r)
  {
    digitalWrite(ledB,HIGH);
    digitalWrite(ledR,LOW);
    digitalWrite(ledG,LOW);
  }
  
  else if(g>r&&g>b)
  {
    digitalWrite(ledG,HIGH);
    digitalWrite(ledR,LOW);
    digitalWrite(ledB,LOW);
  }
   
   
  
  
}
