// Created on Wed Jun 8 2016

//Author:	John Coty Embry
//Class:	Autonomous Robotics	
//Program Comment: This will move the robot forward and around

int main() {
	//motors and 'config'
	int zero = 0;
	int one = 1;
	int two = 2;
	int three = 3;
	int speed = 1000; //velocity
	long delta_pos = -3000;
	//-------
		//help with movement (simulator only, I haven't tested this on the actual robot)
			//all movement is relative to the prior position
			//-up: if you specify delta_pos as a negative number, the robot will go up
			//-down: if you specify delta_pos as a positive number, the robot will go down (like y coordinates in the browser)
			//-right: 
			//-left: 
	//-------
	
	//you must call this function before starting the movement of the motor (I think)
	clear_motor_position_counter(zero);
	clear_motor_position_counter(three);
	//start movement
	
	//mav(
	//mrp(<motor#>,<velocity>,<position>)
	
	//mrp(
	
	
	mrp(zero, speed, delta_pos);
	mrp(three, speed, delta_pos);
	
	
	
	
	
	
	
	//and when done with movement apparently you have to call bmp(...)? though I'm not sure what it does yet
	bmd(zero);
	bmd(three);
	//end movement
	
	
	
	return 0;
}







/*
To make this better:

Create a virtual 'map', literally measure out the entire course then programatically
save variables at the positions the objects are located at and then get a perfect 
calculation for each wheel rotation and if a turn/adjustment has to happen when this
hasn't been counted for (i.e. we measured and was assuming that the robot was going
to go straight and nothing else, but the robot waisted a bit of that by having to 
turn to correct its self back on track), then subtract the amount that the adjustment
took from the overall predicted movement.

This could help get a sense of where you're at in the environment as you are trying
to write to code to solve the problem.

If this is done correctly, this could end up as a VOM (virtual object model) and then
a person could perform 'DOMish' methods on the robot to get positioning and things like
that
*/
