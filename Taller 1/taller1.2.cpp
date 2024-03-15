//Developer --> Carlos Burgos
//Forma 2
#define led_verde   11
#define led_rojo    12
#define led_amarillo    13

bool intermitente = false;
bool estado_verde = false;
bool estado_rojo = false;
bool estado_amarillo = false;
bool todos = false;

void setup()
{                                                                   
  pinMode(led_verde, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  
  Serial.begin(9600);
  
  Serial.println(":::MENU:::");
  	Serial.println("-----------------------------------");
    Serial.println("[1]. Encender o apagar luz verde");
   	Serial.println("[2]. Encerder o apagar luz roja");
  	Serial.println("[3]. Encerder o apagar luz amarilla");
  	Serial.println("[4]. Encerder todas las luces");
  	Serial.println("[5]. Poner luces en intermitente");
  	Serial.println("-----------------------------------");
}

void loop()
{
  while (Serial.available()== 0) {
    if (intermitente) {
      delay(1000);
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
    }
  };
  
  int input = Serial.read() - 48;
  
  if (1 == input) {
    intermitente = false;
    estado_verde = !estado_verde;
    digitalWrite(led_verde, estado_verde);
  } else if (2 == input) {
    intermitente = false;
    estado_rojo = !estado_rojo;
    digitalWrite(led_rojo, estado_rojo);
  } else if (3 == input) {
    intermitente = false;
    estado_amarillo = !estado_amarillo;
    digitalWrite(led_amarillo, estado_amarillo);
  } else if (4 == input) {
    intermitente = false;
    todos = !todos;
    digitalWrite(led_verde, todos);
    digitalWrite(led_rojo, todos);
    digitalWrite(led_amarillo, todos);
  } else if (5 == input) {
    intermitente = !intermitente;
  }
}