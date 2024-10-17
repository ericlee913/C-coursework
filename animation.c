#include "graphics.h"
#include <stdbool.h>
#include <string.h>
#include "animation.h"
#include "robot.h"
#include "marker.h"
#include "drawing.h"
#include "obstacle.h"

const int waittime=100;

//this function clears and draws the map features like obstacles,the grid,home and markers
void drawmapfeatures(Home* home, Obstacle* obstacle1, Obstacle* obstacle2, Obstacle* obstacle3, Obstacle* obstacle4, Obstacle* obstacle5,Marker* marker1, Marker* marker2, Marker* marker3) 
{  
    sleep(waittime);
    clear();
    drawGrid();
    createhome(home);
    createObstacles(obstacle1,obstacle2,obstacle3,obstacle4,obstacle5);
    createmarkers(marker1,marker2,marker3);
}

//this function makes the robot go back to home, after picking up a marker
void backtrack(Robot* robot, Home* home, Marker* marker1, Marker* marker2, Marker* marker3,  Obstacle*obstacle1, Obstacle* obstacle2, Obstacle* obstacle3, Obstacle* obstacle4, Obstacle* obstacle5) 
{
    //the robot turns right twice before it starts to backtrack to follow back its path
    right_backtrack(robot);
    right_backtrack(robot);
    for (int i = robot->numMovement ; i >=0 ; i--){
        drawmapfeatures(home,obstacle1, obstacle2,obstacle3,obstacle4,obstacle5, marker1,marker2,marker3);
        if(atHome(robot,home))
        {
            //the loop will terminate if it reaches home whie backtracking and drops the marker
            trydropMarker(marker1,marker2,marker3,robot,home);
            i = -1;
        }
        if (strcmp(robot -> movement[i], "forward") == 0){
            forward_backtrack(robot);
        }
        else if (strcmp(robot -> movement[i], "left") == 0){
            right_backtrack(robot);
        }
        else if (strcmp(robot -> movement[i], "right") == 0){
            left_backtrack(robot);
        }
        drawrobot(robot,marker1,home,marker2,marker3);
        trydropMarker(marker1,marker2,marker3,robot,home);
    }

}


//this function faciliates the overall animation of the robot including finding marker and backtracking after it picks up the marker
void animation(Robot*robot , Marker* marker1, Home*home , Marker* marker2 , Marker* marker3, Obstacle* obstacle1, Obstacle* obstacle2, Obstacle* obstacle3, Obstacle* obstacle4, Obstacle* obstacle5){ 
    tryPickupMarker(marker1,marker2,marker3,robot);
    trydropMarker(marker1,marker2,marker3,robot,home);
    //this loop occurs when no obstacles are faced and it has not reached a marker yet
    while (atANYmarker(marker1,marker2,marker3,robot) == false && isCarryinganyMarker(marker1,marker2,marker3) == false && anyobstacleinfront(obstacle1,obstacle2,obstacle3,obstacle4,obstacle5,robot) == false){
        drawmapfeatures(home,obstacle1,obstacle2,obstacle3,obstacle4,obstacle5,marker1,marker2,marker3);
        if (canmoveforward(robot)){
            //if there are no walls infront , it will execute the randommove function
            randommove(robot);
        }
        else{
            //if the robot faces a wall it will turn left once
            left(robot);
        }
        drawrobot(robot,marker1, home,marker2,marker3); 
    }
    if (isCarryinganyMarker(marker1,marker2,marker3) == true){
        backtrack(robot, home , marker1, marker2,marker3,obstacle1,obstacle2,obstacle3,obstacle4,obstacle5);
    }
    //if there is an obstacle infront the robot will turn left once
    if (anyobstacleinfront(obstacle1,obstacle2,obstacle3,obstacle4,obstacle5,robot) == true){
        left(robot);;
    }
}