char inputByte = '0';
int lamp_state = 0;
int received = 0;
int relay_port = 11;
//int val ;

//const int state = '0';
//define state pins and pinmodes
//and constants




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay_port, OUTPUT);
  digitalWrite(relay_port , LOW);
  
  //setup bsud rates
//  serial reads
//  pinmodes
//    
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println("Starting");
  lamp_state = 0; //state of the lamp
  digitalWrite(relay_port, HIGH); // set the relay off intially
  
  while(Serial.available()>0){
    inputByte = Serial.read();   //reading the bluetooth signal
    Serial.print(inputByte);
    Serial.println("\t inputByte ");
    Serial.print(lamp_state);
      Serial.println("\tlamp_state intialy ");

//    Switch is on for 10sec and then off
    if(lamp_state == 0 && inputByte == '1'){
      digitalWrite(relay_port, LOW);  // setting the relay on
      lamp_state = 1; // setting the lamp state on.
      Serial.print(lamp_state);
      Serial.println("\tlamp_state before delay on ");

      delay(10000); // define your ON duration here in seconds, unit are in miliseconds i.e 1000 = 1 sec.
      digitalWrite(relay_port, HIGH); // relay off
      lamp_state = 0; //lamp state off
      Serial.print(lamp_state);
      Serial.println("\tlamp_state after delay off ");
      }

//     else if(lamp_state == 1 && inputByte == '0'){
//      digitalWrite(relay_port, LOW);
//      lamp_state = 0;
//      Serial.println(lamp_state);
//      }
//    
    }
  //serial read
  //acknowledge of command received and process intiation
  //state check & state alter
  // delay or time gap to run for a specific time
  //state off back
  //acknowledge after completion (and state value to keep the track.)
}
