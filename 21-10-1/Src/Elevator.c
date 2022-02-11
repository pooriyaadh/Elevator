#include "Elevator.h"
microSW_def   microSwitch;
key_def       key;
relay_def     relay;
direction_def direction;
void CheckMicroSwitch()
{
	if(HAL_GPIO_ReadPin(STOP_DOWN_GPIO_Port , STOP_DOWN_Pin)) // number1 
	{
		if(microSwitch.floor1.state == openLoop)
		{
			microSwitch.floor1.cnt = 0;
		}
		microSwitch.floor1.state = closeLoop;

		if(microSwitch.floor1.cnt++ > 100)
		{
	    microSwitch.floor1.cnt = 100;
		}			
	}
	else
	{
		if(microSwitch.floor1.state == closeLoop) 
		{
			microSwitch.floor1.cnt = 0;
		}
		microSwitch.floor1.state = openLoop;

		if(microSwitch.floor1.cnt++ > 100)
		{
	    microSwitch.floor1.cnt = 100;
		}			
	}
	////////////////////////////////////////////////////////
	if(HAL_GPIO_ReadPin(STOP_UP_GPIO_Port , STOP_UP_Pin)) // number2
	{
		if(microSwitch.floor2.state == openLoop)
		{
			microSwitch.floor2.cnt = 0;
		}
		microSwitch.floor2.state = closeLoop;

		if(microSwitch.floor2.cnt++ > 100)
		{
	    microSwitch.floor2.cnt = 100;
		}			
	}
	else
	{
		if(microSwitch.floor2.state == closeLoop)
		{
			microSwitch.floor2.cnt = 0;
		}
		microSwitch.floor2.state = openLoop;

		if(microSwitch.floor2.cnt++ > 100)
		{
	    microSwitch.floor2.cnt = 100;
		}			
	}
	///////////////////////////////////////////////////////
	if(HAL_GPIO_ReadPin(DOOR_DOWN_GPIO_Port,DOOR_DOWN_Pin)) // number3
	{
		if(microSwitch.floor3.state == openLoop)
		{
			microSwitch.floor3.cnt = 0;
		}
		microSwitch.floor3.state = closeLoop;

		if(microSwitch.floor3.cnt++ > 100)
		{
	    microSwitch.floor3.cnt = 100;
		}			
	}
	else
	{
		if(microSwitch.floor3.state == closeLoop)
		{
			microSwitch.floor3.cnt = 0;
		}
		microSwitch.floor3.state = openLoop;

		if(microSwitch.floor3.cnt++ > 100)
		{
	    microSwitch.floor3.cnt = 100;
		}			
	}
	///////////////////////////////////////////////////////
	if(HAL_GPIO_ReadPin(DOOR_UP_GPIO_Port,DOOR_UP_Pin)) // number4
	{
		if(microSwitch.floor4.state == openLoop)
		{
			microSwitch.floor4.cnt = 0;
		}
		microSwitch.floor4.state = closeLoop;

		if(microSwitch.floor4.cnt++ > 100)
		{
	    microSwitch.floor4.cnt = 100;
		}			
		
	}
	else
	{
		if(microSwitch.floor4.state == closeLoop)
		{
			microSwitch.floor4.cnt = 0;
		}
		microSwitch.floor4.state = openLoop;

		if(microSwitch.floor4.cnt++ > 100)
		{
	    microSwitch.floor4.cnt = 100;
		}			
	}
	
	//////////////////////////////////////////////////////
	if(HAL_GPIO_ReadPin(STOP_2_GPIO_Port,STOP_2_Pin)) //stop_for button
	{
		if(microSwitch.STOP_button.state == openLoop)
		{
			microSwitch.STOP_button.cnt = 0;
		}
		microSwitch.STOP_button.state = closeLoop;

		if(microSwitch.STOP_button.cnt++ > 100)
		{
	    microSwitch.STOP_button.cnt = 100;
		}			
	}
	else
	{
		if(microSwitch.STOP_button.state == closeLoop)
		{
			microSwitch.STOP_button.cnt = 0;
		}
		microSwitch.STOP_button.state = openLoop;

		if(microSwitch.STOP_button.cnt++ > 100)
		{
	    microSwitch.STOP_button.cnt = 100;
		}			
	}
	//////////////////////////////////////////////////////
	if(HAL_GPIO_ReadPin(STOP_1_GPIO_Port,STOP_1_Pin))  // stop for door
	{
		if(microSwitch.STOP_door.state == openLoop)
		{
			microSwitch.STOP_door.cnt = 0;
		}
		microSwitch.STOP_door.state = closeLoop;

		if(microSwitch.STOP_door.cnt++ > 100)
		{
	    microSwitch.STOP_door.cnt = 100;
		}		
	}
	else
	{
		if(microSwitch.STOP_door.state == closeLoop)
		{
			microSwitch.STOP_door.cnt = 0;
		}
		microSwitch.STOP_door.state = openLoop;

		if(microSwitch.STOP_door.cnt++ > 100)
		{
	    microSwitch.STOP_door.cnt = 100;
		}			
	}
	// end of microswitches for this project
}

