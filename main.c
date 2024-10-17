#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "animation.h"
#include "definition.h"
#include "graphics.h"
#include "robot.h"
#include "coordinates.h"


const int width = 1000;
const int height = 1000;


int main(int argc, char **argv)
{
    int initialX = 6;
    int initialY = 5;
    char *initialDirection = "north"; 
    if (argc == 4) // Four arguments were typed
    {
    initialX = atoi(argv[1]); 
    initialY = atoi(argv[2]); 
    initialDirection = argv[3]; 
    }
    srand(time(NULL));
    setWindowSize(width,height);
    Robot myrobot;
    Home myhome;
    Marker mymarker1,mymarker2,mymarker3;
    Obstacle myobstacle1,myobstacle2,myobstacle3,myobstacle4,myobstacle5;
    robot_coordinate_setter(initialX,initialY,initialDirection, &myrobot);
    home_coordinate_setter(initialX,initialY, &myhome);
    allcoordinates(&mymarker1,&mymarker2,&mymarker3,&myobstacle1,&myobstacle2,&myobstacle3,&myobstacle4,&myobstacle5);
    //the loop will continue until all the markers have distinct coordinate from home and one another and obstacles have distinct coordinate from home and markers
    while (overlapping_coordinates(&mymarker1,&mymarker2,&mymarker3,&myobstacle1,&myobstacle3,&myobstacle3,&myobstacle4,&myobstacle5,&myhome)){
        allcoordinates(&mymarker1,&mymarker2,&mymarker3,&myobstacle1,&myobstacle2,&myobstacle3,&myobstacle4,&myobstacle5);
    }
    // the loop will only terminate when the number of markers left is 0
    while (myrobot.markercounter >0){
        animation(&myrobot, &mymarker1 , &myhome, &mymarker2, &mymarker3, &myobstacle1, &myobstacle2,&myobstacle3,&myobstacle4,&myobstacle5);
    }
}       