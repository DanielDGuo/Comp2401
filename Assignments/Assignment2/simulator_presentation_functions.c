/*

File simulator_presentation_functions.c


Purpose: contains functions that present the device data to the user.



Revision:
a. Initial code - Doron Nussbaum
b. Completed code - Daniel Guo

*/


/************************************************************************/

// INCLUDE FILES

#include "stdio.h"
#include "stdlib.h"
#include "simulator_presentation_functions.h"
#include "math.h"
#include "simulator_helper_functions.h"
/************************************************************************/
//MACROS  / DEFINES






/************************************************************************/
// FUNCTION PROTOTYPES



/*************************************************************************************/
/* purpose: presents the heart rate data

input:
heartRate - contains the heart rate data

output:
none

return:
0 – request was completed correctly
1 – an error has occurred (e.g., incorrect parity bit)
2 – sensor needs to be reset


*/

int presentHeartRate(short heartRate)
{
	//prints heartRate in hex
	printf("Presenting heart rate data\nInput is %x\n\n", heartRate);
	char parityBit = (heartRate & (1 << 15)) >> 15;

	//if parity is correct, proceed as normal
	if(computeParityBitShort(heartRate) == 0){
		//checks to see if the sensor needs to be reset
		if((heartRate & (1 << 1)) >> 1){
			printf("Error in data - sensor. Sensor must be reset");
			return(2);
		}

		printf("Parity bit is correct. Parity bit = %d\n", parityBit);
		
		unsigned char bpm = 0;
		//compute bpm
		for(int i = 3; i < 11; i++){
			bpm += ((heartRate & (1 << i)) >> i)*pow(2, i-3);
		}
		//print heart rate
		printf("Heart rate is %d bpm\n\n", bpm);
		
		//checks for high/low bpm
		char hiLow = ((heartRate & (1 << 11)) >> 11) + 2 * ((heartRate & (1 << 12)) >> 12);
		
		if(hiLow == 2){
			printf("Heart rate is high\n\n");
		}else if (hiLow == 3){
			printf("Heart rate is low\n\n");
		}else{
			printf("Heart rate is normal\n\n");
		}

	//if parity is incorrect, print expected bit and close with exit code 1
	}else{
		printf("Error in data - parity bit. Parity bit = %d\n", parityBit);
		//flips the incorrect parity bit to find the correct parity bit
		if(parityBit){
			parityBit = 0;
		}else{
			parityBit = 1;
		}
		printf("Expected value was %d", parityBit);
		return(1);
	}


	return(0);
}


/*************************************************************************************/
/* purpose: presents the blood pressure data

input:
bloodPressure - contains the blood pressure data

output:
none

return:
0 – request was completed correctly
1 – an error has occurred (e.g., incorrect parity bit)
2 – sensor needs to be reset


*/
int presentBloodPressure(int bloodPressure)
{
	//prints bloodPressure in hex
	printf("Presenting blood pressure data\nInput is %x\n\n", bloodPressure);

	char parityBit = (bloodPressure & (1 << 15)) >> 15;

	//if parity is correct, proceed as normal
	if(computeParityBitInt(bloodPressure) == 0){

		//checks to see if sensor needs to be reset
		if((bloodPressure & (1 << 1)) >> 1){
			printf("Error in data - sensor. Sensor must be reset");
			return(2);
		}
		
		printf("Parity bit is correct. Parity bit = %d\n", parityBit);
		
		unsigned char sysPressure = 0;
		unsigned char diaPressure = 0;
		//compute systolic pressure
		for(int i = 3; i < 11; i++){
			sysPressure += ((bloodPressure & (1 << i)) >> i)*pow(2, i-3);
		}
		//calculates diastolic pressure
		for(int i = 11; i < 19; i++){
		        diaPressure += ((bloodPressure & (1 << i)) >> i)*pow(2, i-11);
		}

		//print pressures
		printf("Diastolic blood pressure is %d\nSystolic blood pressure is %d\n\n", diaPressure, sysPressure);
		
		//checks for high/low pressure
		char hiLow = ((bloodPressure & (1 << 19)) >> 19) + 2 * ((bloodPressure & (1 << 20)) >> 20);
		
		if(hiLow == 0){
			printf("Heart rate is normal\n\n");
		}else if (hiLow == 1){
			printf("Heart rate is low\n\n");
		}else if(hiLow == 2){
			printf("Heart rate is high\n\n");
		}else{
			printf("Abnormal blood pressure; head to emergency\n\n");
		}

	//if parity is incorrect, print expected bit and close with exit code 1
	}else{
		printf("Error in data - parity bit. Parity bit = %d\n", parityBit);
		//flips the incorrect parity bit to find the correct parity bit
		if(parityBit){
			parityBit = 0;
		}else{
			parityBit = 1;
		}
		printf("Expected value was %d", parityBit);
		return(1);
	}
	return(0);
}


/*************************************************************************************/
/* purpose: presents the temperature data

input:
temperature - contains the temperature data

output:
none

return:
0 – request was completed correctly
1 – an error has occurred (e.g., incorrect parity bit)

*/


int presentTemperature(short temperature)

{
	//prints temperature in hex
	printf("Presenting temperature data\nInput is %x\n\n", temperature);
	char parityBit = (temperature & (1 << 15)) >> 15;

	//if parity is correct, proceed as normal
	if(computeParityBitShort(temperature) == 0){

		printf("Parity bit is correct. Parity bit = %d\n", parityBit);
		
		float temp = 0;
		//compute temp
		temp = 37 + computeFloatValue(temperature);

		//print temp
		printf("Body temperature is %f\n\n", temp);
	
	//if parity is incorrect, close with exit code 1
	}else{
		printf("Error in data - parity bit. Parity bit = %d\n", parityBit);
		//flips the incorrect parity bit to find the correct parity bit
		if(parityBit){
			parityBit = 0;
		}else{
			parityBit = 1;
		}
		printf("Expected value was %d", parityBit);
		return(1);
	}
	return(0);
}
