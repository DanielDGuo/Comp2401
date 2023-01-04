// file is simulator.h

/* This file contains the functions prototypes and other related data required to interacting with the 
wearable device. 


Revisions:
Who		When		What 
----------------------------------
DN		9/9/2022	initial version */




/***************************************************************/

/* DEFINE */

#define DEVICE_OK 0
#define DEVICE_ERROR 1
#define DEVICE_NOT_INITIALIZED 2


/*************************************************************/
/* prototypes*/
int initDevice();
int resetDevice(unsigned short resetRequest);
int getHeartRate(unsigned short* heartRate);
int getTemperature(unsigned short* temperature);
int getBloodPressure(unsigned int* bloodPressure);

