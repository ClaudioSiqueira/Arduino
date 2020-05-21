//motor:
int motorA1 = 6;  //A -- lado direito
int motorA2 = 7;
int motorB1 = 8;  //B -- lado esquerdo 
int motorB2 = 9;
//sensor:
int sensorD = 3;
int sensorE = 4;
//potencia
//int potencia = A0;
//int potenciaread = 0;


void parafrente(){
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  }

void parar(){
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  }
  
void direita(){
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  }
  
void esquerda(){
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  }

void setup() {
  Serial.begin(9600);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(sensorD, INPUT);
  pinMode(sensorE, INPUT);
}

void loop() {
  //potenciaread = analogRead(potencia);
  //potenciaread = map(potenciaread, 0, 1023, 1, 255);
  //analogWrite(6, potenciaread);
  if (digitalRead(sensorD) == LOW and digitalRead(sensorE) == LOW){
    parafrente();
    delay(30);
    parar();
    delay(60);
    }
  if (digitalRead(sensorD) == LOW and digitalRead(sensorE) == HIGH){
    esquerda();
    delay(20);
    parar();
    delay(60);
    }
  if (digitalRead(sensorD) == HIGH and digitalRead(sensorE) == LOW){

    direita();
    delay(20);
    parar();
    delay(60);
    }
  if (digitalRead(sensorD) == HIGH and digitalRead(sensorE) == HIGH){

    parafrente();
    delay(20);
    parar();
    delay(300);
    }
}
