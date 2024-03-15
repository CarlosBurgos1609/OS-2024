// C++ code
// Developer: Carlos Burgos.

const int ledPin = 13; // Pin del LED rojo
const int sensorPin = A0; // Pin del sensor de temperatura TMP36
const int motorPin = 12; // Pin del motor CC

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Lectura del sensor de temperatura
  float temperatura = analogRead(sensorPin) * 0.48828125 - 50;
  //temperatura = (temperatura * 5.0 * 100.0) / 1023.0;

  

  // Validación de la temperatura
  if (temperatura < 5) {
    // Intermitencia del LED
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  } else if (temperatura >= 6 && temperatura <= 25) {
    // Apagar el LED
    digitalWrite(ledPin, LOW);
  } else if (temperatura > 25) {
    // Encender el LED y el motor
    digitalWrite(ledPin, HIGH);
    digitalWrite(motorPin, HIGH);
  }
  // Visualización de la temperatura en la consola
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
}
