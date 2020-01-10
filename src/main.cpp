#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_VEML6075.h"



int outpin = 9;

//forward declare
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
int averageAnalogRead(int pinToRead);



Adafruit_VEML6075 uv = Adafruit_VEML6075();

void setup()
{
  Serial.begin(9600);
  pinMode(outpin, OUTPUT);

  if (! uv.begin()) {
    Serial.println("Failed to communicate with VEML6075 sensor, check wiring?");
    while (1) { delay(100); }
  }
  Serial.println("Found VEML6075 sensor");
}
}

void loop()
{
  
  float uvIntensity = uv.readUVI();

  // uvIntensity = uvIntensity * 2.634 - 2.424;
  // if (uvIntensity < 0){
  //   uvIntensity=0;
  // }

  Serial.println();
  Serial.print("UV Index reading: "); Serial.println(uv.readUVI());

  analogWrite(outpin,int(uvIntensity*5.667)); 

  delay(1000);
}

// //Takes an average of readings on a given pin
// //Returns the average
// int averageAnalogRead(int pinToRead)
// {
//   byte numberOfReadings = 8;
//   unsigned int runningValue = 0; 

//   for(int x = 0 ; x < numberOfReadings ; x++)
//     runningValue += analogRead(pinToRead);
//   runningValue /= numberOfReadings;

//   return(runningValue);  
// }

// //The Arduino Map function but for floats
// //From: http://forum.arduino.cc/index.php?topic=3922.0
// float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
// {
//   return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
// }