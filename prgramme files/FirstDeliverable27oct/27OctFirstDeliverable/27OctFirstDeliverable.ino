char inputByte;
char lamp_state = '0';
int relay_port = 11;

const byte BT_StatePin = 12;
boolean BTconnected = false;
const byte ledpin = 10;


unsigned long interval = 5000;
unsigned long lampTurnedOnAt;
unsigned long lampTurnedOffAt;

unsigned long time_for_action;

unsigned long buttonPushedMillis;
unsigned long receivedTime;



void setup() {

  pinMode(BT_StatePin, INPUT);
  pinMode(ledpin, OUTPUT);
  pinMode(relay_port, OUTPUT);
  digitalWrite(relay_port , HIGH); //relay off
  

  Serial.begin(9600);
  Serial.println("Ready");
  Serial.println("Connect BT");

  
  while (!BTconnected) {
    if (digitalRead(BT_StatePin) == HIGH){BTconnected = true;};
    }
    
    Serial.println("BT Connected Succesfully");
    Serial.print("");

}


void loop() {
unsigned long currentMillis = millis(); 

if (digitalRead(BT_StatePin) == LOW){BTconnected = false; }
if (digitalRead(BT_StatePin) == HIGH){BTconnected = true;}


while(Serial.available()>0){
    inputByte = Serial.read();   //reading the bluetooth signal
  
    Serial.print("inputByte\t");
    Serial.println(inputByte);

    if(inputByte == '1'){
      buttonPushedMillis = currentMillis;
      
//      Serial.print("lampTurnedOnAt\t");
//      Serial.println(lampTurnedOnAt);
      }  
    
    //Acknowlege back to app that signal recieved succesfully
}

    switch(inputByte){
      
      case '0':
      digitalWrite(relay_port, HIGH);
      Serial.println("Lamp off");
      lamp_state = '0';
      Serial.print("Lamp State-->\t");
      Serial.println(lamp_state);

      inputByte = NULL;

      break;

      

      case '1':
      digitalWrite(relay_port, LOW);
      
      lampTurnedOnAt = currentMillis;
      Serial.print("lampTurnedOnAt\t");
      Serial.println(lampTurnedOnAt);
      
      lamp_state = '1';
      Serial.print("Lamp State--->\t");
      Serial.println(lamp_state);

     if ((unsigned long)(currentMillis - buttonPushedMillis) >= interval){


        if (BTconnected == false) {
   Serial.print("BT Disconnected\t");
   digitalWrite(relay_port, HIGH);
    Serial.println("Lamp off");
    inputByte = NULL;
//    digitalWrite(ledpin, HIGH);
    
     };


      digitalWrite(relay_port, HIGH);
      Serial.println("Lamp off");
      
      lamp_state = '0';
      Serial.print("Lamp State--->\t");
      Serial.println(lamp_state);

      lampTurnedOffAt = currentMillis;
      Serial.print(" lampTurnedOffAt\t");
      Serial.println(lampTurnedOffAt);

     inputByte = NULL;
  }
      break;

//      default:
//      digitalWrite(relay_port, HIGH);
//      Serial.println("Lamp off");
//      lamp_state = '0';
//      Serial.print("Lamp State--->\t");
//      Serial.println(lamp_state);
//      break;
 }
if (BTconnected == false) {
   Serial.print("BT Disconnected\t");
   digitalWrite(relay_port, HIGH);
    Serial.println("Lamp off");
    inputByte = NULL;
//    digitalWrite(ledpin, HIGH);
    
     };



 
}
 
//  if(lamp_state == '1'){
//   
//}
  
