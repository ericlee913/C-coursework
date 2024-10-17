#include "marker.h"
#include <stdbool.h>
#include <string.h>

const int Invalid_marker_position = -100;
const int removed = -500;

//when marker is picked up , the marker is transffered into a specific position outside the grid called Invalid_marker_position
void pickUpMarker(Marker* marker, Robot* robot) {
    if (atMarker(marker,robot) == true && isCarryingAMarker(marker) == false){
    marker->x = Invalid_marker_position;
    marker->y = Invalid_marker_position;}
}

//whenever this function is used, it will try to pick up any of the three markers that can be below the robot
void tryPickupMarker(Marker*marker1, Marker*marker2,Marker*marker3,Robot* robot)
{
    pickUpMarker(marker1,robot);
    pickUpMarker(marker2,robot);
    pickUpMarker(marker3,robot);
}

//when this function is used the marker is transferred into a specific position called removed and this causes the markercoungter to decrease by 1
//it also empties the 2d array that stores the movements
void dropMarker(Robot* robot,Marker* marker,Home*home){
    if (isCarryingAMarker(marker) == true && atHome(robot,home) == true){
    marker->x = removed;
    marker->y = removed;
    robot -> markercounter-- ;
    robot -> numMovement =0;
    for (int i=0; i<10000; i++){
        strcpy(robot-> movement[i],"");
    }
    }
}

//whenever this function is used, it will try to drop any of the three markers it has been carrying, in case it reaches home when backtracking
void trydropMarker(Marker*marker1, Marker*marker2,Marker*marker3,Robot* robot, Home* home){
    dropMarker(robot,marker1,home);
    dropMarker(robot,marker2,home);
    dropMarker(robot,marker3,home);
}

//whenever the marker is picked, the inteager will return true until it drops off the marker
int isCarryingAMarker(Marker* marker) {
    if ((marker->x == Invalid_marker_position&& marker->y == Invalid_marker_position))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//this inteager will return true if one of any of the three markers is picked up and not dropped off yet
int isCarryinganyMarker( Marker* marker1, Marker* marker2 , Marker* marker3)
{
    if (isCarryingAMarker(marker1) == true || isCarryingAMarker(marker2) == true || isCarryingAMarker(marker3) == true){
        return true;
    }
    else{
        return false;
    }
}

