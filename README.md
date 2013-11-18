roso_viz
========

A Visualization tool designed for RoboSoccor Lab of Technische Universität München (TUM). 
See more at http://www.rcs.ei.tum.de/en/Lehre/Labs/pr_rs/.

How to compile
In the repository are two Qt projects, can be compiled using QtCreator out of the box.
Or just use the compiled executable.

How to use
Roso_viz runs as an independent program.
And In your program, includes rosoviz.h which can be found in roso_test\, and add
"QT += network" into the .pro file. 
Then follow the instruction found in that header file. Very easy to use:)


This program (not including tests) is based purely on Qt (core, gui , network).
