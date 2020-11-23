//command to turn on = [DCH, 5] here DCH = Command to turn on lamp, and 5 is the interval duration in seconds.
//command to turn off [DCL,0]

String inputByte;
const int BT_disconnectLed = 10;
const int BT_StatePin = 11;
boolean BTconnected = false;

char lamp_state = '0';
const int relay_port = 12;
const int ledpin = 10;

String sgnlvalue;
unsigned long intervalInMs;

unsigned long interval;
unsigned long lampTurnedOnAt;
unsigned long lampTurnedOffAt;

unsigned long buttonPushedMillis;

char  inputByte1;

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

//command to turn on =[DCH, 5], here DCH = Command to turn on lamp, and 5 is the interval duration in second
//command to turn off [DCL]


while(Serial.available()>0){
    inputByte = Serial.readString();   //reading the bluetooth signal
  
    Serial.print("input\t");
    Serial.println(inputByte);
    
    int openingBraceIndex = inputByte.indexOf('[');
    int commaIndex = inputByte.indexOf(',', openingBraceIndex + 1);
    int secondCommaIndex = inputByte.indexOf(',', commaIndex + 1);
    int closingBraceIndex = inputByte.indexOf(']',openingBraceIndex + 1);

    String signalValue = inputByte.substring(openingBraceIndex+1,commaIndex);
    sgnlvalue = signalValue;
     
    String intervalValueInSec = inputByte.substring(commaIndex + 1, closingBraceIndex);
    
    intervalInMs = strtoul(intervalValueInSec.c_str(), NULL, 10) * 1000UL;
    
    if(sgnlvalue == "DCH"){
      Serial.println("Into if in while with DCH");

      inputByte1 = '1';
      if(inputByte1 == '1'){
      buttonPushedMillis = currentMillis;
        }  
      }

      else if(sgnlvalue == "DCL"){
              inputByte1 = '0';}


      Serial.print("Signal Value ");
      
      
      Serial.println(signalValue);
      
      Serial.print("Sgnl value ");
      Serial.println(sgnlvalue);
      
      
      
      Serial.print("intervalValueInMiliSec ");
      Serial.println(intervalInMs);
      
      
      Serial.print("intervalValueInSec ");
      Serial.println(interval);

}

switch(inputByte1){
      
      case '0':
        digitalWrite(relay_port, HIGH);
        Serial.println("Lamp off");
        lamp_state = '0';
        Serial.print("Lamp State-->\t");
        Serial.println(lamp_state);
  
        inputByte1 = NULL;

      break;

      case '1':
        digitalWrite(relay_port, LOW);
        
        lampTurnedOnAt = currentMillis;
        Serial.print("lampTurnedOnAt\t");
        Serial.println(lampTurnedOnAt);
        
        lamp_state = '1';
        Serial.print("Lamp State--->\t");
        Serial.println(lamp_state);
    
        if ((unsigned long)(currentMillis - buttonPushedMillis) >= intervalInMs){
    
        
                if (BTconnected == false) {
           Serial.print("BT Disconnected\t");
           digitalWrite(relay_port, HIGH);
            Serial.println("Lamp off");
            inputByte1 = NULL;
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
    
          inputByte1 = NULL;
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
//    digitalWrite(ledpin, HIGH);

 inputByte1 = NULL;

};



}
