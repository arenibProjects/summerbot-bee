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
	right_->write(180 - (BEE_OFFSET + RETRACTED));
	side_ = !side;

}

void Bee::deploy() {

	if(side_ == true) {
		if(left_->read() != DEPLOYED){
			left_->write(DEPLOYED);
		}
	} else {
		if(right_->read() != 180 - (BEE_OFFSET + DEPLOYED)) {
			right_->write(180 - (BEE_OFFSET + DEPLOYED));
		}
	}
}

void Bee::retract() {

	if(side_ == true) {
		if(left_->read() != RETRACTED){
			left_->write(RETRACTED);
		}
	} else {
		if(right_->read() != 180 - (BEE_OFFSET + RETRACTED)) {
			right_->write(180 - (BEE_OFFSET + RETRACTED));
		}
	}
}

bool Bee::isBusy() {

	return false;
}
