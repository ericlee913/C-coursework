
# C Coursework - Principles of Programming Module (COMP0002)

The coursework is to make a functioning robot that will search for the markers in the grid and will bring back the markers back to home position.
All the 6 stages have been completed.


![Alt text](<Screenshot 2023-11-14 061610.png>)


## Introduction

The grid comprises a standard 8x8 size, hosting 5 obstacles and 3 markers. Although in most cases, all obstacles and markers will be present, there are variations where obstacle numbers may be lower than 5, explained further below. The robot, indicated by the color blue, deploys an algorithm to navigate the grid, avoiding collisions with walls and obstacles. Upon reaching a marker, the robot transitions to a yellow color, signaling the initiation of the backtrack process. The robot retraces its steps to return home, depositing the marker and restarting the search if additional markers remain. The program concludes once all markers are found and returned home.

Obstacles and markers are randomly positioned in the grid each time the program runs. If obstacle coordinates overlap upon one another, it will lead to lower number of obstacle, leading to dynamic variations in obstacle counts, contributing to a more complex and engaging map. This is the reason why sometimes the starting number of obstacle is not always 5


## Files

The files in the folder is composed as below:

animation.c: Contains sequences for robot movements in various scenarios.
robot.c: Houses functions for robot movement, turning, and integers returning true under specific conditions.
obstacle.c: Includes integers returning true when robots encounter obstacles.
marker.c: Stores functions and integers related to markers.
drawing.c: Draws grid features, including the grid itself, robot, markers, etc.
coordinates.c: Manages functions and integers regarding the position/coordinates of map features (for eg.robots, obstacles).
all the above .c files' respective .h files.
definition.h where all the structs and enums for the objects,robot, directions and home are defined
main.c: Main function resides here.

## Algorithm

The robot employs a random algorithm with an 80% chance of executing the forward function and a 10% chance each for left or right functions. When facing an obstacle or grid wall, the robot executes a left turn to navigate. Backtracking relies on a 2D array storing movements during marker searches, ensuring an exact retracing of the previous path.
## Algorithm

The robot employs a random algorithm with an 80% chance of executing the forward function and a 10% chance each for left or right functions. When facing an obstacle or grid wall, the robot executes a left turn to navigate. Backtracking relies on a 2D array storing movements during marker searches, ensuring an exact retracing of the previous path.
## Executing the file

First of all, in order to compile the program, in the terminal you have to input
"gcc -o [name of the executable file] main.c animation.c drawing.c graphics.c marker.c robot.c obstacle.c coordinates.c "
and in order to execute the program " ./[name of the executable file] [x-coordinate] [y-coordinate] [direction] | java -jar drawapp-3.0.jar "

** The possible x coordinate and the y coordinate input is between  1 to 8. This means that the input combination of x and y coordinate will determine the home of your robot with the top left hand corner coordinate being (1,1) and bottom right coordinate being (8,8). For example, if you input x coordinate =4, y coordinate =6 , starting position of your robot home will be in (4,6).