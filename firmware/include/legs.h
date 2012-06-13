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


// Defining the joints
#define RIGHT_HIP_ROTATE	10
#define RIGHT_HIP_BEND		9
#define RIGHT_KNEE			8
#define RIGHT_ANKLE			7
#define LEFT_HIP_ROTATE		6
#define LEFT_HIP_BEND		5
#define LEFT_KNEE			4
#define LEFT_ANKLE			3


// Defining various variables
char FORWARD, BACK, LEFT, RIGHT;


// Default setting
#define DEFAULT_BAUDNUM		1 // 1Mbps

void legsInit(void);
void move(char direction, char speed);
void turn(char direction, char times);

#endif /* LEGS_H_ */
