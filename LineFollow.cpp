// -----------------------------------------------------------------------------

/*
	LineFollow.cpp 
	
	The purpose of this library is to use digital motors to follow a black line on a white surface. 
	First it starts off by receiving a value from the sensors.
 	Then based on the conditions (whether it senses the line or not) the motors will move corrispondingly. 
 	Each time the motors moves in a specific direction (Forwards, Backwards) a LED will be lit signifying that the 
	motor is going in that direction. 
	
	Made by Daniel Roufail, Febuary 28, 2023.
	
	This library is released into the public domain.
*/

// -----------------------------------------------------------------------------

// Allows the rest of the program access to all the Arduino language
#include "Arduino.h"

// Allows the acces of the definitions in the header file
#include "LineFollow.h"

// -----------------------------------------------------------------------------

// Subroutine for setting all the user's variables to private variables
// This allows for less alteration of the user's numbers
// This is the contructor that creates an instance of the class
Follow::Follow(int LFWD, int LREV, int RFWD, int RREV,int LFwdLed, int LRevLed, int RFwdLed, int RRevLed,  int LSensor, int RSensor){
	
	// Setting all the user inputted variables for the users pins into the private variables
	_LFWD = LFWD;        // Pin which allows the left motor to move forwards
	_LREV = LREV;        // Pin which allows the left motor to move backwards
	_RFWD = RFWD;        // Pin which allows the right motor to move forwards
	_RREV = RREV;        // Pin which allows the right motor to move backwards
	_LFwdLed = LFwdLed;  // Front LED pin on the left
	_LRevLed = LRevLed;  // Back LED pin on the left
	_RFwdLed = RFwdLed;  // Front LED pin on the right
	_RRevLed = RRevLed;  // Back LED pin on the right
	_LSensor = LSensor;  // Left sensor pin
	_RSensor = RSensor;  // Right sensor pin
}

// -----------------------------------------------------------------------------

// Subroutine for setting the pin mode of the sensor pins (Input)
// This receives a center value for each of the sensors using the min and max values
// It also initializes the serial monitor
void Follow::sensors(int LMaxVal, int LMinVal, int RMaxVal, int RMinVal){

	// Sets both pins to input pins meaning that the chip will receive a value from the sensors
	pinMode(_LSensor, INPUT);
	pinMode(_RSensor, INPUT);

	// Setting the min/max values into private variables
	_LMaxVal = LMaxVal;  // Left sensor max value
	_LMinVal = LMinVal;  // Left sensor min value
	_RMaxVal = RMaxVal;  // Right sensor max value
	_RMinVal = RMinVal;  // Right sensor min value

	_LCenter = (_LMaxVal + _LMinVal) / 2;  // Receiving the center value of the left sensor
	_RCenter = (_RMaxVal + _RMinVal) / 2;  // Receiving the center value of the right sensor

	// This opens the serial monitor so that the program can output to the screen
	Serial.begin(9600);
}

// -----------------------------------------------------------------------------

// Subroutine for setting the pin mode of the motor and LED pins (Output)
void Follow::motors(){

	// Sets all the motor pins and LED pins to output meaning that they will receive power from the chip
	pinMode(_LFWD, OUTPUT);
	pinMode(_LREV, OUTPUT);
	pinMode(_RFWD, OUTPUT);
	pinMode(_RREV, OUTPUT);
	pinMode(_LFwdLed, OUTPUT);
	pinMode(_LRevLed, OUTPUT);
	pinMode(_RFwdLed, OUTPUT);
	pinMode(_RRevLed, OUTPUT);
}

// -----------------------------------------------------------------------------

// Subroutine to make the robot turn right
void Follow::RIGHT(){

	// Stops all the motors and turns off all the LEDs
	// Stops sending power to those pins
	digitalWrite (_LFWD, LOW);
	digitalWrite (_RFWD, LOW);
	digitalWrite (_LREV, LOW);
	digitalWrite (_RREV, LOW);
	digitalWrite (_LFwdLed, LOW);
	digitalWrite (_RFwdLed, LOW);
	digitalWrite (_LRevLed, LOW);
	digitalWrite (_RRevLed, LOW);

	// Turns on the back right LED and the front left LED
	// Sends power to the right reverse motor pin and to the left forward motor pin
	// This will make the robot turn to the right
	digitalWrite (_RREV, HIGH);
	digitalWrite (_RRevLed, HIGH);
	digitalWrite (_LFWD, HIGH);
	digitalWrite(_LFwdLed, HIGH);
	delay(5);
}

