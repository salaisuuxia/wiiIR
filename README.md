wiiIR
=====

using a wii remote's IR sensor to control an arduino/ATMega

the project leverages libwiimote to communicate with the wii remote to gather the IR data.
this is averaged, then read out to stdout, allowing a separate script to parse the data and pass it onto the serial device.


to use: 

enter into the root directory and use 'make' to build the wiiIR.c into an executable.
an executable is already provided, but this isn't guaranteed to work on your platform.

it is highly recommended that you build the executable yourself.

once the executable has been built, enter into the 'bin' directory and run './wiiIR'
you can also either add the bin directory into your PATH environment variable, or copy the executable into a folder in your PATH.
