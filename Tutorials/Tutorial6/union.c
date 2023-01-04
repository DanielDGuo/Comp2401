
#include <stdio.h>
#include <stdlib.h>


/***************************************************************************/

// STRUCTURES
// strucure house
struct house{
	int lights;
	char alarmCode;
};
// union anotherHouse
union anotherHouse{
	int lights;
	char alarmCode;
};



/***************************************************************************/


int main(int argc, char *argv[])
{
	printf("%lu\n", sizeof(struct house));
	printf("%lu\n", sizeof(union anotherHouse));
	struct house x;
	union anotherHouse y;

	x.lights = y.lights = 256;
	x.alarmCode = y.alarmCode = 1;
	printf("x.lights = %d, x.alarmCode = %d \n", x.lights, x.alarmCode);
	printf("y.lights = %d, y.alarmCode = %d \n", y.lights, y.alarmCode);

}
