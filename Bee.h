#ifndef BEE_H
#define BEE_H 1

//Standard headers
#include <Arduino.h>
#include <Servo.h>

#define OFFSET 10 //on the right servo
#define DEPLOYED 75
#define RETRACTED 155

class Bee {

public :

	bool side_;
	Servo *left_;
	Servo *right_;

	Bee(Servo *left, Servo *right, bool side);

	void deploy();
	void retract();
	void init();

	bool isBusy();

};

#endif
