
#ifndef demo_h
#define demo_h

#include <Arduino.h>
///@brief Class for DemoClass
class DemoClass
{
	public:
		DemoClass();
		double distancesensor();
		int linesensor();
		bool joystick(int data);

		void move(int direction, int speed);
		void motor(int motor_id, int speed);
		void ledcolor(int red, int green, int blue);
	private:
		int level;
		int line_left;
		int line_right;
		double distance;
		long duration;
};

#endif
