#ifndef ROBOT_H
#define ROBOT_H
#include "definition.h"

void drawmapfeatures(Home* home, Obstacle* obstacle1 , Obstacle* obstacle2, Obstacle* obstacle3, Obstacle* obstacle4, Obstacle* obstacle5,Marker* marker1, Marker* marker2, Marker* marker3);
void backtrack(Robot* robot, Home* home, Marker* marker1, Marker* marker2, Marker* marker3,  Obstacle*obstacle1, Obstacle* obstacle2, Obstacle* obstacle3, Obstacle* obstacle4, Obstacle* obstacle5 );
void animation(Robot*robot , Marker* marker1, Home*home , Marker* marker2 , Marker* marker3, Obstacle* obstacle1, Obstacle* obstacle2, Obstacle* obstacle3, Obstacle* obstacle4, Obstacle* obstacle5 );


#endif 