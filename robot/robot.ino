#include <AFMotor.h>

const int trigPin = 9; // Define un pin digital para trig
const int echoPin = 8; // Define un pin digital para echo

// Crear objetos para los motores en las posiciones M1 y M2
AF_DCMotor motor1(1);  // Motor en la posición M1
AF_DCMotor motor2(2);  // Motor en la posición M2

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

  // Imprime la duración del pulso en el Monitor Serial
  Serial.print("Duración del pulso: ");
  Serial.println(duration);

  // Calcula la distancia en centímetros
  distance = duration * 0.034 / 2; 

  // Imprime la distancia calculada en el Monitor Serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance > 5){
    Serial.println("Motor 1 Sentido horario");
    motor1.setSpeed(200);     // Establecer la velocidad del motor 1 (0-255)
    motor1.run(FORWARD); 

    Serial.println("Motor 2 Sentido horario");
    motor2.setSpeed(200);     // Establecer la velocidad del motor 2 (0-255)
    motor2.run(FORWARD); 
  } else {
    Serial.println("Detener ambos motores");
    motor1.run(RELEASE);      // Detener el motor 1
    motor2.run(RELEASE);      // Detener el motor 2
  }

  // Espera un pequeño intervalo antes de la siguiente medición
  delay(100); 
}
