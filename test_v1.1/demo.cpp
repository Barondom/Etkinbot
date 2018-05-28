#include "demo.h"
int trig = 12;
int echo = 13;
DemoClass::DemoClass(){
	pinMode(trig,OUTPUT); //cizildi
	pinMode(echo,INPUT); //cizildi
	pinMode(16, OUTPUT); //cizildi
	pinMode(9, OUTPUT); //cizildi blue rgb
	pinMode(4, OUTPUT); //cizildi
	pinMode(5, OUTPUT); //cizildi green rgb
	pinMode(6, OUTPUT); //cizildi red rgb
	pinMode(10, OUTPUT); //cizildi
	pinMode(11, OUTPUT); //cizildi
  level = 0;
	distance = 0;
	duration = 0;
	line_left = 0;
	line_right = 0;

}

double DemoClass::distancesensor(){
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);
	duration = pulseIn(echo, HIGH);
	distance = duration / 58.2;
	delay(50);
	return distance;
}
int DemoClass::linesensor(){
	line_left = analogRead(A3);
	line_right = analogRead(A6);
	if (line_left < 100 && line_right < 100){
		return 3;
	}
	else if (line_left < 100 && line_right > 100){
		return 2;
	}
	else if (line_left > 100 && line_right < 100){
		return 1;
	}
	else {
		return 0;
	}
}
void DemoClass::ledcolor(int red, int green, int blue){
	analogWrite(9, blue);
	analogWrite(5, green);
	analogWrite(6, red);

}
void DemoClass::motor(int motor_id, int speed){
	if (motor_id == 1) {
		if (speed < 0) {
			digitalWrite(16, LOW);
			speed = -speed;
		}
		else if (speed > 0){
			digitalWrite(16, HIGH);
		}
		else {
			digitalWrite(16, LOW);
		}
		analogWrite(10, speed);
	}
	if (motor_id == 2) {
		if (speed < 0) {
			digitalWrite(4, LOW);
			speed = -speed;
		}
		else if (speed > 0){
			digitalWrite(4, HIGH);
		}
		else {
			digitalWrite(4, LOW);
		}
		analogWrite(11, speed);
	}
}
void DemoClass::move(int direction, int speed){
	if (direction == 1){
		digitalWrite(16, HIGH);
		digitalWrite(4, HIGH);
	}else if(direction == 2){
		digitalWrite(16, LOW);
		digitalWrite(4, LOW);
	}else if(direction == 3){
		digitalWrite(16, HIGH);
		digitalWrite(4, LOW);
	}else if(direction == 4){
		digitalWrite(16, LOW);
		digitalWrite(4, HIGH);
	}
	analogWrite(10, speed);
  analogWrite(11, speed);
}
bool DemoClass::joystick(int data){
	if(data==1){
		if(analogRead(A0)>650){
			return true;
		}
		else return false;
	}
	else if(data==2){
		if(analogRead(A0)<350){
			return true;
		}
		else return false;

	}
	else if(data==3){
		if(analogRead(A1)>650){
			return true;
		}
		else return false;
	}
	else{
		if(analogRead(A1)<350){
			return true;
		}
		else return false;
	}

}
