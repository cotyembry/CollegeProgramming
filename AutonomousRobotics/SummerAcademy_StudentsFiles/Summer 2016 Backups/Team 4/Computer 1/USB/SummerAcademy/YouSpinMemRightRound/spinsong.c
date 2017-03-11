#include <stdio.h>
int main() {
for (int i=1; i<10000; i++) {
 clear_motor_position_counter(0);
 clear_motor_position_counter(3);
 //'move to position'
 mtp(0,500,1000);	
 mtp(3,-500,1000);
 printf("You spin me right round");
 printf("Right rounnd");
 printf("Like a record baby");
 printf("Right round, right round...");
}
}

