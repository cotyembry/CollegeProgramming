int main() {

int i=100;

while (i < 1000) {
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,i,1000);
	mtp(3,i,1000);
	bmd(0);
	bmd(3);
	i=i+100;
	}
return 0;
}
