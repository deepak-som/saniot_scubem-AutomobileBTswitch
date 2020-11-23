char inputByte;
#define BT_disconnectLed = 10;
#define BT_StatePin = 11;
#define relay_port = 12;


boolean BTconnected = false;
char lamp_state = '0';



unsigned long interval;
unsigned long lampTurnedOnAt;
unsigned long lampTurnedOffAt;

unsigned long time_for_action;

unsigned long buttonPushedAtMillis;
unsigned long receivedTime;



void setup() {

  pinMode(BT_StatePin, INPUT);
  pinMode(BT_disconnectLed, OUTPUT);
  pinMode(relay_port, OUTPUT);
  digitalWrite(relay_port , HIGH); //relay off
  

  Serial.begin(9600);
  Serial.println("Ready");
  Serial.println("Connect BT");

  
  while (!BTconnected) {
    if (digitalRead(BT_StatePin) == HIGH){BTconnected = true;};
    digitalWrite(BT_disconnectLed, HIGH); //Disconnected led indicate
    }

    digitalWrite(BT_disconnectLed, LOW);
    Serial.println("BT Connected Succesfully");
    Serial.print("");

}


void loop() {
unsigned long currentMillis = millis(); 

if (digitalRead(BT_StatePin) == LOW){BTconnected = false; digitalWrite(BT_disconnectLed, HIGH);}
if (digitalRead(BT_StatePin) == HIGH){BTconnected = true; digitalWrite(BT_disconnectLed, LOW);}

//command =[D1H0003600]
// unsigned long interval_in_ms = (min*60*1000)UL
while(Serial.available()>0){
    inputByte = Serial.read();   //reading the bluetooth signal
  
    Serial.print("inputByte\t");
    Serial.println(inputByte);

    if(inputByte == '1'){
      buttonPushedAtMillis = currentMillis;
      
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

     if ((unsigned long)(currentMillis - buttonPushedAtMillis) >= interval){


        if (BTconnected == false) {
   Serial.print("BT Disconnected\t");
   digitalWrite(relay_port, HIGH);
    Serial.println("Lamp off");
    inputByte = NULL;
//    digitalWrite(BT_disconnectLed, HIGH);
    
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
//    digitalWrite(BT_disconnectLed, HIGH);
    
     };



 
}
