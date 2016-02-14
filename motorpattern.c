#include "motorpattern.h"

void lturn (int time)
{
	motor[rightMotor] = 10;
	motor[leftMotor] = -10;
	wait1Msec(time);
}

void lturn()
{
	motor[rightMotor] = 10;
	motor[leftMotor] = -10;
}

void rturn()
{
	motor[rightMotor] = -10;
	motor[leftMotor] = 10;
	motor[backMotor] = 20;
}

void forward ()
{
	motor[rightMotor] = 10;
	motor[leftMotor] = 10;
	motor[backMotor] = 20;
}

void forward (int time)
{
	motor[rightMotor] = 10;
	motor[leftMotor] = 10;
	motor[backMotor] = 20;
	wait1Msec(time);
}

void brake()
{
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	motor[backMotor] = 0;
}

void centerscan()
{
	int lEnc = 0;

	lturn();

	if(SensorValue[sonar] < 50)
		nMotorEncoder[leftMotor] = 0;

	while(SensorValue[sonar] <50)
	{ }

	if(SensorValue[sonar] > 50)
		lEnc = nMotorEncoder[leftMotor];

	while(nMotorEncoder[leftMotor] > lEnc/2)
		rturn();
	brake();

}

int
