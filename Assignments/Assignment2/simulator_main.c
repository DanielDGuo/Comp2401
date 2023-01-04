/*

File simulator_main.c


Purpose: contains main() for testing the device API.



Revision:
a. Initial code - Doron Nussbaum
b. Completed code - Daniel Guo

*/


/************************************************************************/

// INCLUDE FILES

#include "stdio.h"
#include "stdlib.h"
#include "simulator.h"
#include "simulator_presentation_functions.h"
#include "simulator_prep_functions.h"


/************************************************************************/
//MACROS  / DEFINES






/************************************************************************/
// FUNCTION PROTOTYPES



int main(int argc, char* argv[])
{


	int rc;
	unsigned short heartRate;
	unsigned short temperature;
	unsigned int bloodPressure;
	int heartBPM;
	int sensorFunction;
	int systolicPressure, diastolicPressure;
	int i;

	initDevice();

	for (i = 0; i < 2; i++) {

		rc = getHeartRate(&heartRate);
		switch (rc) {
		case DEVICE_OK:
			// interpret ouptput data
			break;
		case DEVICE_ERROR:
			// print error message
			printf("Heart rate not avaialble deice error. Resetting device. \n");
			// reset the heart sensor;

			break;
		case DEVICE_NOT_INITIALIZED:
			printf("Device was not initialized.  Initializing the device. \n");
			initDevice();
			break;

		}

		rc = presentHeartRate(heartRate);
		// add code to ensure proper operation (see code above)
		switch (rc) {
		default:
			printf("in default option \n");
			break;

		}



		rc = getTemperature(&temperature);
		// add code to ensure proper operation (see code above)
		switch (rc) {
		default:
			printf("in default option \n");
			break;

		}

		rc = presentTemperature(temperature);
		// add code to ensure proper operation (see code above)
		switch (rc) {
		default:
			printf("in default option \n");
			break;

		}


		rc = getBloodPressure(&bloodPressure);
		// add code to ensure proper operation (see code above)
		switch (rc) {
		default:
			printf("in default option \n");
			break;

		}

		rc = presentTemperature(temperature);
		// add code to ensure proper operation (see code above)
		switch (rc) {
		default:
			printf("in default option \n");
			break;

		}
	}

	printf("Testing Heart Rate Prep Function \n");
	heartBPM = 54;
	sensorFunction = 0;
	rc = prepareHeartRate(heartBPM, sensorFunction, &heartRate);

	rc = presentHeartRate(heartRate);

	
	printf("Testing Blood Pressure Prep Function \n");
	sensorFunction = 0;
	systolicPressure = 128;
	diastolicPressure = 78;
	rc = prepareBloodPressure(sensorFunction, systolicPressure, diastolicPressure, &bloodPressure);
	rc = presentBloodPressure(bloodPressure);

}



