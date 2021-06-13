
                                
                         #include <string.h>
#include <stdio.h>
#include <stdlib.h>


extern char GPSM[150]; //to save GPS message
extern char *data[15]; //to save the line that have the coordinate 
extern int dataLength; //global variable that will be used to check gps fix
int i;           // iterator on the cutting line

void splitLine() {

  dataLength = 0;
	data[0] = strtok(GPSM, ",");
  while (data[dataLength] != NULL && dataLength < 14) {
		dataLength++;
    data[dataLength] = strtok(NULL, ",");
  }
}

void GetLineHaveCoordinates() {
  GPSM[0] = '$';
  GPSM[1] = 'G';
  GPSM[2] = 'P';
  GPSM[3] = 'G';
  GPSM[4] = 'G';
  GPSM[5] = 'A';
  while (1) {
		char c = readUART1();
    i = 6;
    if (c == '$') {
        c = readUART1();
        if (c == 'G') {
            c = readUART1();
            if (c == 'P') {
                c = readUART1();
                if (c == 'G') {
                    c = readUART1();
                    if (c == 'G') {
                        c = readUART1();
                        if (c == 'A') {
													c = readUART1();
                            while (c != '\n') {
															GPSM[i] = c;
                              i++;
															c = readUART1();
                            }
                            break;
                        }}}}}}}}

												
double getLatitude() { return atof(data[2]); }

double getLongitude() { return atof(data[4]); }

int isOk() {
    
  if (*data[6] <= '0') {
      
    return 0;
      
  } else if ('1' <= *data[6] && *data[6] <= '5') {
      
    return 1;
      
  } else {      
    return 0;
  }
}      
