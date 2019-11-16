const int analogInPin = A1; 
int sensorValue = 0; 
void setup() { 
  Serial.begin(9600);
  } 
  void loop() { 
      sensorValue = analogRead(analogInPin); //Read data from analog pin and store it to sensorValue variable
  
  if (sensorValue<=480){ 
    Serial.println("Water level: 0mm - Empty!"); 
  }
  else if (sensorValue>480 && sensorValue<=530){ 
    Serial.println("Water level: 0mm to 5mm"); 
  }
  else if (sensorValue>530 && sensorValue<=615){ 
    Serial.println("Water level: 5mm to 10mm"); 
  }
  else if (sensorValue>615 && sensorValue<=660){ 
    Serial.println("Water level: 10mm to 15mm"); 
  } 
  else if (sensorValue>660 && sensorValue<=680){ 
    Serial.println("Water level: 15mm to 20mm"); 
  }
  else if (sensorValue>680 && sensorValue<=690){ 
    Serial.println("Water level: 20mm to 25mm"); 
  }
  else if (sensorValue>690 && sensorValue<=700){ 
    Serial.println("Water level: 25mm to 30mm"); 
  }
  else if (sensorValue>700 && sensorValue<=705){ 
    Serial.println("Water level: 30mm to 35mm"); 
  }
  else if (sensorValue>705){ 
    Serial.println("Water level: 35mm to 40mm"); 
  }
}
