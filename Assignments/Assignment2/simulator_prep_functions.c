/*

File simulator_main.c


Purpose: contains functions for preparing the output of the temperature and blood pressure sensors



Revision:
a. Initial code - Doron Nussbaum
b. Completed code - Daniel Guo

*/


/************************************************************************/

// INCLUDE FILES

#include "simulator_prep_functions.h"
#include "stdio.h"
#include "simulator_helper_functions.h"

/************************************************************************/
//MACROS  / DEFINES






/************************************************************************/
// FUNCTION PROTOTYPES





/***********************************************************************************/
/* purpose: prepares the heart rate data

input:
heartRate - contains the heart rate data
sensorFunction - contains the state of the sensor

output:
heartRate - stores the raw heartrate data

return:
0  request was completed correctly
1  illegal input

*/


int prepareHeartRate(int heartrate, int sensorFunction, short* heartRate)
{
	//sets bits of heartRate to 0
	*heartRate = 0;

	//checks if the heartrate and sensorFunction is within acceptable bounds
	if(heartrate > 255 || heartrate < 1 || sensorFunction < 0 || sensorFunction > 1){
		printf("prepareHeartRate - illegal input");
		return(1);
	}
	
	//if sensor function is 1, set bit 0 to signal incorrect reading
	if(sensorFunction == 1){
		*heartRate = *heartRate | (1 << 0);
	}

	if(heartrate < 50 || heartrate > 165){
		//set bit 2 to signal abnormal heart rate
		*heartRate = *heartRate | (1 << 2);
		
		if(heartrate > 165){
			//set bit 12 to signal high heart rate
			*heartRate = *heartRate | (1 << 12);
		}else{
			//set both bits 11 and 12 to signal low heart rate
			*heartRate = *heartRate | (1 << 12);
			*heartRate = *heartRate | (1 << 11);
		}
	}

	//sets the heartrate to bits 3-10
	for(int i = 0; i < 8; i++){
		//get bit i from heartrate
		int currentBit = (heartrate & (1 << i)) >> i;
		//if it is 1, set bit i+3 in heartRate
		if(currentBit){
			*heartRate = *heartRate | (1 << (i+3));	
		}
	}
	//sets the parity
	if(computeParityBitShort(*heartRate)){
		*heartRate = *heartRate | (1 << 15);
	}
	return(0);
}



/***********************************************************************************/
/* purpose: prepares the blood pressure data

input:
sensorFunction - contains the state of the sensor
systolicPressure - contains the systolic pressure
diastolicPressure - contains the diastolic pressure

output:
bloodPressure - stores the raw bloodPressure data

return:
0  request was completed correctly
1  illegal input

*/

int prepareBloodPressure(int sensorFunction, int systolicPressure, int diastolicPressure, int* bloodPressure)
{

	//sets bits of bloodPressure to 0
	*bloodPressure = 0;

	//checks if values are within acceptable bounds
	if(sensorFunction < 0 || sensorFunction > 1 || diastolicPressure < 0 || diastolicPressure > 255 || systolicPressure < 0 || systolicPressure > 255){
	        printf("prepareBloodPressure - illegal input");
		return(1);
	}
	
	//if sensor function is 1, set bit 0 to signal incorrect reading
	if(sensorFunction == 1){
		*bloodPressure = *bloodPressure | (1 << 0);
	}
	
	//checks for abnormal blood pressure
	if(systolicPressure <= 100 || diastolicPressure <= 75){
		//low blood presure; set to 1
		*bloodPressure = *bloodPressure | (1 << 19);

	}else if(systolicPressure >= 130 || diastolicPressure >= 100){
		//high blood pressure; set to 2
		*bloodPressure = *bloodPressure | (1 << 20);
	}else if(systolicPressure >= 170 ||diastolicPressure < 55){
		//medical attention required; set to 3
		*bloodPressure = *bloodPressure | (1 << 19);
		*bloodPressure = *bloodPressure | (1 << 20);
	}

	//sets the diastolic pressure to bits 3-10
	for(int i = 0; i < 8; i++){
		//get bit i from diastolicPressure
		int currentBit = (diastolicPressure & (1 << i)) >> i;
		//if it is 1, set bit i+3 in bloodPressure
		if(currentBit){
			*bloodPressure = *bloodPressure | (1 << (i+3));	
		}
	}
	//sets the systolic pressure to bits 11-18
	for(int i = 0; i < 8; i++){
		int currentBit = (systolicPressure & (1 << i)) >> i;
		//if it is 1, set the bit i+11 in bloodPressure
		if(currentBit){
			*bloodPressure = *bloodPressure | (1 << (i+11));
		}
	}


	//sets the parity bit
	if(computeParityBitInt(*bloodPressure)){
		*bloodPressure = *bloodPressure | (1 << 31);
	}

	return(0);
}



