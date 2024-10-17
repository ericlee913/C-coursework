#ifndef DRAWING_H
#define DRAWING_H

#include "definition.h"


void drawGrid();
void createhome (Home* home);
void createmarkers (Marker* marker1, Marker* marker2, Marker* marker3);
void drawingObstacle( Obstacle*obstacle);
void createObstacles( Obstacle*obstacle1, Obstacle* obstacle2, Obstacle* obstacle3 , Obstacle* obstacle4, Obstacle* obstacle5);
void drawingMarker (Marker* marker);
void drawrobot(Robot* robot , Marker*marker1 , Home* home, Marker*marker2, Marker*marker3);


#endif 