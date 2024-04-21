#include "thingProperties.h"

// DHT sensor library - Version: Latest
#include <DHT.h>
#include <DHT_U.h>
#define pin1 15 //ESPECIFICAR PIN TEMP
DHT dht1(pin1, DHT11); //INICIALIZAR DHT
#define PIN_LED 2 //ESPECIFICAR PIN LED

void setup() {
  
  pinMode(PIN_LED,OUTPUT); //DEFINIR LED COMO OUTPUT
dht1.begin(); //INICIAR DHT

  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
  //ASIGNAR LA LECTURA a la variable declarada
temperatura = dht1.readTemperature();
//IMPRIMIR EN EL MONITOR SERIAL LA TEMPERATURA
Serial.println(temperatura);
delay(4000);

  
  
}



/*
  Since Temperatura is READ_WRITE variable, onTemperaturaChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTemperaturaChange()  {
  // Add your code here to act upon Temperatura change
}

/*
  Since Luz is READ_WRITE variable, onLuzChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLuzChange()  {
  // Add your code here to act upon Luz change
  
  digitalWrite(PIN_LED, luz);
}
