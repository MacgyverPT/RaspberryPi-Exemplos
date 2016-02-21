/*
 * TUX CROSSING:
 * 
 * dsada
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

//our lamps (using wiringPi pin numbers)
#define RED		0
#define YELLOW	1
#define GREEN	2
#define RED_MAN	3
#define GREEN_MAN	4
#define BUTTON	5 //input button


/*
 * Setup: Program de GPIO correctly and initialise the lamps
 */
void setup(void){
	int i;
	
	if(geteuid() != 0){
		fprintf(stderr, "tuxx: Need to be root to run (sudo?)\n");
		exit(0);
	}
	
	if(wiringPiSetup() == -1)
		exit(1);
	
	printf("Setup...") ; fflush(stdout);
	for(i = 0; i < 5; i++){
		pinMode(i, OUTPUT);
		digitalWrite(i, 0);
	}
	digitalWrite(GREEN, 1);
	digitalWrite(RED_MAN, 1);
	pinMode(BUTTON, INPUT);
	
	printf("OK\n");
}


/*
 * WaitButton:
 * 	wait for the btton to be pressed. Because we have the GPIO pin pulled high, we wait for it to go low to indicate a push
 */
void waitButton(void){
	printf("Waiting for button..."); fflush(stdout);
	
	while(digitalRead (BUTTON) = HIGH)
		delay(10)
	
	printf("Got it\n");
}


/*
 * stopTraffic: Cycle the traffic lights from Green to Red
 */
 void stopTraffic(){
	 printf("Stopping traffic..."); fflush(stdout);
	 
	 digitalWrite(GREEN, 0);
	 digitalWrite(YELLOW, 1);
	 delay(2000);
	 digitalWrite(YELLOW, 0);
	 digitalWrite(RED, 1);
	 delay(2000);
	 printf("Stopped\n");
}


/*
 * Walk:
 * 	Signal the red/green man to walk and when time is up
 * 	Start the traffic light sequence to let the traffic move again
 */
 void walk(){
	 printf("Walk now... "); fflush(stdout);
	 
	 digitalWrite(RED_MAN, 0);
	 digitalWrite(GREEN_MAN, 1);
	 delay(1000);
	 digitalWrite(RED, 0);
	 digitalWrite(YELLOW, 1);
	 
	 printf("Walked\n");
}


/*
 * graceTime:
 * 	This is the time when the green man is flashing, and the yellow
 * 	traffic light is also flashing - to signal to pedestrians to not
 * 	start the cross and to drivers that they can move on if the
 * 	crossing is clear.
 */
 











