char inputByte = '0';
int lamp_state = 0;
int received = 0;
int relay_port = 11;
int ON_duration_val= 40000; //define your ON duration here in seconds, unit are in miliseconds i.e 1000 = 1 sec.

//const int state = '0';
//define state pins and pinmodes
//and constants




void setup() {
  Serial.begin(9600);
  pinMode(relay_port, OUTPUT);
  digitalWrite(relay_port , HIGH); //relay off
  
  //setup bsud rates
//  serial reads
//  pinmodes
//    
}

void loop() {
//  Serial.println("Starting");
  lamp_state = 0; //initial state of the lamp off.
 // digitalWrite(relay_port, HIGH); // set the relay off intially
  
  while(Serial.available()>0){
    
    inputByte = Serial.read();   //reading the bluetooth signal
    Serial.print(inputByte);
    Serial.println("\t inputByte ");
    
    //Acknowlege back to app that signal recieved succesfully
    
    Serial.print(lamp_state);
    Serial.println("\tlamp_state intially ");

    Sanitize(1);

    //    Switch is on for 10sec and then off
//    if(lamp_state == 0 && inputByte == '1'){
//      
//      digitalWrite(relay_port, LOW);  // setting the relay on
//      lamp_state = 1; // setting the lamp state on.
//      
//      Serial.print(lamp_state);
//      Serial.println("\tlamp_state before delay on ");
//
//      ON_duration_val = 10000;
//
//      delay(ON_duration_val); // set the ON delay.
//      
//      digitalWrite(relay_port, HIGH); // relay off
//      lamp_state = 0; //lamp state off
//      
//      Serial.print(lamp_state);
//      Serial.println("\tlamp_state after delay off ");
//      
//      //Acknowlege back to app that santization done succesfully for given duration
//      }

    }
}

void Sanitize(int time_in_min){
  
  int time_in_sec = (time_in_min)*60;

  int long time_in_miliSec = (time_in_sec)*1000UL;

  if(lamp_state == 0 && inputByte == '1'){
      
      digitalWrite(relay_port, LOW);  // setting the relay on
      lamp_state = 1; // setting the lamp state on.
      
      Serial.print(lamp_state);
      Serial.println("\tlamp_state before delay on ");
      Serial.print(time_in_miliSec);
      Serial.println("\tDelay of this mili secs");

      Serial.print(ON_duration_val);
      Serial.println("\tOn Duration value");

//      ON_duration_val = 10000;

    for(int i=0; i<10;i++){
      delay(1000); // set the ON delay.
      }

      
      
      digitalWrite(relay_port, HIGH); // relay off
      lamp_state = 0; //lamp state off
      
      Serial.print(lamp_state);
      Serial.println("\tlamp_state after delay off ");
      
      //Acknowlege back to app that santization done succesfully for given duration
      }

  
  }
