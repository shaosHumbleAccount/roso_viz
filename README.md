roso_viz
========

A Visualization tool designed for RoboSoccor Lab of Technische Universität München (TUM). 
See more at http://www.rcs.ei.tum.de/en/Lehre/Labs/pr_rs/.

How to Build
-------------------------------
The simplest way is to use Qt Creator, load roso_viz.pro, and click Run.


How to Use
-------------------------------
Roso_viz runs as an independent program. 

In your program, includes rosoviz.h which can be found in quick_start\, and add
"QT += network" into your .pro file.   
Then follow the instruction found in that header file (rosoviz.h). Project roso_example is also a good reference.  

Very easy to use, I promise:)


More on how to Use
-------------------------------
1. Please make sure that the rosoviz.ini file in placed in the same directory as the executable.
2. Roso_viz and your program could be run on different computers, just change the IP address and port
defined in rosoviz.h and rosoviz.ini accordingly.
3. Only one Roso_viz will work if you start multiple instances, unless you set them to different ports.

Dependencies
-------------------------------
Roso_viz (not including the examples) is based purely on Qt (core, gui , and network).
