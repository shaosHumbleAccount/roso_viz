roso_viz
========

A Visualization tool designed for RoboSoccor Lab of Technische Universität München (TUM). 
See more at http://www.rcs.ei.tum.de/en/Lehre/Labs/pr_rs/.

How to Run
-------------------------------
The simplest way is to just use the executable in the quick_start\ folder (should work in the lab of TUM).  
It's also very easy to build by yourself.


How to Use
-------------------------------
Roso_viz runs as an independent program.  
And In your program, includes rosoviz.h which can be found in quick_start\, and add
"QT += network" into the .pro file.   
Then follow the instruction found in that header file (rosoviz.h). Very easy to use, I promise:)


More on how to Use
-------------------------------
1. Please make sure that the rosoviz.ini file in placed in the same directory as the executable.
2. Roso_viz and your program could be run on different computers, just change the IP address and port
defined in rosoviz.h and rosoviz.ini accordingly.


How to Build
-------------------------------
If you have problem running the pre-compiled executable, or wanna make some change (which is welcomed)
, you can build the projects yourself
In the repository are two Qt projects, which should be able to be compiled using QtCreator (a reasonably up-to-date version)
out of the box.

Dependencies
-------------------------------
Roso_viz (not including the examples) is based purely on Qt (core, gui , and network).
