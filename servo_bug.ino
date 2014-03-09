#include <Servo.h>

Servo leg1;
Servo leg2;
Servo leg3;
Servo leg4;
Servo leg5;
Servo leg6;

const int lightSensor

int sensorValue = 0;
int sensorMax = 1023;
int sensorMin = 0;

int up = 0;
int down = 90;

void setup(){

  leg1.attach(3);
  leg2.attach(5);
  leg3.attach(6);
  leg1.attach(9);
  leg2.attach(10);
  leg3.attach(11);

while(millis() <5000){  
  sensorValue = analogRead(lightSensor);
  
  if (sensorValue > sensorMax){
    sensorMax = sensorValue;
    }
    
  if (sensorValue < sensorMin){
    sensorMin = sensorValue;
    }  
  }
}

void loop(){

sensorValue = analogRead(lightSensor);
sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 9);
sensorValue = constrain (sensorValue, 0, 9);  
  
if (sensorValue -=2){  
 for(up = 0; up <90; up +=1){
   leg1.write(up);
   leg2.write(down);
   leg3.write(up);
   leg4.write(down);
   leg5.write(up);
   leg6.write(down);
   delay(15);
 }
 for(down = 90; down >=1; down -=1){
   leg1.write(down);
   leg2.write(up);
   leg3.write(down);
   leg4.write(up);
   leg5.write(down);
   leg6.write(up);
  delay(15);
    }
  }  
}


