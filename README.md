# C-Fronius-library

Copyright (c) 2020 Danielcplusplus and mike-2x.

DISCLAIMER: This project is not affiliated with, funded by, or in any way associated with Fronius International GmbH.

WARNING: This project is still in the alpha phase and should NOT be relied upon! Also, please keep in mind that we take no responsibility whatsoever for any damage caused to your devices!

This project, wich was created by me and mike-2x, aims to simplify the process of getting power values from a Fronius inverter in C, using the Fronius JSON API.


# Usage
To use this library, you need to first move the "Fronius.h"-file into your project folder and then include it in your project using #include "Fronius.h".

Then you can use the function get_solar_power() to get the current power of your inverter. If you feed back power to your grid, the return value of the function is negative. If you use power from the grid it is positive.

If you need other values, you can also manually parse them using the function parse() (see examples for more informations)
