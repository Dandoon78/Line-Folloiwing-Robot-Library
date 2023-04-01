# LineFollow Library

Description

--------------

<h5> 
The purpose of this library is to use digital motors to follow a black line on a white surface. First it starts off by receiving a value from the sensors. Then based on the conditions (whether it senses the line or not) the motors will move corrispondingly. If there is an intersection the robot will stop for one second. Each time the motors moves in a specific direction (Forwards, Backwards) a LED will be lit signifying that the motor is going in that direction. 
</h5>

--------------

Subroutines

--------------

<h5>

Note: Subroutines are called from the class "Follow"

Follow(int LFWD, int LREV, int RFWD, int RREV, int LFwdLed, int LRevLed, int RFwdLed, int RRevLed,  int LSensor, int RSensor);
    
    This is the constrictor to the program. In this library all it does is it initializes the private variables that are used for storing the pin numbers. In the parameters, it is required to put all the pin numbers in the following order: left forward pin, left reverse pin, right forward pin, right reverse pin, left forward LED, left reverse LED, right forward LED, right reverse LED, left sensor, and right sensor. This line is required as it is used to create an instance of the class. In the program it will be written as: 
    
    Follow follow(LFWD, LREV, RFWD, RREV, LFwdLed, LRevLed, RFwdLed, RRevLed, LSensor, RSensor);

sensors(int LMaxVal, int LMinVal, int RMaxVal, int RMinVal);

    The sensors subroutine is in charge of setting up the sensors. It sets the pinMode to input meaning that the pins will receive a value from the sensors. This method is also used to find the center values of each sensor using their max and min values. It will also setup the serial monitor to output values to the screen. The perameters are the minimum and maximum values of each sensor in the following order: maximum for the left sensor, minimum for the left sensor, maximum for the right sensor, and minimum for the right sensor. This line is put in the void setup() to run once and it is written as:
    
    follow.sensors(LMaxVal, LMinVal, RMaxVal, RMinVal);

motors();

    The motors subroutine is used to set up the motors and the LEDs. It uses the pinMode command to declare all the motor and LED pins as output pins. This means that the chip will send power to those pins. There is no parameters because all the values used are given from the constrictor. This line is put in the void setup() to run once and written as:
    
    follow.motors();

FollowLine();

    The FollowLine subroutine is the biggest part of the program as it has multiple functions. First, it will receive the values from the sensors and store it into a variable. Second, it will print out the sensor values to the serial monitor so that the user can keep track of inconsistencies. Next, it will check the conditions for the directions to see how the robot must move. Lastly, based on the conditions it will move the motors and flash the LEDs accordingly. For this line to be used all the previous subroutines must be in the program. There is also no parameters as it uses variables declared in the constrictor. This line is put in the void loop() to run infinitely and it is written as:
    
    follow.followLine();
</h5>

--------------

Restrictions

--------------

<h5>

1) You cannot use the motors in this library without the sensors and LEDs also being used.

2) The constrictor must be initialized before the other subroutines.

3) To use the library as intended, you must contain all the subroutines explained above. 

4) Parameters must be added if required.

5) This library is used with digital motors only.

</h5>

--------------

Recommendations

--------------

<h5>

1) This was done on the Arduino Uno (ATmega328P) so it is suggested to use that programmer although it should work with other chips.

2) The example was made using the L293D Motor Driver with gearhead motors so it is recommended to use it.

3) The sensors used are QTR-1A IR reflective sensors. The library was made to work with its inputs and are not tested with other types of sensors.

4) Make sure the motors are receiving enough power to function. 
</h5>

--------------

Credits

--------------

<h5>
Made by Daniel Roufail, Febuary 28, 2023.

Released into the public domain.
</h5>

--------------