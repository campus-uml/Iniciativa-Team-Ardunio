#include <Servo.h>

Servo servo1;
int pinservo = 2;
int pulsomin = 1000;
int pulsomax = 2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(pinservo, pulsomin, pulsomax); //Inicializando el servomotor. at
}

void loop() {
  // put your main code here, to run repeatedly:
  servo1.write(0);
  int lectura = analogRead(A0);
  Serial.print("La lectura es: ");
  Serial.println(lectura);

  if(lectura >= 1000){
    Serial.println("Sensor Desconectado o Fuera del Suelo");
  }
  else if(lectura  > 900 && lectura < 1000){
      Serial.println("El Suelo está Seco");     
      servo1.write(180);
      //delay(5000);
      //servo1.write(0);
  }
    else if(lectura  > 800 && lectura <899){
      Serial.println("El Suelo está Semi Seco");     
      servo1.write(180);
      //delay(5000);
      //servo1.write(0);
  }
  else if(lectura  >700 && lectura < 799){
      Serial.println("El Suelo está Semi Húmedo");     
      servo1.write(180);
      //delay(5000);
      //servo1.write(0);
  }
    else if(lectura > 600 && lectura < 699){
      Serial.println("El Suelo está Húmedo");     
      servo1.write(180);
      //delay(5000);
      //servo1.write(0);
  }
      else if(lectura  > 500 && lectura < 161){
      Serial.println("El Suelo tiene capacidad de campo");     
      servo1.write(180);
      //delay(5000);
      //servo1.write(0);
  }
  else if(lectura  > 150 && lectura <160){
      Serial.println("Levantar Riego");     
      servo1.write(270);
      //delay(5000);
      servo1.write(0);
  }
    else if(lectura  > 0 && lectura < 149){
      Serial.println("Inundado");     
      servo1.write(270);
      //delay(5000);
      servo1.write(0);
  }
  delay(1000);
  
}
