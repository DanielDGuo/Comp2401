

/* This program converts degrees in from Farnehit to Celsius */
/* Conversion from F to C is carried out using the following formula 
 * C = F-32;
 * C = C * 5/9;
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
   float degFarenheit = 0;
   float degCelsius = 0.0;

   // get the input 
   printf("Enter a Farenheit degree: ");
   scanf("%f",&degFarenheit);

   // convert to celsius 
   degCelsius = (degFarenheit -  32) * 5/9;

   // output 
   printf("%f Farenheit = %f Celsius \n",degFarenheit, degCelsius);
   return(0);
}

