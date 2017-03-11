#include <stdio.h>
#include <math.h>


int num_squared(int);
int num_cubed(int);
int num_sqrt (int);
int main(){
	int i, c, s;
		printf("\nThis is for the numbers 0 through 99 squared:\n\n");
		for(i = 0; i < 100; i ++) {
			printf("Number squared: %2d = %4d\n", i, num_squared(i));
			}
		
		printf("\nThis is for the numbers 0 through 99 cubed:\n\n");
		for(c = 0; c < 100; c ++) {
			printf("Number cubed: %2d = %6d\n", c, num_cubed(c));
			}
			
		printf("\nThis is for the numbers 0 through 99 square root:\n\n");
		for(s = 0; s < 100; s ++) {
			printf("Numbers square root: %2d = %d\n", s, num_sqrt(s));
			}
}

int num_squared (int i) {
		i = i * i;
		return i;
		}
		
int num_cubed (int c) {
		c = c * c * c;
		return c;
		}
		
int num_sqrt (s) {
		s = sqrt(s);
		return s;
	}
		
		
		
		
		
		
		
		
		
		