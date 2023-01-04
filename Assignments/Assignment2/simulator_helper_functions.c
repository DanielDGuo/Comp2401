/*

File simulator_main.c


Purpose: contains helper functions for preparing and presenting the output of medical sensors



Revision:
a. Initial code - Doron Nussbaum
b. Completed code - Daniel Guo

*/


/************************************************************************/

// INCLUDE FILES

#include "math.h"
#include "simulator_helper_functions.h"

/************************************************************************/
//MACROS  / DEFINES






/************************************************************************/
// FUNCTION PROTOTYPES





/***********************************************************************************/


/* purpose: computes parity of a short

input:
x - short who's parity is to be calculated


output:


return: parity value(0, 1)
*/

int computeParityBitShort(short x){
	int parity = 0;
	//determines the number of 1s in the given short
        for(int i = 0; i < 16; i++){
		parity += (x & (1 << i)) >> i;
	}
	//if there is an odd number of 1s, set the parity to 1
	parity = parity % 2;
	//return 1 if parity is needed
	return parity;
}

/* purpose: computes parity of an int

input:
x - int who's parity is to be calculated


output:


return: parity value(0, 1)
*/
int computeParityBitInt(int x){
	int parity = 0;
	//determines the number of 1s in the given int
        for(int i = 0; i < 32; i++){
		parity += (x & (1 << i)) >> i;
	}
	//if there is an odd number of 1s, set the parity to 1
	parity = parity % 2;
	//return 1 if parity is needed
	return parity;
}

/* purpose: computes float value of a 8 bit float

input:
x - intergers whos float value is to be calculated(from bit 3-10)

output:


return: float value
*/
float computeFloatValue(int x){
	//initializes the float
	float value;
	//initializes parts of the float
	int power = 0;
	char mantissa = 0;
	//calculates power
	power = ((x & (1 << 9)) >> 9)*4 + ((x & (1 << 8)) >> 8) * 2 + ((x & (1 << 7)) >> 7) - 4;
	
	for(int i = 0; i < 4; i++){
		//if the mantissa bit is 1, set the corresponding base bit
		if((x & (1 << i)) >> i){
			mantissa = mantissa | (1 << i);
		}
	}
	//set bit 4 to represent the leading 1
	mantissa = mantissa | ((1 << 4));

	for(int i = 0; i < 5; i++){
		//if the mantissa power is a 1, add the power of 2
		if(((mantissa & (1 << i)) >> i)){
			value += pow(2, (i - 4 + power));
		}
	}
	//returns a negative if the sign is 1
	if(((x & (1 << 10)) >> 10)){
		return -value;
	}
	return value;

}
