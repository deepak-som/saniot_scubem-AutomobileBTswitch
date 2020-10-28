char inputByte;
char lamp_state = '0';
int relay_port = 11;

unsigned long interval = 5000;
unsigned long lampTurnedOnAt;
unsigned long lampTurnedOffAt;

unsigned long time_for_action;

unsigned long buttonPushedMillis;

unsigned long receivedTime;



void setup() {

  
  Serial.begin(9600);
  pinMode(relay_port, OUTPUT);
  digitalWrite(relay_port , HIGH); //relay off
}

void loop() {
//  lamp_state = 0; //initial state of the lamp off.
//  digitalWrite(relay_port, HIGH); // set the relay off intially
//unsigned long currentTime = millis();

unsigned long currentMillis = millis(); 

while(Serial.available()>0){

  
//if(currentTime-previousTime == period){
    inputByte = Serial.read();   //reading the bluetooth signal
  
    Serial.print("inputByte\t");
    Serial.println(inputByte);

    if(inputByte == '1'){
      buttonPushedMillis = currentMillis;
      }
//   
    
    //Acknowlege back to app that signal recieved succesfully
    
   
//    Serial.print("lamp_state intially-->\t");
//    Serial.println(lamp_state);
//}
//     unsigned long currentTime = millis();
//    if(lamp_state ==1){
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



//
//      if(currentTime - previousTime >= period){
//     
//      }
 
      break;


//      default:
//      digitalWrite(relay_port, HIGH);
//      Serial.println("Lamp off");
//      lamp_state = '0';
//      Serial.print("Lamp State--->\t");
//      Serial.println(lamp_state);
//      break;


      
 }


 
}
 
//  if(lamp_state == '1'){
//   
//}
  
