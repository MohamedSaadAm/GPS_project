#include <math.h>
#define rad(x) x*(3.14159/180)

unsigned int distanceBetweenTwoPoints_Harvesine(float lat_1, float long_1, float lat_2, float long_2)
{ 
	// converting Coordinates degree values into radian
	float rad_lat_1 = rad(lat_1) , rad_lat_2 = rad(lat_2);
	float rad_long_1 = rad(long_1) , rad_long_2 = rad(long_2);


	int D_EarthDiameter = 2 * 6371000;
	float lat_diff = rad_lat_2 - rad_lat_1;
	float long_diff = rad_long_2 - rad_long_1;
	float under_sqrt = pow(sin(lat_diff / 2), 2) + cos(rad_lat_1)*cos(rad_lat_2)*pow(sin(long_diff / 2), 2);
	float flt_sqrt = sqrtf(under_sqrt);
	float haversineDistance = D_EarthDiameter * asinf(flt_sqrt);

	return (int)(haversineDistance);
}
