
#ifndef WHEEL_H_
#define WHEEL_H_


#endif /* WHEEL_H_ */


/// Control table address
#define P_CCW_ANGLE_L			8
#define P_CCW_ANGLE_H			9
#define P_SPEED_L				32
#define P_SPEED_H				33
#define P_PRESENT_POSITION_L	36
#define P_PRESENT_POSITION_H	37
#define P_MOVING				46

// Defulat setting
#define DEFAULT_BAUDNUM		1 // 1Mbps

void wheelInit(void);
void wheel(int id, int speed);
int convertSpeed(int speed_percentage);
