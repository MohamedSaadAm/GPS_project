#include <math.h>
#define rad(x) x*(3.14159/180)
#define DDM_to_DD(x) (int)(x / 100) + ((x - ((int)(x / 100)) * 100) / 60)

double Latdiff, Longdiff, under_sqrt, flt_sqrt, distance;
int EarthDiameter = 2 * 6371000;

double CalcDistance(double latatude1, double longatute1, double latatude2, double longatute2) 
{
	// converting DDM into DD
	latatude1 = DDM_to_DD(latatude1), longatute1 = DDM_to_DD(longatute1);
	latatude2 = DDM_to_DD(latatude2), longatute2 = DDM_to_DD(longatute2);

	// converting from degrees into radian
	latatude1 = rad(latatude1), longatute1 = rad(longatute1);
	latatude2 = rad(latatude2), longatute2 = rad(longatute2);

	// implementing Haversine 
	Latdiff = latatude2 - latatude1;
	Longdiff = longatute2 - longatute1;
	under_sqrt = pow(sin(Latdiff / 2), 2) + cos(latatude1)*cos(latatude2)*pow(sin(Longdiff / 2), 2);
	flt_sqrt = sqrtf(under_sqrt);
	distance = EarthDiameter * asinf(flt_sqrt);

	return distance;
}
