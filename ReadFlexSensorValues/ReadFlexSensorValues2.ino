/*
GUNJAN SETHI and AKASH JAMES, 2016

The code uses two open source libraries <Wire.h> and <ADXL345.h>. It reads the values of the flex sensors to display a 
corresponding alphabet onto the serial monitor.
The code also reads and prints the values of the x,y and z-axes from the accelerometer.
read() function: This code reads the values of five flex sensors through the analog pins (A0-A4) and displays them on the serial monitor.
*/

#include <Wire.h>
#include <ADXL345.h>

ADXL345 adxl;                                                               //Variable adxl is an instance of the ADXL345 library

int x,y,z;                                                                  //Constants:

const int flexPin1 = A0; //pin A0 to read analog input from flex sensor 1
const int flexPin2 = A1; //pin A1 to read analog input from flex sensor 2
const int flexPin3 = A2; //pin A2 to read analog input from flex sensor 3
const int flexPin4 = A3; //pin A3 to read analog input from flex sensor 4
const int flexPin5 = A4; //pin A4 to read analog input from flex sensor 5

//Variables:
int F1,F2,F3,F5,F4;                                                         //Variables to save analog values from flex sensors
 

void read()
{
  F1 = analogRead(flexPin1);                                                //Read and save analog value from flex sensor 1
  Serial.print(F1);                                                         //Print value
  Serial.print("\t");   
  delay(100);                                                               //Small delay

  F2 = analogRead(flexPin2);                                                //Read and save analog value from flex sensor 2
  Serial.print(F2);                                                         //Print value
  Serial.print("\t");
  delay(100);                                                               //Small delay

  F3 = analogRead(flexPin3);                                                //Read and save analog value from flex sensor 3
  Serial.print(F3);                                                         //Print value
  Serial.print("\t");
  delay(100);                                                               //Small delay

  F4 = analogRead(flexPin4);                                                //Read and save analog value from flex sensor 4
  Serial.print(F4);                                                         //Print value
  Serial.print("\t");
  delay(100);                                                               //Small delay

  F5 = analogRead(flexPin5);                                                //Read and save analog value from flex sensor 5
  Serial.print(F5);                                                         //Print value
  Serial.print("\t");
  delay(100);                                                               //Small delay
  
  adxl.readAccel(&x, &y, &z);                                               //Read the accelerometer values and store them in variables x,y,z

  // print out values:
 
  Serial.print("x: "); Serial.println(x);                                   // Raw data without offset
  Serial.print(" y: "); Serial.println(y);                                  // Raw data without offset
  Serial.print(" z: "); Serial.println(z);                                  // Raw data without offset
  Serial.println(); 
}

void setup()
{
  Serial.begin(9600);                                                       //Begin Serial communication
  adxl.powerOn();                                                           //Activate ADXL library
}

void loop(){

  read();                                                                    //Read values from flex sensors
  
  
  if(F1>150 && F2>200 && F3>100 && F4>100 && F5>140)                        //Relaxed palm
  {
    Serial.print('N');
  }
  
  
  else if(F1>150 && F2<200 && F3<100 && F4<100 && F5<140)                   //Index finger relaxed, others flexed
  {
     Serial.print('A');
  }
  
  else if(F1<150 && F2>200 && F3>100 && F4<100 && F5<140)                   //Index finger and middle finger relaxed, others flexed
  {
    
    Serial.print('B');
  }
  
  else if(F1>150 && F2>200 && F3>100 && F4<100 && F5<140)                   //Thumb, Index finger and middle finger relaxed, others flexed
  {
    Serial.print('C');
  }
  
  else if(F1<150 && F2>200 && F3<100 && F4<100 && F5>140)                   //Index finger and little finger relaxed, others flexed
  {
    Serial.print('D');
  }
  
  else if(F1<150 && F2<200 && F3<100 && F4<100 && F5<140)                   //Fist
  {
    Serial.print('E');
  }
    
  else if(F1>150 && F2<200 && F3<100 && F4<100 && F5<140)                   //Thumb relaxed, others flexed
  {
    Serial.print('F');
  }

  else if(F1<150 && F2>200 && F3>100 && F4>100 && F5<140)                   //Index, middle and ring finger relaxed, others flexed
  {
    Serial.print('G');
  }

  else if(F1<150 && F2<200 && F3<100 && F4<100 && F5>140)                   //Only pinky finger relaxed
  {
    Serial.print('I');
  }
  Serial.println();
  delay(500);
}



