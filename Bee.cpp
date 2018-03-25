//---headers
#include "Bee.h"

//---functions

Bee::Bee(Servo *servo) {

	servo_ = servo;
	servo_->read(RETRACTED);

}

Bee::deploy() {

	if(servo_->read() != DEPLOYED) {
		servo_->write(DEPLOYED);
	}
}

Bee::retract() {
	
	if(servo_->read() != RETRACTED) {
		servo_->write(RETRACTED);
	}
}

Bee::isBusy() {

	return false;
}