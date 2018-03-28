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
		if(left_->read() != 180 - DEPLOYED){
			left_->write(180 - DEPLOYED);
		}
	} else {
		if(right_->read() != OFFSET + DEPLOYED) {
			right_->write(OFFSET + DEPLOYED);
		}
	}
}

void Bee::retract() {
	
	Serial.println("retract");
	if(side_) {
		if(left_->read() != 180 - RETRACTED){
			left_->write(180 - RETRACTED);
		}
	} else {
		if(right_->read() != OFFSET + RETRACTED) {
			right_->write(OFFSET + RETRACTED);
		}
	}
}

void Bee::init() {
	
	left_->write(180 - RETRACTED);
	right_->write(OFFSET + RETRACTED);

}

bool Bee::isBusy() {

	return false;
}