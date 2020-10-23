char inputByte = '0' ;
char lamp_state = '0';
int relay_port = 11;
//unsigned long ON_duration_val= 60000; //define your ON duration here in seconds, unit are in miliseconds i.e 1000 = 1 sec.
#define interval 5000;

//unsigned long previousTime;
unsigned long time_for_action;



void setup() {
  Serial.begin(9600);
  pinMode(relay_port, OUTPUT);
  digitalWrite(relay_port , HIGH); //relay off
}

void loop() {
//  lamp_state = 0; //initial state of the lamp off.
//  digitalWrite(relay_port, HIGH); // set the relay off intially
//unsigned long currentTime = millis();
while(Serial.available()>0){

  
//if(currentTime-previousTime == period){
    inputByte = Serial.read();   //reading the bluetooth signal
  
    Serial.print("inputByte\t");
    Serial.println(inputByte);
    
    
    //Acknowlege back to app that signal recieved succesfully
    
   
    Serial.print("lamp_state intially-->\t");
    Serial.println(lamp_state);
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

      break;


      case '1':
      digitalWrite(relay_port, LOW);
      Serial.println("Lamp on");
      lamp_state = '1';
      Serial.print("Lamp State--->\t");
      Serial.println(lamp_state);


      if(millis() > time_for_action){

      time_for_action = millis() + (unsigned long)interval;
      

      digitalWrite(relay_port, HIGH);
      Serial.println("Lamp off");
      lamp_state = 0;
      Serial.print("Lamp State-->\t");
      Serial.println(lamp_state);
  
//      Serial.print("currentTime\t");
//      Serial.println(currentTime);
//
//      Serial.print("previousTime\t");
//      Serial.println(previousTime);

//      previousTime = currentTime;
//
//      currentTime = 0UL;

      inputByte = '0';
    
    Serial.println("5secs ");
    Serial.println(millis());
  }



//
//      if(currentTime - previousTime >= period){
//     
//      }
 
      break;


      default:
      digitalWrite(relay_port, HIGH);
      Serial.println("Lamp off");
      lamp_state = '0';
      Serial.print("Lamp State--->\t");
      Serial.println(lamp_state);
      break;


      
 }


 
  
}
 
//  if(lamp_state == '1'){
//   
//}
  
