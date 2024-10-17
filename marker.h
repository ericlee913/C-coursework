#ifndef MARKER_H
#define MARKER_H
#include "definition.h"
#include "robot.h"

void pickUpMarker(Marker* marker, Robot*robot);
void tryPickupMarker(Marker*marker1, Marker*marker2,Marker*marker3,Robot* robot);
void dropMarker(Robot* robot, Marker* marker, Home* home);
void trydropMarker(Marker*marker1, Marker*marker2,Marker*marker3,Robot* robot, Home* home);
int isCarryingAMarker(Marker* marker);
int isCarryinganyMarker(Marker* marker, Marker* marker2, Marker* marker3);

#endif