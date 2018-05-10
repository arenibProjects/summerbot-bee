#ifndef BEE_H
#define BEE_H 1

//Standard headers
#include <Arduino.h>
#include <Servo.h>

#define BEE_OFFSET 11 //on the right servo
#define DEPLOYED 77
#define RETRACTED 155

class Bee {

public :

	bool side_;
	Servo *left_;
	Servo *right_;

	Bee(Servo *left, Servo *right, bool side);

	void deploy();
	void retract();

	bool isBusy();

};

#endif
