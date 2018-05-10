#include "Bee.h"
#include "pinout.h"
#include <Servo.h>

Bee *bee;
Servo *left;
Servo *right;

void setup() {

	Serial.begin(9600);
	delay(1);
	left = new Servo;
	right = new Servo;
	right->write(180 - (BEE_OFFSET + RETRACTED));
	left->attach(SERVO6);
	right->attach(SERVO5);

	bee = new Bee(left, right, false);
	Serial.println("init");

	delay(1000);

}

void loop() {

	bee->deploy();
	delay(1000);
	bee->retract();
	delay(1000);

}
