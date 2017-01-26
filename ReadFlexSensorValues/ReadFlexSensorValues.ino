/*
Gunjan Sethi, 2016
This code reads the value of five flex sensors through the analog pins(A0,A1,A2,A3,A4) and displays them on the serial monitor.
Code can be used with all flavours of Arduino and its derivatives.
*/


const int flexPin1 = A0; //pin A0 to read analog input
const int flexPin2 = A1; //pin A1 to read analog input
const int flexPin3 = A2; //pin A2 to read analog input
const int flexPin4 = A3; //pin A3 to read analog input
const int flexPin5 = A4; //pin A4 to read analog input
int F1,F2,F3,F4,F5;

void setup(){
  
  pinMode(13, OUTPUT);      //Set pin 13 as 'output'
  Serial.begin(9600);       //Begin serial communication
}

void loop(){
  Serial.println();
  delay(1000);
  
  F1 = analogRead(flexPin1);         //Read and save analog
  Serial.print(F1);//Print value
  Serial.print("\t");
  
  F2 = analogRead(flexPin2);         //Read and save analog 
  Serial.print(F2);//Print value
  Serial.print("\t");

  F3 = analogRead(flexPin3);         //Read and save analog
  Serial.print(F3);//Print value
  Serial.print("\t");
  
  F4 = analogRead(flexPin1);         //Read and save analog
  Serial.print(F1);//Print value
  Serial.print("\t");
  
  F5 = analogRead(flexPin5);         //Read and save analog
  Serial.print(F5);//Print value
  Serial.print("\t");
  
  
  delay(100);      //Small delay
  
}
