#include "math.h"
#include "Fronius.h"
double powersum = 0.0;
int main()
{
	powersum = get_solar_power("192.168.1.41");
	if(powersum < 1){
		get_request_without("Replace this text with a url you want to make a request to");
		printf("%lf W are beeing fed in to the grid",fabs(powersum));
	}
	else if(powersum > 1){
		get_request_without("Replace this text with a url you want to make a request to");
		printf("%lf W are beeing used from the Grid",fabs(powersum));
	}
	
}
