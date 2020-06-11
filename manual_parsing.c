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
