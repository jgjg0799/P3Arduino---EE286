//Arduino Code for Weather Station
//Project 3; Jacob Gardner, Loren Larrieu, Ben Emerson, Mohammad Ahmad
//Current Date: 11/8/21 9:56 AM

#include <Servo.h>
#include <LiquidCrystal.h>

//variables for LED
int greenLED = 13;
int yellowLED = 12;
int redLED = 11;
//variables for Sensors
int windSensor = A2;
int tempSensor = A3;
int levelSensor = A4;
//variables for Servos
int dumperPin = 9;
int coverPin = 10;
//variables for LCD Display
int RS = 2;
int E = 3;
int D4 = 4;
int D5 = 5;
int D6 = 6; 
int D7 = 7;
//object creation
LiquidCrystal lcd = (RS, E, D4, D5, D6, D7);    //lcd object
Servo dumper;     //Servo object
Servo cover;      //Servo object

void setup() {
  dumper.attach(dumperPin);     //link dumper to pin
  cover.attach(coverPin);       //link cover to pin
  lcd.begin(16,2)               //lcd column and rows
  //initialize servos
}

void loop() {
  //Read in water level
  //Read in Temperature
  //Read in wind speed

  //math for temperature
  //if water level above set height, dump
  //increment dump counter

  //math for wind speed
  //if Speed is low, light green LED, turn off other LED's
  //if Speed is Medium, light yellow LED, turn off other LED's
  //if Speed is High, light red LED, turn off other LED's

  //math for temperature

  //display wind speed, water levels, temperature on LCD

  //check button, if pressed, enter low power mode

  //delay for 300ms  

}
