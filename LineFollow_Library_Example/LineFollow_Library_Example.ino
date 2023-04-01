// -----------------------------------------------------------------------------

/*
 LineFollow Library Example

 This is an example for the library LineFollow. The purpose of this library is to 
 use digital motors to follow a black line on a white surface. First it starts off by receiving a value from the sensors.
 Then based on the conditions (whether it senses the line or not) the motors will move corrispondingly. 
 Each time the motors moves in a specific direction (Forwards, Backwards) a LED will be lit signifying that the 
 motor is going in that direction. 

 The following example was made using the ATmega328P programming chip (Arduino Uno). It also uses the QTR-1A IR reflective sensors.
 The motor controller used is the L293D using digital gearhead motors. The library may possibly work with different components 
 but it is recommended to use the same as the example.

 Made by Daniel Roufail, Febyuary 28, 2023.

 This is released into the public domain.
*/

// -----------------------------------------------------------------------------

// Allows the use of the library "LineFollow" in the program
#include <LineFollow.h>

// Declariing the pins for sensors, motors and LEDs
// You can change the pins to correspond to the pins being used

// Sets motor pins as variables
// Must be digital pins because the motors used are digital motors
int LFWD = 8;      // Pin which allows the left motor to move forwards
int LREV = 9;      // Pin which allows the left motor to move backwards
int RFWD = 11;     // Pin which allows the right motor to move forwards
int RREV = 10;     // Pin which allows the right motor to move backwards

// Sets the LED pins as variables
int LFwdLed = 6;   // Front LED pin on the left
int LRevLed = 7;   // Back LED pin on the left
int RFwdLed = 13;  // Front LED pin on the right 
int RRevLed = 12;  // Back LED pin on the right

// Sets sensor pins as variables
// These must be analog pins
// Adding an A before the pin number signifies that it is an analog pin
int LSensor = A2;   // Left sensor pin
int RSensor = A3;   // Right sensor pin

// Declares the max and min values for each sensor
int LMaxVal = 897; // Left sensor's max value
int LMinVal = 575; // Left sensor's min value
int RMaxVal = 823; // Right sensor's max value
int RMinVal = 384; // Right sensor's min value
 
// -----------------------------------------------------------------------------

// Gathers all the pins and sets them as private variables which will be used in the rest of the program
// It calls the subroutine "follow" in the class "Follow"
// Each of the parameters corrispond to its respective variable (No need to change the parameters only the variables above)
Follow follow(LFWD, LREV, RFWD, RREV, LFwdLed, LRevLed, RFwdLed, RRevLed, LSensor, RSensor);

// -----------------------------------------------------------------------------

// Runs code once
// This is where the pins are set as output or input pins
void setup() {

  // Sets the mode for the sensor pins and initializes the serial monitor
  // The sensor pins are set to input meaning the chip will take a value from the sensors 
  // It also recieves a centered value of the Min and Max values for each sensor to keep the robot alined
  // Each of the parameters corrispond to its respective variable (No need to change the parameters only the variables above)
  follow.sensors(LMaxVal, LMinVal, RMaxVal, RMinVal);
  
  // Sets the mode for the motor and LED pins
  // They are set to output meaning the chip will send power to the motors/LEDs
  follow.motors();
}

// -----------------------------------------------------------------------------

// Runs code infinitely
void loop() {
  
  // 1) Receives the values from the sensors and stores it
  // 2) Prints the values to the serial monitor
  // 3) Checks the conditions for directions (Forward, Left, Right, Pause) using the sensor values
  // 4) Uses the motor pins to move the motors
  // 5) Uses the LED pins to flash the LEDs
  follow.followLine();
}

// -----------------------------------------------------------------------------
