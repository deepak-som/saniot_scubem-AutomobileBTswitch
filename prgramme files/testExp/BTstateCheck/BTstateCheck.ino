const byte BT_StatePin = 12;
boolean BTconnected = false;
const byte ledpin = 10;

char inputByte;
char lamp_state = '0';

void setup() {
  // put your setup code here, to run once:
  pinMode(BT_StatePin, INPUT);
  pinMode(ledpin, OUTPUT);


  Serial.begin(9600);
  Serial.println("Ready");
  Serial.println("Connect BT");

  while (!BTconnected) {
    
    if (digitalRead(BT_StatePin) == HIGH){
      
      BTconnected = true;
    };
  
  }
    
    Serial.println("BT Connected Succesfully");
    Serial.print("");
}





void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BT_StatePin) == LOW){BTconnected = false; }
  if (digitalRead(BT_StatePin) == HIGH){BTconnected = true;}


  if (BTconnected == false) {
   Serial.println("BT Disconnected");
    digitalWrite(ledpin, HIGH);
     };

//  if (BTconnected==true) {
//
//    Serial.print("lamp_state\t");
//Serial.println(lamp_state);
//  };

 while (Serial.available() > 0) {
    
    inputByte = Serial.read();

    Serial.print("inputByte\t");
    Serial.println(inputByte);
  }
 
//Serial.println(digitalRead(BT_StatePin));

}
