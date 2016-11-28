#ifndef __37T_Functions__
#define __37T_Functions__


void setDrive(int l, int r){
	setMotorSpeed(leftMotor, l);
	setMotorSpeed(rightMotor, r);
}


void driveFor(int l, int r, int t){
	setDrive(l, r);
	wait1Msec(t);
	setDrive(0, 0);
}

void forward (int t){
	driveFor(127, 127, t);
}
void back (int t){
	driveFor(-127, -127, t);
}
void turnRight (int t){
	driveFor(127, -127, t);
}
void turnLeft (int t){
	driveFor(-127, 127, t);
}

void armUp (int t) {
	setMotorSpeed(Arm, -127);
	wait1Msec(t);
	setMotorSpeed(Arm, 0);
}
void armDown (int t) {
	setMotorSpeed(Arm, 127);
	wait1Msec(t);
	setMotorSpeed(Arm, 0);
}
void flipperUp (int t) {
	setMotorSpeed(Flipper, 127);
	wait1Msec(t);
	setMotorSpeed(Flipper, 0);
}
void flipperDown (int t) {
	setMotorSpeed(Flipper, -127);
	wait1Msec(t);
	setMotorSpeed(Flipper, 0);
}

void setStrafe(int p){
	setMotorSpeed(Strafe, p);
}

void strafeLeft (int t) {
	setMotorSpeed(Strafe, 127);
	wait1Msec(t);
	setMotorSpeed(Strafe, 0);
}
void strafeRight (int t) {
	setMotorSpeed(Strafe, -127);
	wait1Msec(t);
	setMotorSpeed(Strafe, 0);
}


bool isColorB (int port) {
	return getColorGrayscale(port) < 110;
}

void followLine(int power, unsigned int t){
	unsigned int t0 = nPgmTime;
	while(nPgmTime < (t0 + t)){
		if(isColorB(mColor)){
			setDrive(power, (int)(.65*power));
		} else {
			setDrive((int)(.65*power), power);
		}
		delay(10);
	}
}

void strafeTillLine(int power, int colorPort){
	while(!isColorB(colorPort)){
		setStrafe(power);
		delay(5);
	}
	setStrafe(0);
}


#endif
