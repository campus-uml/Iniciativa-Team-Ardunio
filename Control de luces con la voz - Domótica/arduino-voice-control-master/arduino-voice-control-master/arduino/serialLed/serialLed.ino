int data = 0;
int ledRojo = 2;
int ledVerde = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
}

void loop() {
  // envía datos sólo si los recibe:
  if (Serial.available() > 0) {
    // lee el byte de entrada:
    data = Serial.read();
    //lo vuelca a pantalla
    if(data == 1 || data == '1'){
      Serial.print("He recibido: ");
      Serial.println(data, DEC);
      digitalWrite(ledRojo,HIGH);
    }
    else if(data == 2 || data == '2'){
      Serial.print("He recibido: ");
      Serial.println(data, DEC);
      digitalWrite(ledRojo,LOW);
    }
    else if(data == 3 || data == '3'){
      Serial.print("He recibido: ");
      Serial.println(data, DEC);
      digitalWrite(ledVerde,HIGH);
    }
    else if(data == 4 || data == '4'){
      Serial.print("He recibido: ");
      Serial.println(data, DEC);
      digitalWrite(ledVerde,LOW);
    }
    else if(data == 5 || data == '5'){
      Serial.print("He recibido: ");
      Serial.println(data, DEC);
      digitalWrite(ledRojo,HIGH);
      digitalWrite(ledVerde,HIGH);
    }
    else{
      digitalWrite(ledRojo,LOW);
      digitalWrite(ledVerde,LOW);
    }
  }
  delay(50);
}
