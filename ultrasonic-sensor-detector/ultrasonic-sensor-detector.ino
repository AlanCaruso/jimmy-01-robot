#include <Wire.h>


const int trigPin = 18; // Define el pin A4 como el pin digital 18
const int echoPin = 14; // Define el pin A0 como el pin digital 14



long duration; // Variable para almacenar la duración del pulso
int distance; // Variable para almacenar la distancia calculada

void setup() {
  pinMode(trigPin, OUTPUT); // Configura trigPin como salida
  pinMode(echoPin, INPUT); // Configura echoPin como entrada
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
  Serial.println("Sensor de proximidad iniciado");
}

void loop() {
  // Limpia el trigPin
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 

  // Genera un pulso de 10 microsegundos en trigPin
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 

  // Lee el pulso de echoPin
  duration = pulseIn(echoPin, HIGH); 


  // Calcula la distancia en centímetros
  distance = duration * 0.034 / 2; 

  // Imprime la distancia calculada en el Monitor Serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");


  // Espera un pequeño intervalo antes de la siguiente medición
  delay(100); 
}
