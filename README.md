# The Neutralizer

The Neutralizer is a Windows only program that was developed for the Community Ecology Research Course given every year in spring by the Community and Ecology department.
With the program, the student can get a general grasp and idea of how the neutral model works.
 
## Background
The program is coded in C++/CLI, using standard Windows Forms (the interaction screen) in combination with a freeglut openGL implementation (the screen with the moving squares).
On the screen with the buttons, the user can adjust the values for the different parameters (exponential notation is preferred, to avoid problems with comma’s and language settings). After pressing start, the local community is simulated forward in time, as shown in the colored figure. Different colors represent different species.
 
## The model
At the beginning of the simulation, the meta-community is generated according to Hubbel 2001, with parameter theta (can be changed by user).
Depending on whether initial dominance is checked or not, the local community is populated with either a single species, or a random sample from the meta community
Every timestep, one individual is removed from the local community, and replaced by either:
Offspring from a neighbour from the local community, from with the dispersal radius
An immigrant from the meta community
After being replaced, the individual has the chance of speciating into a new species, according to the speciationrate.
The Size parameter indicates the length of one side of the square that forms the local community, the total number of individuals in the simulation is therefore equal to size^2
 
## Installation
Within the self-extracting winzip archive are included the following files:
The Neutralizer.exe
freeglut.dll
msvcp100.dll
msvcr100.dll
OPENGL32.dll
The *.exe file is the simulation itself, the *.dll files are for runtime support only. More advanced programmers could possibly statically link these dll’s to the program, but I have not been able to do this.
By default, all files are extracted to “D:/The Neutralizer/”, during installation this path can freely be changed.

USE THE PROGRAM AT YOUR OWN RISK AND RESPONSIBILITY

[Download link](http://www.thijsjanzen.nl/The%20Neutralizer%201.31.exe)


![](http://www.thijsjanzen.nl/wordpress/wp-content/uploads/2015/02/TheNeutralizerScreenShot-1.jpg)
