#include <Adafruit_Sensor.h>

#include <DHT.h>
#include <DHT_U.h>

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

#define DHTPIN 11
#define DHTTYPE DHT11
DHT_Unified dht(DHTPIN, DHTTYPE);

/////////////////////////////////////

signed int VibPin = 9;

////////////////////////////
void setup() {
  pinMode(VoltageInput, INPUT);
  pinMode(Gas,INPUT);
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  pinMode(VibPin, INPUT);
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
Serial.println(gasValue);
delay(1000);
//////////////////////////
sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  delay(1000);
  ///////////////////////////////

  signed int vibMeasure = TP_init();
  Serial.println("Viberation = ");
  Serial.println(vibMeasure);

}

long TP_init(){
  delay(10);
  long measurement=pulseIn (VibPin, HIGH);  
  return measurement;
}
