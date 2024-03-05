//Developer -- Carlos Burgos
const int led_verde = 11;
const int led_rojo = 12;
const int led_amarillo = 13;

void setup(){
  pinMode(led_rojo,OUTPUT);
  Serial.begin(9600);// Baudios.
  
     //Menu de la Terminal
    Serial.println(":::MENU:::");
  	Serial.println("-----------------------------------");
    Serial.println("[1]. Encender o apagar luz verde");
    Serial.println("[2]. Apagar luz verde");
    Serial.println("[3]. Encerder o apagar luz roja");
  	Serial.println("[4]. Apagar luz roja");
  	Serial.println("[5]. Encerder o apagar luz amarilla");
  	Serial.println("[6]. Apagar luz amarilla");
  	Serial.println("[7]. Encerder todas las luces");
	Serial.println("[8]. Apagar todas las luces");
  	Serial.println("[9]. Poner luces en intermitente");
    Serial.println(":::Please, press your option.:::");
  	Serial.println("-----------------------------------");
  
  
}

void loop(){ 
  
  if(Serial.available() > 0){
  	char opt = Serial.read();
    
    switch (opt){
    case '1':
      digitalWrite(led_verde, HIGH);
      Serial.print("Opcion: 1");
      Serial.println(" El led verde se a prendido");
      break;
      
     case '2':
		digitalWrite(led_verde, LOW);
      	Serial.print("Opcion: 2");
       	Serial.println("Led verde ha sido apagado");
        break;
      
      case '3':
      	digitalWrite(led_rojo, HIGH);
      	Serial.print("Opcion: 3");
      	Serial.println(" El led rojo se a prendido");
      	break;
      
      case '4':
      	digitalWrite(led_rojo, LOW);
      	Serial.print("Opcion: 4 ");
       	Serial.println("Led rojo ha sido apagado");
        break;
      
      case '5':
      	digitalWrite(led_amarillo, HIGH);
      	Serial.print("Opcion: 5 ");
      	Serial.println(" El led amarillo se a prendido");
      	break;
      
      case '6':
      	digitalWrite(led_amarillo, LOW);
      	Serial.print("Opcion: 6");
       	Serial.println("Led amarillo ha sido apagado");
        break;
      
      case '7':
      	digitalWrite(led_rojo, HIGH);
      	digitalWrite(led_verde, HIGH);
      	digitalWrite(led_amarillo, HIGH);
      	Serial.print("Opcion: 7 ");
      	Serial.println("Se prendieron todas las luces");
      	break;
      
      case '8':
      	digitalWrite(led_rojo, LOW);
      	digitalWrite(led_verde, LOW);
      	digitalWrite(led_amarillo, LOW);
      	Serial.print("opcion: 8 ");
      	Serial.println("Se apagaron todas las luces");
      	break;
      
      case '9':
      	for (int i = 0; i < 10; i++) {
          digitalWrite(led_verde, HIGH);
          digitalWrite(led_rojo, HIGH);
          digitalWrite(led_amarillo, HIGH);
          delay(500);
          digitalWrite(led_verde, LOW);
          digitalWrite(led_rojo, LOW);
          digitalWrite(led_amarillo, LOW);
          delay(500);
       }
      	Serial.print("Opcion: 9 ");
        Serial.println("Modo intermitente activado");
        break;
      
      	default:
        Serial.println("Opt no valida. Ingrese un numero del 1 al 9.");
      
    }
  }
}  

  
   /*if(Serial.available() > 0){
     char opt = Serial.read();
     if(opt == '1'){
     	digitalWrite(led_rojo, HIGH);
       Serial.print("opcion: 1");
       Serial.println(" El led rojo se a prendido");
       
     }else if(opt == '0'){
     	digitalWrite(led_rojo, LOW);
       Serial.println("Led Rojo ha sido apagado");
     }else {
      Serial.println("Ingrese una opción valida");
     }
   }
   */
  
