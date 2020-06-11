/* 
 * C Fronius library example
 * Copyright (c) 2020 Danielcplusplus and mike-2x.
 * DISCLAIMER: This project is not affiliated with, funded by, or in any way associated with Fronius International GmbH.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

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
