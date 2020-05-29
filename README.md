# C-Fronius-library

Warning this project is in the alpha-phase, we take no responsibility for any damage caused to your devices!

This project, wich was created by me and mike-2x, aims to simplify the process of getting power-values from a Fronius-inverter in c, using the Fronius json api.


# Usage
To use this library, you need to first move the "Fronius.h"-file into your project folder and then include it in your project using #include "Fronius.h".

Then you can use the function get_solar_power to get the current power of your inverter. If you feed back power to your grid the number the function will return is negative. If you use power from the grid it is positive.
