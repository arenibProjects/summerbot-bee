//---headers
#include "Bee.h"

//---functions

/**
  *  left servo, right servo, side : true = left
  */
Bee::Bee(Servo *left, Servo *right, bool side) {

	left_ = left;
	right_ = right;
	left_->write(RETRACTED);
	right_->write(RETRACTED);
	side_ = side;

}

void Bee::deploy() {

	Serial.println("deploy");
	if(side_) {
		if(left_->read() != DEPLOYED){
			left_->write(DEPLOYED);
		}
	} else {
		if(right_->read() != 180 - OFFSET + DEPLOYED) {
			right_->write(180 - OFFSET + DEPLOYED);
		}
	}
}

void Bee::retract() {

	Serial.println("retract");
	if(side_) {
		if(left_->read() != RETRACTED){
			left_->write(RETRACTED);
		}
	} else {
		if(right_->read() != 180 - OFFSET + RETRACTED) {
			right_->write(180 - OFFSET + RETRACTED);
		}
	}
}

void Bee::init() {

	left_->write(RETRACTED);
	right_->write(180 - OFFSET + RETRACTED);

}

bool Bee::isBusy() {

	return false;
}
