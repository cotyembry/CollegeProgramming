int main (void)
{
	//calculates amount of ticks in degree for arm servo and claw servo
	int arm =(1300/1100);
	int claw =(2047/270);
 clear_motor_position_counter(0);
 clear_motor_position_counter(3);
 //'move to position'
 mtp(0,500,1000);	
 mtp(3,500,1000);
 bmd(0);
 bmd(3);	
enable_servos();//power the port and move the servo
set_servo_position(0,0);
set_servo_position(0,1036);
msleep(2000);
disable_servo(0);
enable_servo(2);
set_servo_position(2,0);
msleep(2000);
disable_servo(2);
 clear_motor_position_counter(0);
 clear_motor_position_counter(3);
 //'move to position'
 mtp(0,-250,1000);	
 mtp(3,-500,1000);
 bmd(0);
 bmd(3);	
  clear_motor_position_counter(0);
 clear_motor_position_counter(3);
 //'move to position'
 mtp(0,500,1000);	
 mtp(3,500,1000);
 bmd(0);
 bmd(3);
 enable_servo(0);//power the port and move the servo
set_servo_position(0,(arm*40));
set_servo_position(0,-(arm*50));
msleep(2000);
disable_servo(0);
enable_servo(2);
set_servo_position(2,(claw*0));
msleep(2000);
disable_servo(2);
return(0);
}

//Dogmeat 4 Prezedent nxt trm!
