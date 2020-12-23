void setup() {
  // put your setup code here, to run once:
pinMode(0,OUTPUT);
pinMode(2,INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);
pinMode(4,INPUT_PULLUP); // All pins to get data from sensors
pinMode(5,INPUT_PULLUP); // enabling internal pullup of promini for each pin and making that pin direction as input
pinMode(6,INPUT_PULLUP);
pinMode(7,INPUT_PULLUP);
pinMode(8,INPUT_PULLUP);
pinMode(9,INPUT_PULLUP);
pinMode(10,INPUT_PULLUP);
pinMode(11,INPUT_PULLUP);
pinMode(12,INPUT_PULLUP);

pinMode(A0,INPUT_PULLUP);
pinMode(A1,INPUT_PULLUP);
pinMode(A2,INPUT_PULLUP);
pinMode(A3,INPUT_PULLUP);
pinMode(A4,INPUT_PULLUP);
pinMode(A5,INPUT_PULLUP);

// totally 17 pins for sensors

Serial.begin(38400);

}
// variables to store data from sensors 
  uint32_t pin2,pin3,pin4,pin5,pin6,pin7,pin8,pin9,pin10,pin11,pin12,pinA0,pinA1,pinA2,pinA3,pinA4,pinA5;

  //intermediate varibles to store ORed data
  uint32_t inter1=0,inter2=0,final_data=0;
  uint8_t final_array[3]={0,0,0};
  
void loop() {
  // put your main code here, to run repeatedly:
  
  //start checking data on all pins
  if(digitalRead(2)==HIGH)
    {
     pin2=0;
    }
    else
    {
    pin2=1;
    }
    
  if(digitalRead(3)==HIGH)
    {
     pin3=0;
    }
    else
    {
    pin3=2;
    }
    
  if(digitalRead(4)==HIGH)
    {
     pin4=0;
    }
    else
    {
    pin4=4;
    }
    
    if(digitalRead(5)==HIGH)
    {
     pin5=0;
    }
    else
    {
    pin5=8;
    }
    
    if(digitalRead(6)==HIGH)
    {
     pin6=0;
    }
    else
    {
    pin6=16;
    }

    if(digitalRead(7)==HIGH)
    {
     pin7=0;
    }
    else
    {
    pin7=32;
    }

    if(digitalRead(8)==HIGH)
    {
     pin8=0;
    }
    else
    {
    pin8=64;
    }
    if(digitalRead(9)==HIGH)
    {
     pin9=0;
    }
    else
    {
    pin9=128;
    }
    
    if(digitalRead(10)==HIGH)
    {
     pin10=0;
    }
    else
    {
    pin10=256;
    }

    if(digitalRead(11)==HIGH)
    {
     pin11=0;
    }
    else
    {
    pin11=512;
    }
    
    if(digitalRead(12)==HIGH)
    {
     pin12=0;
    }
    else
    {
    pin12=1024;
    }

     if(digitalRead(A0)==HIGH)
    {
     pinA0=0;
    }
    else
    {
    pinA0=2048;
    }


 if(digitalRead(A1)==HIGH)
    {
     pinA1=0;
    }
    else
    {
    pinA1=4096;
    }


 if(digitalRead(A2)==HIGH)
    {
     pinA2=0;
    }
    else
    {
    pinA2=8192;
    }


 if(digitalRead(A3)==HIGH)
    {
     pinA3=0;
    }
    else
    {
    pinA3=16384;
    }


 if(digitalRead(A4)==HIGH)
    {
    pinA4=0;
    }
    else
    {
    pinA4=32768;
    }

     if(digitalRead(A5)==HIGH)
    {
     pinA5=0;
    }
    else
    {
     pinA5=65536;
    }

/* combine all data into one variable in binary form
   example : if data on pins 2 and 4 
   final_data = 00000000000000101*/

inter1= pin2|pin3|pin4|pin5|pin6|pin7|pin8;
inter2=inter1|pin9|pin10|pin11|pin12|pinA0;
final_data=inter2|pinA1|pinA2|pinA3|pinA4|pinA5;

final_array[0]=final_data & 0xff;
final_array[1]=(final_data & 0xff00)>>8;
final_array[2]=(final_data & 0x10000)>>16;
  
 
 Serial.write(final_array,3);
 delay(10);
//can change delay according to implementation

}
