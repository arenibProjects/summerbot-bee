#include "Bee.h"
#include "pinout.h"
#include <Servo.h>

Bee *bee;
Servo *left;
Servo *right;

void setup() {

	pinMode(2,OUTPUT);
	Serial.begin(9600);
	delay(1000);
	left = new Servo;
	right = new Servo;
	left->attach(SERVO8);
	right->attach(SERVO5);

	bee = new Bee(left, right, false);
	bee->init();
	Serial.println("init");
	delay(1000);

}

void loop() {

	bee->deploy();
	delay(1000);
	bee->retract();
	delay(1000);

}
