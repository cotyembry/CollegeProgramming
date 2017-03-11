 int main(){
clear_motor_position_counter(0);
clear_motor_position_counter(2);
 while(analog10(0)+analog10(1)<=700);{
clear_motor_position_counter(0)	;
clear_motor_position_counter(2);
 mtp(0,875,-982);
mtp(2,875,-982);
msleep(123);
}
}
