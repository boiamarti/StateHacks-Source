#include <DHT.h>
signed int VoltageInput = A0;
float vOut = NULL;
float vIn = NULL;
float R1 = 30000;
float R2 = 7500;
signed int value = NULL;
///////////////////////////////
signed int Gas = A1;
float gasValue = NULL;
//////////////////////////
signed int TempPin = 11;



void setup() {
  pinMode(VoltageInput, INPUT);
  pinMode(Gas,INPUT);
  Serial.begin(9600);
  
}

void loop() {
  value = analogRead(VoltageInput);
   vOut = (value * 5.0) / 1024.0; 
   vIn = vOut / (R2/(R1+R2)); 
Serial.print("INPUT V= ");
Serial.println(vIn,2);
delay(1000);
////////////////////////////
gasValue = analogRead(Gas);
Serial.println("gas value = ");
Serial.println(gasValue,2);
delay(1000);
//////////////////////////

}
