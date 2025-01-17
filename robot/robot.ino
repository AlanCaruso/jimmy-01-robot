#include <AFMotor.h>

const int trigPin = 18; // Define el pin A4 como el pin digital 18
const int echoPin = 14; // Define el pin A0 como el pin digital 14
const int ledPin = 13; // Pin para el LED indicador

// Crear objetos para los motores en las posiciones M1 y M2
AF_DCMotor motor1(1);  // Motor en la posición M1
AF_DCMotor motor2(2);  // Motor en la posición M2

long duration; // Variable para almacenar la duración del pulso
int distance; // Variable para almacenar la distancia calculada

void setup() {
  pinMode(trigPin, OUTPUT); // Configura trigPin como salida
  pinMode(echoPin, INPUT); // Configura echoPin como entrada
  pinMode(ledPin, OUTPUT); // Configura el LED como salida

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

  if (distance > 20) {
    // Movimiento hacia adelante
    motor1.setSpeed(200);
    motor1.run(FORWARD);

    motor2.setSpeed(200);
    motor2.run(FORWARD);

    digitalWrite(ledPin, LOW); // Apaga el LED cuando no hay obstáculos
  } else {
    // Detiene motores
    motor1.run(RELEASE);
    motor2.run(RELEASE);

    // Retrocede ligeramente
    Serial.println("Obstáculo detectado: Retrocediendo");
    motor1.setSpeed(150);
    motor1.run(BACKWARD);
    motor2.setSpeed(150);
    motor2.run(BACKWARD);
    delay(500);

    // Gira a la derecha
    Serial.println("Girando a la derecha");
    motor1.run(FORWARD);  // Motor izquierdo hacia adelante
    motor2.run(BACKWARD); // Motor derecho hacia atrás
    digitalWrite(ledPin, HIGH); // Enciende el LED durante el giro
    delay(500);

    // Detener motores después del giro
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    digitalWrite(ledPin, LOW); // Apaga el LED después del giro
  }

  delay(100); // Espera antes de la siguiente medición
}
