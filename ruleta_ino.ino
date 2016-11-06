
int tiempooff=500;
int tiempoon=tiempooff-100;
int n;
int python = 'e';
int tpython = 't';
int clicks=0;

void setup(){
  Serial.begin(9600); 
   for (n=5;n<8;n++){
      pinMode(n,OUTPUT);
  }
}
  
void loop(){
  for (n=5;n<8;n++){
          vaciar();
          digitalWrite(n,HIGH);
          delay(tiempooff);
          if (n==6){
            comprobacion();
          }
          vaciar();
          digitalWrite(n,LOW);
          delay(tiempooff);
        }
   vaciar();
   digitalWrite(6,HIGH);
   delay(tiempooff);
   comprobacion();
   vaciar();
   digitalWrite(6,LOW);
   delay(tiempooff);
}
   
void comprobacion(){
  if (Serial.available()>0){
    python = Serial.read();
    if (python=='a'){
       flash();
       tiempooff= tiempooff-50;
       if (tiempooff<50){
         tiempooff=500;
         flash();
       }
      vaciar();
    }
    if (python=='r'){
      reiniciar();
      vaciar();
    }
  }    
}

void vaciar(){
  while(Serial.available()){
    Serial.read();
  }
}

void flash(){
  for (n=5;n<8;n++){
        digitalWrite(n,LOW);
  }
  for (n=5;n<8;n++){
        digitalWrite(n,HIGH);
  }
  delay(100);
  for (n=5;n<8;n++){
        digitalWrite(n,LOW);
  }
  delay(100);
  for (n=5;n<8;n++){
        digitalWrite(n,HIGH);
  }
  delay(100);
  for (n=5;n<8;n++){
        digitalWrite(n,LOW);
  }
  delay(100);
  for (n=5;n<8;n++){
        digitalWrite(n,HIGH);
  }
  delay(100);
  for (n=5;n<8;n++){
        digitalWrite(n,LOW);
  }
}

void reiniciar(){
      tiempooff=500;
      flash();
      vaciar();
      
      Serial.write(clicks);
   
}