// -----------------------------------------------------------------------------

// Subroutine to make the robot turn left
void Follow::LEFT(){

	// Stops all the motors and turns off all the LEDs
	// Stops sending power to those pins
	digitalWrite (_LFWD, LOW);
	digitalWrite (_RFWD, LOW);
	digitalWrite (_LREV, LOW);
	digitalWrite (_RREV, LOW);
	digitalWrite (_LFwdLed, LOW);
	digitalWrite (_RFwdLed, LOW);
	digitalWrite (_LRevLed, LOW);
	digitalWrite (_RRevLed, LOW);

	// Turns on the front right LED and the back left LED
	// Sends power to the right forward motor pin and to the left reverse motor pin
	// This will make the robot turn to the left
	digitalWrite (_RFWD, HIGH);
	digitalWrite (_RFwdLed, HIGH);
	digitalWrite (_LREV, HIGH);
	digitalWrite (_LRevLed, HIGH);
	delay(5);
}

// -----------------------------------------------------------------------------

// Subroutine to make the robot stop
void Follow::PAUSE(){

	// Stops all the motors and turns off all the LEDs
	// Stops sending power to those pins
	// This will make the robot stop moving for 1 second
	digitalWrite (_LFWD, LOW);
	digitalWrite (_RFWD, LOW);
	digitalWrite (_LREV, LOW);
	digitalWrite (_RREV, LOW);
	delay (1000);
}

// -----------------------------------------------------------------------------

// Subroutine to make the robot move forwards
void Follow::FWD(){

	// Turns on the front right LED and the front left LED
	// Sends power to the right forward motor pin and to the left forward motor pin
	// This will make the robot move forward
	digitalWrite (_LFWD, HIGH);
	digitalWrite (_LFwdLed, HIGH);
	digitalWrite (_RFWD, HIGH);
	digitalWrite (_RFwdLed, HIGH);
	delay (5);
}

// -----------------------------------------------------------------------------

// Subroutine which will allow the robot to be alined to follow the line smoothly
void Follow::followLine(){
	
	// Turns off all the LEDs and Motors
	// Stops sending power to those pins
	digitalWrite (_LFWD, LOW);
	digitalWrite (_RFWD, LOW);
	digitalWrite (_LREV, LOW);
	digitalWrite (_RREV, LOW);
	digitalWrite (_LFwdLed, LOW);
	digitalWrite (_RFwdLed, LOW);
	digitalWrite (_LRevLed, LOW);
	digitalWrite (_RRevLed, LOW);
	
	// Receives the values of the sensors and stores them in its respective variable
	_LSens = analogRead (_LSensor);
	_RSens = analogRead (_RSensor);

	// This outputs the sensor values to the serial monitor
	Serial.print("Left Sensor = ");
	Serial.print (_LSens);
	Serial.print ("     Right Sensor = ");
	Serial.println(_RSens);
	delay(5);
	
	// If the sensor values are both below the centering values then the robot will move forwards
	// This is when the sensors both sense white
	if (_LSens < _RCenter and _RSens < _LCenter){
	  
	  // Calls the subroutine to make the robot move forward
	  FWD();
	}

	// If the sensor values are both above the centering values then the robot will stop moving for 1 second
	// This is when both sensors are sensing black
	if (_LSens > _RCenter and _RSens > _LCenter){
	  
	  // Calls the subroutine to make the robot stop moving for one second
	  PAUSE();
	}

	// If the left sensor value is below centering value and the right sensor value is above sensoring value then the robot will turn a little right
	// This is when the left sensor senses white and the right sensor senses black
	if (_LSens < _RCenter and _RSens > _LCenter){

		// Calls the subroutine to make the robot turn a little right
	  	RIGHT();

	}

	// If the left sensor value is above centering value and the right sensor value is below sensoring value then the robot will turn a little left
	// This is when the right sensor senses white and the left sensor senses black
	if (_LSens > _RCenter and _RSens < _LCenter){
	  
	  	// Calls the subroutine to make the robot turn a little left
	  	LEFT();
	}

}

// -----------------------------------------------------------------------------
