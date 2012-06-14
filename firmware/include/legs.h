#ifndef LEGS_H_
#define LEGS_H_


/// Control table address
//#define CCW_ANGLE_L		8
//#define CCW_ANGLE_H		9
#define GOAL_POSITION_L		30
#define GOAL_POSITION_H		31
#define MOVING_SPEED_L		32
#define MOVING_SPEED_H		33
#define PRESENT_POSITION_L	36
#define PRESENT_POSITION_H	37
#define PRESENT_SPEED_L		38
#define PRESENT_SPEED_H		39
#define MOVING				46

// Defining the legs
#define FRONT_LEFT	1
#define FRONT_RIGHT 2
#define BACK_LEFT	3
#define BACK_RIGHT	4

// Defining the joints
#define FRONT_LEFT_ROTATE	7
#define FRONT_LEFT_BEND		4
#define FRONT_RIGHT_ROTATE	3
#define FRONT_RIGHT_BEND	9
#define BACK_LEFT_ROTATE	5
#define BACK_LEFT_BEND		8
#define BACK_RIGHT_ROTATE	10
#define BACK_RIGHT_BEND		6


// Defining various variables
// char FORWARD, BACK, LEFT, RIGHT;


// Default setting
#define DEFAULT_BAUDNUM		1 // 1Mbps

void legsInit(void);
int forward(int state,int direction);
int convert(int degree);
void move(int leg, int angle, int length, int speed);
// void turn(char direction, char times);

#endif /* LEGS_H_ */
