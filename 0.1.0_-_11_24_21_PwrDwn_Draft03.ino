
//Arduino Code for Pwr Dwn switch for Weather Station
//Last Updated: 11/24/21 @ 09:41

#include <avr/sleep.h>

//pin10 = int0 on the board
#define INTERRUPT_PIN 2

//int switchPin = 10; //verify that this pin is the one used for the switch

void setup() {
  // put your setup code here, to run once:
  //the following is from this example code on github: https://gist.github.com/MMartin09/8d1bc22a4888309b32a56116ba0405c7

  Serial.begin(9600);

  // the interrupt should trigger on a falling edge so 
  // define the pin as a pullup
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);

  // turn on the builtin led to show that thw arduino is active
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  //////////////
  //set switch pin as an input
  //pinMode(switchPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //if statement to run powerDownFunc if a switch is flipped

  delay(3000);//simulate some code...

  if (digitalRead(2)== LOW){
    powerDownFunc(); //power down mode function
  }
    

}

////////////////////////////////////////////////////////////////////////////////
void powerDownFunc() {
  //this will be the function that puts the board in pwr dwn mode
  //the following is from this example code: https://gist.github.com/MMartin09/8d1bc22a4888309b32a56116ba0405c7

  Serial.println("Weather Station Is Sleeping!");

  sleep_enable();//set the sleep enable bit

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);//select pwr down sleep mode

  attachInterrupt(0, interruptFunc, LOW); 
  //attachInterrupt function documentation: https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/

  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  // activate the sleep mode
  sleep_cpu(); 

  // simulate som important code here ...
  // This code will be executed after the arduino woke up
  Serial.println("Weather Station Woke Up!");
  digitalWrite(LED_BUILTIN, HIGH); 
}

////////////////////////////////////////////////////////////////////////////////
//the following is from the previously refereced example code
void interruptFunc() {
  // simulate some important code here ...
  // This code will be executed when the interrupt is triggered  
  Serial.println("Interrupt!");

  // disable the sleep enable bit
  sleep_disable();
  
  // detacht the acutal trigger event 
  detachInterrupt(0);
}
