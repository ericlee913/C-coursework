#include <string.h>
#include "robot.h"
#include <stdbool.h>
#include <stdlib.h>

const int moveDistance = 100;

//this inteager returns true when it faces a wall
int canmoveforward(Robot* robot){
    if ((robot -> dir == south && robot -> y == 850) || (robot -> dir == west && robot -> x == 150) || (robot -> dir == north && robot -> y == 150) || (robot -> dir == east && robot -> x == 850)){
        return false;
    }
    else {
        return true;
    }
}

//this inteager returns true when robot's coordinate is the same as marker's
int atMarker(Marker* marker , Robot* robot){
    if ((robot->x == marker -> x && robot -> y == marker -> y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//this inteager returns true when robot's coordinate is the same as one of the three markers
int atANYmarker(Marker* marker1, Marker* marker2, Marker* marker3, Robot* robot){
    if (atMarker(marker1,robot)==true || atMarker(marker2,robot)==true || atMarker(marker3,robot)==true )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//this inteager returns true when robot's coordinates is the same as home coordinates
int atHome(Robot* robot, Home* home) {
    if(robot->x == home->x && robot->y == home->y)
    {
        return true;
    }
    else
    {
        return false;
    }
} 

//this function rotates the robot anticlockwise by 90 degrees
void left(Robot* robot){
    robot->dir -= 1;
    robot ->dir%=4;
    strcpy(robot -> movement[robot -> numMovement] , "left");
    robot -> numMovement += 1;   
}

//this function rotates the robot clockwise by 90 degrees
void right(Robot* robot){
    robot-> dir += 1;
    robot -> dir %=4;
    strcpy(robot -> movement[robot -> numMovement] , "right");
    robot -> numMovement += 1;
}

//this function rotates the robot anticlockwise by 90 degrees but is only used for backtracking, as this does not store a string into the 2d array(movement) in robot struct
void left_backtrack(Robot* robot){
    robot-> dir -= 1;
    robot -> dir %=4;
}

//this function rotates the robot clockwise by 90 degrees but is only used for backtracking, as this does not store a string into the 2d array(movement) in robot struct
void right_backtrack(Robot* robot){
    robot-> dir += 1;
    robot -> dir %=4;
}

//this function moves the robot forward according to its enum direction in the robot struct
void forward(Robot* robot){
    if (robot -> dir == north){
        robot -> y -= moveDistance;
    }
    else if (robot -> dir == east){
        robot -> x += moveDistance;
    }
    else if (robot -> dir == west){
        robot -> x -= moveDistance; 
    }
    else if (robot -> dir == south){
        robot -> y += moveDistance;
    }
    strcpy(robot -> movement[robot -> numMovement] , "forward");
    robot -> numMovement += 1;
}

//this function moves the robot forward according to its enum direction in the robot struct 
//but is only used for backtracking, as this does not store a string into the 2d array(movement) in robot struct
void forward_backtrack(Robot* robot){
    if (robot -> dir == north){
        robot -> y -= moveDistance;
    }
    else if (robot -> dir == east){
        robot -> x += moveDistance;
    }
    else if (robot -> dir == west){
        robot -> x -= moveDistance; 
    }
    else if (robot -> dir == south){
        robot -> y += moveDistance;
    }
}

//this function will randomlymove the robot left right or forward
//It has 80% chance of moving forward 10% chance turning left 10% chance turning right
void randommove(Robot*robot){
        int randomdigit = rand() %100;
        if (randomdigit <= 80 ) {
            forward(robot);
        } 
        else if (randomdigit <= 90) {
            left(robot);
        } 
        else {
            right(robot);
        }
}