void CheckKey()
{
	// this check is for floor1
	if(HAL_GPIO_ReadPin(START_DOWN_1_GPIO_Port,START_DOWN_1_Pin))
	{
		 key.floor_1.state = pressed;
	}
	else
	{
		 key.floor_1.state = released;
	}
	
	// this check is for floor 2
	////////////////////////////////////////////////////////
	if(HAL_GPIO_ReadPin(START_DOWN_2_GPIO_Port,START_DOWN_2_Pin))
	{
		 key.floor_2.state = pressed;
	}
	else
	{
		 key.floor_2.state = released;
	}
		// this check is for floor 3
	////////////////////////////////////////////////////////
	if(HAL_GPIO_ReadPin(START_UP_1_GPIO_Port,START_UP_1_Pin))
	{
		 key.floor_3.state = pressed;
	}
	else
	{
		 key.floor_3.state = released;
	}
	
		//This check is for floor 4
	////////////////////////////////////////////////////////
	if(HAL_GPIO_ReadPin(START_UP_2_GPIO_Port,START_UP_2_Pin))
	{
		 key.floor_4.state = pressed;
	}
	else
	{
		 key.floor_4.state = released;
	}
}
void StartOperation()
{
	if((direction.towardUp == false) && (direction.towardDown == false))
	{
	if(key.floor_3.state == pressed) 
	{
		direction.target = floor3; // need to edit
		if((microSwitch.floor4.state == openLoop) &&
			(microSwitch.floor4.cnt>=90)) //microswitch floo4
		{
			   direction.towardUp = false;
	 			direction.towardDown = true;
			    
		}
		else if(((microSwitch.floor1.state == openLoop) && 
			      (microSwitch.floor1.cnt >=90)) || 
		        ((microSwitch.floor2.state == openLoop) &&
		        (microSwitch.floor2.cnt>=90)))//microswitch floor1 and floor2 
		{
			   direction.towardUp = true;
	 			direction.towardDown = false;
		}
		if((microSwitch.floor3.state == openLoop)&&
			 (microSwitch.floor3.cnt>=90)) // microswitch floor3
		{
			   direction.towardUp = false;
	 			direction.towardDown = false;	
		}
		
		if((microSwitch.floor1.state == closeLoop) && 
			(microSwitch.floor1.cnt>=90) && ((microSwitch.floor2.state == closeLoop) 
		&& (microSwitch.floor2.cnt >=90)) && (microSwitch.floor3.state == closeLoop) 
		&& (microSwitch.floor3.cnt >= 90) && (microSwitch.floor4.state == closeLoop) && microSwitch.floor4.cnt>=90)
		{
			   direction.towardUp = true;
	 			direction.towardDown = false;	
		}
		
	 }
	
	 if(key.floor_4.state == pressed)
	 {
		 direction.target = floor4; // need to edit
		 
	  if((microSwitch.floor4.state != openLoop) &&
		  (microSwitch.floor4.cnt>=90)) //microswitch floo4
     {
			  direction.towardUp = true;
	 			direction.towardDown = false;
     }
  	 if((microSwitch.floor4.state == openLoop) && (microSwitch.floor4.cnt>=90))
	 {
		     direction.towardUp = false;
	 			direction.towardDown = false;
	 }
	  if((microSwitch.floor1.state == closeLoop) && 
			(microSwitch.floor1.cnt>=90) && ((microSwitch.floor2.state == closeLoop) 
		&& (microSwitch.floor2.cnt >=90)) && (microSwitch.floor3.state == closeLoop) 
		&& (microSwitch.floor3.cnt >= 90) && (microSwitch.floor4.state == closeLoop) && microSwitch.floor4.cnt>=90)
		{
			   direction.towardUp = true;
	 			direction.towardDown = false;	
		}	 
	 } 
	 
	if(key.floor_2.state == pressed)
	{
		direction.target = floor2; // need to edit
		if(((microSwitch.floor3.state == openLoop) && (microSwitch.floor3.cnt >=90)) 
			|| ((microSwitch.floor4.state == openLoop) &&(microSwitch.floor4.cnt>=90)))  
		{
		      direction.towardUp = false;
	 			direction.towardDown = true;
		}
   else if((microSwitch.floor1.state == openLoop) && 
			(microSwitch.floor1.cnt >=90)) // floor microswitch 
	 {
		    direction.towardUp = true;
	 			direction.towardDown = false;
	 }
	 if((microSwitch.floor2.state == openLoop) && (microSwitch.floor2.cnt>=90))
	 {
		     direction.towardUp = false;
	 			direction.towardDown = false;
	 }
	 	if((microSwitch.floor1.state == closeLoop) && 
			(microSwitch.floor1.cnt>=90) && ((microSwitch.floor2.state == closeLoop) 
		&& (microSwitch.floor2.cnt >=90)) && (microSwitch.floor3.state == closeLoop) 
		&& (microSwitch.floor3.cnt >= 90) && (microSwitch.floor4.state == closeLoop) && microSwitch.floor4.cnt>=90)
		{
			   direction.towardUp = false;
	 			direction.towardDown = true;	
		}
	 
	}
	if(key.floor_1.state == pressed) 
	{
		direction.target = floor1; // need to edit
		if(microSwitch.floor1.state != openLoop)
		{
			direction.towardUp = false;
			direction.towardDown = true;
		}
	 if((microSwitch.floor1.state == openLoop) && (microSwitch.floor1.cnt>=90))
	 {
		     direction.towardUp = false;
	 			direction.towardDown = false;
	 }
	 	if((microSwitch.floor1.state == closeLoop) && 
			(microSwitch.floor1.cnt>=90) && ((microSwitch.floor2.state == closeLoop) 
		&& (microSwitch.floor2.cnt >=90)) && (microSwitch.floor3.state == closeLoop) 
		&& (microSwitch.floor3.cnt >= 90) && (microSwitch.floor4.state == closeLoop) && microSwitch.floor4.cnt>=90)
		{
			   direction.towardUp = false;
	 			direction.towardDown = true;	
		}
	}
}
}
void elevatorCmnd(relay_direction_def floor)
{
	
	HAL_GPIO_WritePin(Relay_DOWN_GPIO_Port, Relay_DOWN_Pin, GPIO_PIN_RESET);
	relay.DOWN.state    = Off;
	relay.DOWN.tick.Off = HAL_GetTick(); 
	
	HAL_GPIO_WritePin(Relay_UP_GPIO_Port  , Relay_UP_Pin,  GPIO_PIN_RESET);
	relay.UP.state    = Off;
	relay.UP.tick.Off = HAL_GetTick(); 
	HAL_GPIO_WritePin(Relay_UP_Door_GPIO_Port , Relay_UP_Door_Pin  ,GPIO_PIN_RESET);
	
	switch(floor)
	{
		case up:
			HAL_GPIO_WritePin(Relay_UP_GPIO_Port, Relay_UP_Pin, GPIO_PIN_SET);//elevator is up
			relay.UP.state    = On;
			relay.UP.tick.On  = HAL_GetTick(); 
		 HAL_GPIO_WritePin(Relay_UP_Door_GPIO_Port ,Relay_UP_Door_Pin ,GPIO_PIN_SET);
		 	break;
		case down:
		  HAL_GPIO_WritePin(Relay_DOWN_GPIO_Port, Relay_DOWN_Pin, GPIO_PIN_SET);// elevator is down
			relay.DOWN.state    = On;
			relay.DOWN.tick.On = HAL_GetTick(); 
	 HAL_GPIO_WritePin(Relay_UP_Door_GPIO_Port , Relay_UP_Door_Pin  ,GPIO_PIN_SET);
			break;
		case stop:
			
			break;
	}
}
void RelayManagement(void)
{
	bool floor_1_tick = false;
	bool floor_2_tick = false;
	bool floor_3_tick = false;
	bool floor_4_tick = false;
	
	uint32_t Get_time_floor1 = 0;
	uint32_t Get_time_floor2 = 0;
	uint32_t Get_time_floor3 = 0;
	uint32_t Get_time_floor4 = 0;
	
	
	
	if(direction.towardUp)
	{
	 if(((microSwitch.STOP_button.state == openLoop) && (microSwitch.STOP_button.cnt >= 90)) 
		  ||((microSwitch.STOP_door.state == openLoop) && (microSwitch.STOP_door.cnt >= 90)))
		 {
			elevatorCmnd(stop);
			direction.towardDown = false;
			direction.towardUp = false;			 
		 }
	 
	 if(direction.target == floor1)
		{
			 elevatorCmnd(stop);
			  if(!floor_1_tick)
			  {
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_SET);
			  Get_time_floor1 = HAL_GetTick();
				floor_1_tick = true;
			  }
			if(HAL_GetTick() - Get_time_floor1 >= 60000)
				{
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_RESET);	
				}
       direction.towardDown = false;
       direction.towardUp = false;				
		}
		
		if(direction.target == floor2)
		{
			if(!floor_2_tick)
			  {
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_SET);
			  Get_time_floor2 = HAL_GetTick();
				floor_2_tick = true;
			  }
			if((microSwitch.floor1.state == openLoop) && (microSwitch.floor1.cnt >= 90))
			{
				elevatorCmnd(up);
			}
		if((microSwitch.floor2.state == openLoop) && (microSwitch.floor2.cnt >= 90))
			{
		   elevatorCmnd(stop);
				if(HAL_GetTick() - Get_time_floor2 >= 60000)
				{
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_RESET);	
				}
       direction.towardDown = false;
       direction.towardUp = false;				
			}
			else 
			{
				elevatorCmnd(up);
			}
		}
		
		if(direction.target == floor3)
		{
			if(!floor_3_tick)
			{
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_SET);
			  Get_time_floor3 = HAL_GetTick();
				floor_3_tick = true;
			}
		if((microSwitch.floor4.state == openLoop) && (microSwitch.floor4.cnt >= 90))
			{
			 direction.towardDown = true;
       direction.towardUp = false;
       elevatorCmnd(down);				
			}
	if((microSwitch.floor3.state == openLoop) && (microSwitch.floor3.cnt >= 90))
			{
		   elevatorCmnd(stop);
				if(HAL_GetTick() - Get_time_floor3 >= 60000)
				{
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_RESET);	
				}
       direction.towardDown = false;
       direction.towardUp = false;				
			}
			else 
			{
				elevatorCmnd(up);
			}
		}
		
		if(direction.target == floor4)
		{
			if(!floor_4_tick)
			{
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_SET);
			  Get_time_floor4 = HAL_GetTick();
				floor_4_tick = true;
			}
	   if((microSwitch.floor4.state == openLoop) && (microSwitch.floor4.cnt >= 90))
			{
		   elevatorCmnd(stop);
			if(HAL_GetTick() - Get_time_floor4 >= 60000)
				{
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_RESET);	
				}
       direction.towardDown = false;
       direction.towardUp = false;				
			}
			else
			{
				elevatorCmnd(up);
			}
			
		}
	}
	else if(direction.towardDown)
	{
	 if(((microSwitch.STOP_button.state == openLoop) && (microSwitch.STOP_button.cnt >= 90)) 
		||((microSwitch.STOP_door.state == openLoop) && (microSwitch.STOP_door.cnt >= 90)))
	 {
	  elevatorCmnd(stop);
    direction.towardDown = false;
    direction.towardUp = false;			 
	 }	
		
	 if(direction.target == floor1)
		{
			  if(!floor_1_tick)
			  {
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_SET);
			  Get_time_floor1 = HAL_GetTick();
				floor_1_tick = true;
			  }
			if((microSwitch.floor1.state == openLoop) && (microSwitch.floor1.cnt >= 90))
			{
		   elevatorCmnd(stop);
				if(HAL_GetTick() - Get_time_floor1 >= 60000)
				{
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_RESET);	
				}
       direction.towardDown = false;
       direction.towardUp = false;				
			}
			else
			{
				elevatorCmnd(down);
			}
		}
		
		if(direction.target == floor2)
		{
				if(!floor_2_tick)
			  {
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_SET);
			  Get_time_floor2 = HAL_GetTick();
				floor_2_tick = true;
			  }
			if((microSwitch.floor1.state == openLoop) && (microSwitch.floor1.cnt >= 90))
			{
				elevatorCmnd(up);
        direction.towardDown = false;
        direction.towardUp = true;
			}
			if((microSwitch.floor2.state == openLoop) && (microSwitch.floor2.cnt >= 90))
			{
		   elevatorCmnd(stop);
				if(HAL_GetTick() - Get_time_floor2 >= 60000)
				{
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_RESET);	
				}
       direction.towardDown = false;
       direction.towardUp = false;				
			}
			else 
			{
				elevatorCmnd(down);
			}
		}
		
		if(direction.target == floor3)
		{
				if(!floor_3_tick)
			  {
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_SET);
			  Get_time_floor3 = HAL_GetTick();
				floor_3_tick = true;
			  }
     if((microSwitch.floor4.state == openLoop) && (microSwitch.floor4.cnt >= 90))
			{
			 direction.towardDown = true;
       direction.towardUp = false;
       elevatorCmnd(down);				
			}
	if((microSwitch.floor3.state == openLoop) && (microSwitch.floor3.cnt >= 90))
			{
		   elevatorCmnd(stop);
				if(HAL_GetTick() - Get_time_floor3 >= 60000)
				{
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_RESET);	
				}
       direction.towardDown = false;
       direction.towardUp = false;				
			}
			else 
			{
				elevatorCmnd(down);
			}
		}
		
		if(direction.target == floor4)
		{
			if(!floor_4_tick)
			  {
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_SET);
			  Get_time_floor4 = HAL_GetTick();
				floor_4_tick = true;
			  }
			 elevatorCmnd(stop);
			if(HAL_GetTick() - Get_time_floor4 >= 60000)
				{
				HAL_GPIO_WritePin(DOOR_UP_GPIO_Port , DOOR_UP_Pin , GPIO_PIN_RESET);	
				}
       direction.towardDown = false;
       direction.towardUp = false;				
			
		}
	}
  else
	{
		 elevatorCmnd(stop);
	}
}




