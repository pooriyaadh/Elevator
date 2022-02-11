#ifndef ELEVATOR__H
#define ELEVATOR__H
#include "stdbool.h"
#include "main.h"

typedef enum 
{
	openLoop,
	closeLoop,
}USW_State_enum;

typedef struct
{
	uint32_t close;
	uint32_t open;
}USW_tick_def;	

typedef struct
{
	USW_State_enum  state;
	USW_tick_def    tick;
	int             cnt;
}USW_State_def;

typedef enum 
{
	pressed,
	released
}Key_State_enum;

typedef struct
{
	uint32_t close;
	uint32_t open;
}Key_tick_def;

typedef struct
{
	Key_State_enum  state;
	Key_tick_def    tick;
	int             cnt;
}Key_State_def;

typedef enum 
{
	On,
	Off
}Relay_State_enum;

typedef enum 
{
	openDoor,
	closeDoor
}door_Status_def;

typedef enum 
{
	up,
	down,
	stop,
}relay_direction_def;
typedef struct
{
	uint32_t On;
	uint32_t Off;
}Relay_tick_def;

typedef struct
{
	Relay_State_enum  state;
	Relay_tick_def    tick;
}Relay_State_def;

typedef struct 
{
	USW_State_def floor1;
	USW_State_def floor2;
	USW_State_def floor3;
	USW_State_def floor4;
	USW_State_def STOP_button;
	USW_State_def STOP_door;
}microSW_def;
typedef struct 
{
	Key_State_def floor_3;
	Key_State_def floor_1;
	Key_State_def IN_NO5;
	Key_State_def IN_NO6;
	Key_State_def IN_NO7;
	Key_State_def IN_NO8;
	Key_State_def floor_4;
	Key_State_def floor_2;
}key_def;
typedef struct 
{
	Relay_State_def UP;
	Relay_State_def DOWN;
	Relay_State_def DOWN_Door;
	Relay_State_def UP_Door;
	Relay_State_def Other;
}relay_def;
typedef enum
{
	floor1,
	floor2,
	floor3,
	floor4,
}floor_def;

typedef struct
{
	bool towardUp;
	bool towardDown;
	floor_def  target;
}direction_def;

void CheckMicroSwitch(void);
void CheckKey(void);
void StartOperation(void);
void elevatorCmnd(relay_direction_def floor);
void RelayManagement(void);

extern  microSW_def   microSwitch;
extern    key_def       key;
extern   relay_def     relay;
extern  direction_def direction;



#endif




