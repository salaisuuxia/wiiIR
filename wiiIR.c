#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>

#include "wiimote.h"
#include "wiimote_api.h"

int main(int argc, char **argv)
{


	wiimote_t wiimote = WIIMOTE_INIT;
	
	if (argc < 2) {
		fprintf(stderr, "Usage: wiiIR BDADDR\n");
		exit(1);
	}
	
	printf(" Home - Exit\n\n");
	printf("Press buttons 1 and 2 on the wiimote now to connect.\n");
	
	/* Connect the wiimote specified on the command line. */
	
	if (wiimote_connect(&wiimote, argv[1]) < 0) {
		fprintf(stderr, "unable to open wiimote: %s\n", wiimote_get_error());
		exit(1);
	}



	while (wiimote_is_open(&wiimote)) {
		
		if (wiimote_update(&wiimote) < 0) {
			wiimote_disconnect(&wiimote);
			break;
		}
		
		if (wiimote.keys.home) {
			wiimote_disconnect(&wiimote);
		}
		
		if (wiimote.keys.bits & WIIMOTE_KEY_1) {
			/* This will activate the rumble feature on the next update.
			   The wiimote will rumble until the 'one' key is released. */		
			wiimote.rumble = 1;
		}
		else {
			/* Disable rumble on the next update. */ 
			wiimote.rumble = 0;
		}

			wiimote.mode.ir = 1;
			wiimote.mode.acc = 1;

		/* Change the LEDs on the wiimote when the plus and minus keys
		   are pressed. */


//		fprintf(stderr, "AXIS =%03d y=%03d z=%03d\n", 
//			wiimote.axis.x,
//			wiimote.axis.y,
//			wiimote.axis.z);

int xcoordinate=0;
int ycoordinate=0;
int blobcount=0;

if (wiimote.ir1.x < 1791)
{
xcoordinate=xcoordinate+wiimote.ir1.x;
ycoordinate=ycoordinate+wiimote.ir1.y;
blobcount++;
}

if (wiimote.ir2.x < 1791)
{
xcoordinate=xcoordinate+wiimote.ir2.x;
ycoordinate=ycoordinate+wiimote.ir2.y;
blobcount++;
}

if (wiimote.ir3.x < 1791)
{
xcoordinate=xcoordinate+wiimote.ir3.x;
ycoordinate=ycoordinate+wiimote.ir3.y;
blobcount++;
}

if (wiimote.ir4.x < 1791)
{
xcoordinate=xcoordinate+wiimote.ir4.x;
ycoordinate=ycoordinate+wiimote.ir4.y;
blobcount++;
}

if (blobcount > 1)
{
xcoordinate=(xcoordinate/blobcount);
ycoordinate=(ycoordinate/blobcount);
}




if ((xcoordinate > 0) && (xcoordinate < 256 )){

wiimote.led.one  = 1;
wiimote.led.two  = 0;
wiimote.led.three  = 0;
wiimote.led.four  = 0;

}else if ((xcoordinate >= 256) && (xcoordinate < 512)){

wiimote.led.one  = 1;
wiimote.led.two  = 1;
wiimote.led.three  = 0;
wiimote.led.four  = 0;

}else if ((xcoordinate >= 512) && (xcoordinate < 768)){

wiimote.led.one  = 0;
wiimote.led.two  = 1;
wiimote.led.three  = 0;
wiimote.led.four  = 0;

}else if ((xcoordinate >= 768)&&(xcoordinate < 1024)){

wiimote.led.one  = 0;
wiimote.led.two  = 1;
wiimote.led.three  = 1;
wiimote.led.four  = 0;

}else if ((xcoordinate >= 1024) && (xcoordinate < 1280)){

wiimote.led.one  = 0;
wiimote.led.two  = 0;
wiimote.led.three  = 1;
wiimote.led.four  = 0;

}else if ((xcoordinate >= 1280) && (xcoordinate < 1536)){

wiimote.led.one  = 0;
wiimote.led.two  = 0;
wiimote.led.three  = 1;
wiimote.led.four  = 1;

}else if (xcoordinate >= 1536){

wiimote.led.one  = 0;
wiimote.led.two  = 0;
wiimote.led.three  = 0;
wiimote.led.four  = 1;

}else{
wiimote.led.one  = 0;
wiimote.led.two  = 0;
wiimote.led.three  = 0;
wiimote.led.four  = 0;

}







fprintf(stderr, "x=%04d \ny=%04d \nc=%d\n",
	xcoordinate,
	ycoordinate,
	blobcount);
				
	}
	return 0;
}

