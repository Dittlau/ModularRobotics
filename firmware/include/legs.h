#ifndef LEGS_H_
#define LEGS_H_


/// Control table address
#define P_CCW_ANGLE_L			8
#define P_CCW_ANGLE_H			9
#define P_SPEED_L				32
#define P_SPEED_H				33
#define P_PRESENT_POSITION_L	36
#define P_PRESENT_POSITION_H	37
#define P_MOVING				46

// Default setting
#define DEFAULT_BAUDNUM		1 // 1Mbps

void legsInit(void);
void move(int distance);
void turn(int direction, int times);

#endif /* LEGS_H_ */
