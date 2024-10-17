#ifndef COORDINATES_H
#define COORDINATES_H
#include "definition.h"

int gridtocoordinate(int i);
void marker_coordinate_setter(int x, int y, Marker *marker);
void obstacle_coordinate_setter(int x, int y, Obstacle *obstacle);
void home_coordinate_setter(int x, int y, Home *home);
void robot_coordinate_setter(int x, int y, char* direction,Robot* robot);
int randomcoord();
void allcoordinates(Marker *marker1, Marker *marker2, Marker *marker3, Obstacle *obstacle1, Obstacle *obstacle2, Obstacle *obstacle3, Obstacle *obstacle4, Obstacle *obstacle5);
int comparecoordinate_obstacle (Obstacle*obstacle, Home*home, Marker*marker);
int comparecoordinate_markers (Marker* marker1, Marker*marker2);
int overlapping_coordinates (Marker *marker1, Marker *marker2, Marker *marker3, Obstacle *obstacle1, Obstacle *obstacle2, Obstacle *obstacle3, Obstacle *obstacle4, Obstacle *obstacle5, Home*home);


#endif