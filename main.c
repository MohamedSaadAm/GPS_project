#include "tm4c123gh6pm.h"
#include <TM4C123.h>
#include <math.h>
#include <string.h>
#include "medhat.h"
#include "saad.h"
#include "abd elrahman.h"
#include "sayed.h"
#include "yousef.h"
#include "nader.h"

//Global variables
double Distance = 0;
double prevLat, prevLong, currentLat, currentLong;
char GPSM[150]; 
char *data[15]; 
int dataLength; 
int delay;
int distanceDifference;

void SystemInit() {
	SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));
}

int main () {
	//All initilizations
	initUART1();
	initportA();
	initportB();
	initportE();
	initportD();	
	initportF();
	turn_led_Red(); // test to make sure all initialization is fine
	GetLineHaveCoordinates(); 
	splitLine();
	turn_led_blue(); // test to make sure GPS is start taking input
	while (dataLength < 6) {  // to avoid segmentation fault
		GetLineHaveCoordinates();
	splitLine();
	}
	while (!isOk()) { 
		GetLineHaveCoordinates(); 
	splitLine();
		while (dataLength < 6) {  
			GetLineHaveCoordinates();
	splitLine();
		}
	}
	currentLat = getLatitude(); // current location
	currentLong = getLongitude();
	turn_led_Green(); //if green led is on this mean we start 
	distanceDifference = 0;
	while (1) {
		
		GetLineHaveCoordinates(); 
	splitLine();
		while (dataLength < 6) {  
			turn_led_Red();
			currentLat = getLatitude();
	currentLong = getLongitude();
		}
		while (!isOk()) {
			turn_led_Red();
			currentLat = getLatitude();
	currentLong = getLongitude();
			while (dataLength < 6) {  
				currentLat = getLatitude();
	currentLong = getLongitude();
			}
		}
		prevLat = currentLat;
		prevLong = currentLong;
		currentLat = getLatitude();
		currentLong = getLongitude();
		distanceDifference = CalcDistance(prevLat, prevLong, currentLat, currentLong);
		if(distanceDifference >= .01 )
		{
			Distance += distanceDifference; //updating distance

		}
		if(Distance >= 100)
		{
				turn_led_Red();

		}
		print_distance((int)Distance); //display the distance
		delay = 100;
		
		while (delay > 0) {
			delay--;
		}
	}
}

