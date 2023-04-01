// -----------------------------------------------------------------------------

/*
	LineFollow.h 
	
	The purpose of this library is to use digital motors to follow a black line on a white surface. 
	First it starts off by receiving a value from the sensors.
 	Then based on the conditions (whether it senses the line or not) the motors will move corrispondingly. 
 	Each time the motors moves in a specific direction (Forwards, Backwards) a LED will be lit signifying that the 
	motor is going in that direction.  
	
	Made by Daniel Roufail, Febuary 28, 2023.
	
	This library is released into the public domain.
*/

// -----------------------------------------------------------------------------

// Checks to see if the include statement is already added
// This prevents problems from occuring if it is accidentally added twice
#ifndef LineFollow_h
#define LineFollow_h

// -----------------------------------------------------------------------------

// Allows all the Arduino language to be used in this file
#include "Arduino.h"

// -----------------------------------------------------------------------------

// Creates a class called Follow which will set all the subroutines and variables (One line for each subroutine)
// All that is set under public means that it can be accessed by anyone using the library
// All the variables under private can only be accessed within the class
class Follow{

	// Sets the subroutines below to be accessed by anyone using the library
	public:

		// Subroutine for setting all the user's variables to private variables
		// This allows for less alteration of the user's numbers
		// This is the contructor that creates an instance of the class
		Follow(int LFWD, int LREV, int RFWD, int RREV, int LFwdLed, int LRevLed, int RFwdLed, int RRevLed,  int LSensor, int RSensor);
		
		// Subroutine for setting the pin mode of the sensor pins (Input)
		// It receives the center values of each sensor
		// It also initializes the serial monitor
		void sensors(int LMaxVal, int LMinVal, int RMaxVal, int RMinVal);

		// Subroutine for setting the pin mode of the motor and LED pins (Output)
		void motors();

		// Subroutine to make the robot turn right
		void RIGHT();

		// Subroutine to make the robot turn left
		void LEFT();

		// Subroutine to make the robot stop
		void PAUSE();

		// Subroutine to make the robot move forwards
		void FWD();

		// Subroutine which will allow the robot to be alined to follow the line smoothly
		void followLine();

	// Declares the variables below to only be accessed within the class
	private:

		// These are variables for the various pins being used
		int _LSensor;
		int _RSensor;
		int _LMaxVal;
		int _LMinVal;
		int _RMaxVal;
		int _RMinVal;
		int _LFWD;
		int _LREV;
		int _RFWD;
		int _RREV;
		int _LFwdLed;
		int _LRevLed;
		int _RFwdLed;
		int _RRevLed;

		// Sets the variables to get the center values of each sensor
		int _LCenter;
		int _RCenter;

		// Sets variables that would store the sensor values
		int _LSens;
		int _RSens;
};

// -----------------------------------------------------------------------------

// This concludes the header file
#endif