int main(){
clear_motor_position_counter(0);
clear_motor_position_counter(3);
mtp(0,500,1000);
mtp(3,500,1000);
bmd(0);
bmd(3);
mtp(0,500,0);
mtp(3,500,0);
bmd(0);
bmd(3);
mav(0,1000);
mav(3,-1000);
return 0;
}
