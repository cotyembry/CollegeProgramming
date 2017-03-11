int main(){

set_servo_position(0,2000);
set_servo_position(2,975);	
enable_servos();
msleep(1000);	
clear_motor_position_counter(0);
clear_motor_position_counter(3);	
mtp(0,500,-1000);
mtp(3,500,-1000);
msleep(3000);	
set_servo_position(0,2000);
set_servo_position(2,0);
msleep(1000);
set_servo_position(0,1700);
enable_servos();	
msleep(1000);
clear_motor_position_counter(0);
clear_motor_position_counter(3);		
mtp(0,500,0);
mtp(3,500,1500);
msleep(3000);
set_servo_position(0,1700);
set_servo_position(2,975);
enable_servos();
msleep(3000);
disable_servos();	
return 0;
}
