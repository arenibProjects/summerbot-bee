#ifndef PINCE_H
#define PINCE_H 1

//Standard headers
#include <Arduino.h>
#include <Servo.h>

#define DEPLOYED 0
#define RETRACTED 90

class Bee {

public :
	
	Servo* servo_;
	
	Bee(Servo *servo);
	
	void deploy();
	void retract();
	bool isBusy();
	
}

#endif