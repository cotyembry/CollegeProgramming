#include <stdio.h>
typedef struct {
	int userdata;
	int priority;
} choice;

int main(void) {
	choice data;
		printf("enter userdata\n");
		scanf("%d", & data.userdata);
		printf("enter priority\n");
		scanf("%d", & data.priority);
	
		printf("choice.userdata = %d\n", data.userdata);
		printf("choice.priority = %d\n", data.priority);
}
