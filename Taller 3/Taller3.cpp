//Developer Carlos Burgos
//Taller_#3 Medidor de temperatura

#include <LiquidCrystal.h>
#define TMP A0
#define Led_rojo 13
#define motor 10

int segundos = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup(){
lcd_1.begin(16, 2);
  Serial.begin(9600);
  pinMode(Led_rojo, OUTPUT);
  pinMode(motor, OUTPUT);
  
  
  lcd_1.print("   hello word!!");
  //lcd_1.print("Carlos Burgos");
  //lcd_1.print("La temperatura");
}

void loop(){
  float temperatura = analogRead(TMP) * 0.48828125 - 50;
  
lcd_1.setCursor(0, 1);
  lcd_1.print(segundos);
  delay(1100);
  segundos += 1;
  lcd_1.print("   ");
  lcd_1.print(temperatura);
  lcd_1.print(" ");
  
  
	//Aparece la temperatura en la consola
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");
  
  if (isnan(temperatura)) {
    Serial.println("Error, No se pudo leer la temperatura");
    return;
  }

  if (temperatura < 10.0){
    digitalWrite(Led_rojo, HIGH);
    delay(500);
    digitalWrite(Led_rojo, LOW);
    delay(500);
    digitalWrite(motor, LOW);
    //El led rojo intermitente y el motor esta apagado
    
  } else if (temperatura >= 11.0 && temperatura <= 24.0) {
    digitalWrite(Led_rojo, LOW);
    digitalWrite(motor, LOW);
    //Apaga el led rojo y el motor esta apagado
    
  } else if (temperatura > 26.0) {
    digitalWrite(Led_rojo, HIGH);
    delay(200);
    digitalWrite(motor, HIGH);
    delay(500);
    //pinMode(motor, HIGH);
    //Motor encendido y led rojo encendido
  }
}
