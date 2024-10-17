#include "coordinates.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//this function converts grid position to coordinates on drawapp
int gridtocoordinate(int i){
    int I = i*100 +50;
    return I;
}

//this function will convert the marker's grid position eg(1,3) into coordinates on the drawapp
void marker_coordinate_setter(int x, int y, Marker *marker){
    marker->x = gridtocoordinate(x);
    marker->y = gridtocoordinate(y);
}

//this function will convert the obstacle's grid position eg(1,3) into coordinates on the drawapp
void obstacle_coordinate_setter(int x, int y, Obstacle *obstacle){
    obstacle->x = gridtocoordinate(x);
    obstacle->y = gridtocoordinate(y);
}

//this function will convert the home's grid position eg(1,3) into coordinates on the drawapp
void home_coordinate_setter(int x, int y, Home *home){
    home->x = gridtocoordinate(x);
    home->y = gridtocoordinate(y);
}

//this interager will convert direction into enum numbers used in direction struct in the robot struct
int convertDirectionToEnum(char* direction)
{
    if (strcmp(direction,"north") ==0){
        return 0;
    }
    else if (strcmp(direction,"east") ==0){
        return 1;
    }
    else if (strcmp(direction,"south") ==0){
        return 2;
    }
    else if (strcmp(direction,"west") ==0){
        return 3;
    }
}

//this function will convert the robot's grid position eg(1,3) into coordinates on the drawapp + declare its starting direction, and other variables
void robot_coordinate_setter(int x, int y, char* direction,Robot*robot){
    robot->x = gridtocoordinate(x);
    robot->y = gridtocoordinate(y);
    robot->dir = convertDirectionToEnum(direction);
    robot->numMovement = 0;
    robot->markercounter =3;

}

//this function will randomly choose a x, y grid position for your marker and obstacle position
int randomcoord()
{
    int random = (rand() % 8) + 1;
    return random;
}

//this function converts all the object(marker+obstacle) into cooridnates on java drawapp
void allcoordinates(Marker *marker1, Marker *marker2, Marker *marker3, Obstacle *obstacle1, Obstacle *obstacle2, Obstacle *obstacle3, Obstacle *obstacle4, Obstacle *obstacle5){
    marker_coordinate_setter(randomcoord(),randomcoord(),marker1);
    marker_coordinate_setter(randomcoord(),randomcoord(),marker2);
    marker_coordinate_setter(randomcoord(),randomcoord(),marker3);
    obstacle_coordinate_setter(randomcoord(),randomcoord(),obstacle1);
    obstacle_coordinate_setter(randomcoord(),randomcoord(),obstacle2);
    obstacle_coordinate_setter(randomcoord(),randomcoord(),obstacle3);
    obstacle_coordinate_setter(randomcoord(),randomcoord(),obstacle4);
    obstacle_coordinate_setter(randomcoord(),randomcoord(),obstacle5);
}

//this inteager will return true if obstacle overlaps with home or marker when it is first assigned the coordinates
int comparecoordinate_obstacle (Obstacle*obstacle, Home*home, Marker*marker)
{
    if ((obstacle->x == home->x & obstacle ->y == home ->y) || (obstacle->x == marker->x & obstacle ->y == marker ->y) || (marker->x == home->x & marker ->y == home ->y))
    {
        return true;
    }
    
}

//this inteager returns true if an assigned coordinate of a marker overlaps with other marker's coordinate
int comparecoordinate_markers (Marker* marker1, Marker*marker2)
{
    if ((marker1->x == marker2->x && marker1 ->y == marker2 ->y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//this inteager returns true if an obstacle is overlapping with home or marker, or if a marker is overlapping with home or other markers (not for obstacle over obstacle)
int overlapping_coordinates (Marker *marker1, Marker *marker2, Marker *marker3, Obstacle *obstacle1, Obstacle *obstacle2, Obstacle *obstacle3, Obstacle *obstacle4, Obstacle *obstacle5, Home*home)
{
    if (comparecoordinate_obstacle(obstacle1,home,marker1)|| comparecoordinate_obstacle(obstacle1,home,marker2) || 
    comparecoordinate_obstacle(obstacle1,home,marker3) ||comparecoordinate_obstacle(obstacle2,home,marker1)|| 
    comparecoordinate_obstacle(obstacle2,home,marker2) ||comparecoordinate_obstacle(obstacle2,home,marker3) || 
    comparecoordinate_obstacle(obstacle3,home,marker1) || comparecoordinate_obstacle(obstacle3,home,marker2) || 
    comparecoordinate_obstacle(obstacle3,home,marker3) ||comparecoordinate_obstacle(obstacle4,home,marker1)|| 
    comparecoordinate_obstacle(obstacle4,home,marker2) || comparecoordinate_obstacle(obstacle4,home,marker3) || 
    comparecoordinate_obstacle(obstacle5,home,marker1)|| comparecoordinate_obstacle(obstacle5,home,marker2) || comparecoordinate_obstacle(obstacle5,home,marker3) || 
    comparecoordinate_markers(marker1,marker2)||comparecoordinate_markers(marker1,marker3)||comparecoordinate_markers(marker2,marker3))
    {
        return true;
    }
}



