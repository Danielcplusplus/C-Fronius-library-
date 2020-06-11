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
char json[1100];
int main()
{
  get_ip_only("ENTER_THE_IP_OF_YOUR_INVERTER", json);     //Get the JSON and save it in the string
    char * value = parse(json, "Voltage_AC_Phase_2");    //Get the value of "Voltage_AC_Phase_2" from the JSON string
    double val_converted;                               //Create a variable for the converted value
    sscanf(value, "%lf", &val_converted);              //Convert string into double
    printf("Value: %lf", val_converted);              //Display the value    
}
