int main(){
	set_each_analog_state(1,0,0,0,0,0,0);
	//set port 0 to floating 
	sleep(0,02);         //wait for state to change
	while(1){                    //loop forever
		if(analog10(0)>512){     //if too close
			bk(0);               //back up
			bk(3);              
		}
		if(analog10(0)<=512){    //if too far away
			fd(0);               //get closer
			fd(3);
			
			
