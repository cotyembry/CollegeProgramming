#include <kovan/analog.h>

int main(){
	
	int distance;
	while(1){
		distance=analog_et(0);
		printf("ET: %d\n", distance);
		
	}
	return 0;
}
