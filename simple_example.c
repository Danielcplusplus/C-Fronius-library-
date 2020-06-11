#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Fronius.h"
double powersum = 0.0;
int main()
{
	powersum = get_solar_power("YOUR_IP_ADDRESS");//"get_solar_power returns the produced/used power as a double
	if(powersum < 1){
		get_request_without("REPLACE_THIS_WITH_AN_URL_TO_MAKE_A_GET_REQUEST_TO");//This line runs a get request to an url(for example ifttt) and ignores the feedback
		printf("%lf W are beeing fed in to the grid",fabs(powersum));
	}
	else if(powersum > 1){
		get_request_without("REPLACE_THIS_WITH_AN_URL_TO_MAKE_A_GET_REQUEST_TO");//This line runs a get request to an url(for example ifttt) and ignores the feedback
		printf("%lf W are beeing used from the Grid",fabs(powersum));
	}
	
}
