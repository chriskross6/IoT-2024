//3.2  Leer y escribir al monitor serial información del sensor de temperatura y humedad (DHT)

  #include "DHT.h"
  DHT dht15(15,DHT11);
  void setup()
  {
  Serial.begin(9600);
  delay(2000);
  dht15.begin();
  }
  void loop()
  {
  Serial.println("Temperatura en el sensor");
  Serial.println((dht15.readTemperature( )));
  Serial.println("Humedad en el sensor");
  Serial.println((dht15.readHumidity()));
  delay(5000);
  }
//3.3 Leer y escribir al monitor serial información del sensor ultrasónico

//Mi medidor de “CHRIS LARIOS”
const int trigPin = 5;
const int echoPin = 18;
//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
long duration;
float distanceCm;
float distanceInch;
void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microsecondsduration = pulseIn(echoPin, HIGH);
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED / 2;
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  delay(1000);
}

