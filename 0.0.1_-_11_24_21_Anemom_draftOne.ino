
// anemometer code. make sure to combine set up and global var sections
// last updtated: 11/29/21 @ 09:50

// utilised example code available here: https://create.arduino.cc/projecthub/achindra/diy-anemometer-wind-speed-sensor-device-84a2e3

// establish led pins for the leds. change depending on schematic for the finished circuit
int ledPinR = 9;
int ledPinY = 8;
int ledPinG = 7;

void setup() {
  // put your setup code here, to run once:

   Serial.begin(9600);

   pinMode(ledPinR, OUTPUT);
   pinMode(ledPinY, OUTPUT);
   pinMode(ledPinG, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
//////////////////////////////////////////////////////////////////////////  
  int sensorVal = analogRead(A0); //verify that A0 is free to use

  if (sensorVal > 0){
    Serial.println(sensorVal); //prints the value reported from the motor
    Serial.print(" ");
  }
//////////////////////////////////////////////////////////////////////////
  if( sensorVal < 50 ){
    //turn off other LEDs
    digitalWrite(ledPinY, LOW);
    digitalWrite(ledPinR, LOW);

    //turn on Green LED    
    digitalWrite(ledPinG, HIGH); 
  }
  else if (sensorVal < 101){
    //turn off other LEDs
    digitalWrite(ledPinG, LOW);
    digitalWrite(ledPinR, LOW);

    //turn on Yellow LED    
    digitalWrite(ledPinY, HIGH);
  }

  else if (sensorVal > 101){
    //turn off other LEDs
    digitalWrite(ledPinY, LOW);
    digitalWrite(ledPinG, LOW);

    //turn on Red LED    
    digitalWrite(ledPinR, HIGH);
  }

  else {
    //digitalWrite all led's to low
    digitalWrite(ledPinY, LOW);
    digitalWrite(ledPinR, LOW);    
    digitalWrite(ledPinG, LOW);
  }

}
