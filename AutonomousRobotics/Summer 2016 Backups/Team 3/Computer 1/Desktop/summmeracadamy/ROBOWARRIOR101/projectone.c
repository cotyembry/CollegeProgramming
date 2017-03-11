.0int main(){							
	set_servo_position(2,1500);// set a position for the servo port
	set_servo_position(0,1300);
	enable_servos();// power the port and move the servo 
	msleep(1000);
	set_servo_position(2, 100);
	msleep(1000);
	
 	set_servo_position(0, 400);
	
	msleep(1000);
	set_servo_position(0,1200);
	msleep(1000);
	set_servo_position(2,1200);
	
	
	
}

    /*long ticks = 25;
	clear_motor_position_counter(3);	
	mtp(0,1000,ticks);
	mtp(3,1000,ticks);//driving a robot forward 
//circumference= pi*d,1100 ticks/revolution 
	 int inches=12, ticks;
//inches;distance to travel, d= diameter of wheel
	float d=1.2;
	ticks=(inches/(3.14159*d)*1100);
//computes the distance from inches to ticks
	clear_motor_position_counter(0);
000,ticks);
	mtp(3,-1000,ticks);
	bmd(-0);
	bmd(-3);
	mav(0,750);
	mav(0,750);
	mav(0,750);
	mav(0,750);
	mav(0,-750);
	mav(0,-750);
   return 0;
//driving a robot forward 
int main(){
//circumference= pi*d,1100 ticks/revolution 
	 int inches=12, ticks;
//inches;distance to travel, d= diameter of wheel
	float d=1.2;
	ticks=(inches/(3.14159*d)*1100);
//computes the distance from inches to ticks
	clear_motor_position_counter(0);
000,ticks);
	mtp(3,-1000,ticks);
	bmd(-0);
	bmd(-3);
	mav(0,750);
	mav(0,750);
	mav(0,750);
	mav(0,750);
	mav(0,-750);
	mav(0,-750);
   return 0;
   }
  */
 

