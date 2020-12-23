#include "SD.h"
#include"SPI.h"
#define CSpin 53
void setup() 
{
      // put your setup code here, to run once:
    Serial.begin(38400);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(22,OUTPUT);
    pinMode(24,OUTPUT);
    pinMode(26,OUTPUT);
    pinMode(A0,OUTPUT);
    pinMode(A1,OUTPUT);
    pinMode(A2,OUTPUT);
    pinMode(A3,OUTPUT);
    pinMode(A4,OUTPUT);
    pinMode(A5,OUTPUT);

    Serial.print("Initializing SD card...");
    pinMode(CSpin, OUTPUT);
    //
    // see if the card is present and can be initialized:
    if (!SD.begin(CSpin)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
    }
    Serial.println("card initialized.");


}
uint8_t data=0,count=0;
uint8_t final_data[3]={0,0,0};
uint8_t pin2,pin3,pin4,pin5,pin6,pin7,pin8,pin9,pin22,pin24,pin26,pinA0,pinA1,pinA2,pinA3,pinA4,pinA5;


void loop() {
  // put your main code here, to run repeatedly:

    while(Serial.available()<4);
    for(count=0;count<3;count++)
    {
      final_data[count]=Serial.read();
      Serial.println(final_data[count]);
    }
    pin2=final_data[0]& 0B1;
    pin3=(final_data[0]&0B10)>>1;
    pin4=(final_data[0]&0B100)>>2;
    pin5=(final_data[0]&0B1000)>>3;
    pin6=(final_data[0]&0B10000)>>4;
    pin7=(final_data[0]&0B100000)>>5;
    pin8=(final_data[0]&0B1000000)>>6; 
    pin9=(final_data[0]&0B10000000)>>7;

    pin22=final_data[1]& 0B1;
    pin24=(final_data[1]&0B10)>>1;
    pin26=(final_data[1]&0B100)>>2;
    pinA0=(final_data[1]&0B1000)>>3;
    pinA1=(final_data[1]&0B10000)>>4;
    pinA2=(final_data[1]&0B100000)>>5;
    pinA3=(final_data[1]&0B1000000)>>6; 
    pinA4=(final_data[1]&0B10000000)>>7;

    pinA5=final_data[2]& 0B1;


    digitalWrite(2,pin2);
    digitalWrite(3,pin3);
    digitalWrite(4,pin4);
    digitalWrite(5,pin5);
    digitalWrite(6,pin6);
    digitalWrite(7,pin7);
    digitalWrite(8,pin8);
    digitalWrite(9,pin9);
    digitalWrite(22,pin22);
    digitalWrite(24,pin24);
    digitalWrite(26,pin26);
    digitalWrite(A0,pinA0);
    digitalWrite(A1,pinA1);
    digitalWrite(A2,pinA2);
    digitalWrite(A3,pinA3);
    digitalWrite(A4,pinA4);
    digitalWrite(A5,pinA5);



    if(SD.exists("data.csv")){ // check the card is still there
    // now append new data file
    File sensorData = SD.open("data.csv", FILE_WRITE);
    if (sensorData){
    sensorData.print(pin2);
    sensorData.print(pin3);
    sensorData.print(pin4);
    sensorData.print(pin5);
    sensorData.print(pin6);
    sensorData.print(pin7);
    sensorData.print(pin8);
    sensorData.print(pin9);
    sensorData.print(pin22);
    sensorData.print(pin24);
    sensorData.print(pin26);
    sensorData.print(pinA0);
    sensorData.print(pinA1);
    sensorData.print(pinA2);
    sensorData.print(pinA3);
    sensorData.print(pinA4);
    sensorData.print(pinA5);
    sensorData.print(',');
    sensorData.close(); // close the file
    }
    }
    else{
    Serial.println("Error writing to file !");
    }

    }        
