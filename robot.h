#ifndef ACTION_H
#define ACTION_H
#include "definition.h"

int canmoveforward(Robot* robot);
int atHome(Robot* robot, Home* home) ;
int atMarker(Marker* marker , Robot* robot );
int atANYmarker(Marker* marker1, Marker* marker2, Marker* marker3, Robot* robot);
void left(Robot* robot);
void right(Robot* robot);
void right_backtrack(Robot* robot);
void left_backtrack(Robot* robot);
void forward(Robot* robot);
void forward_backtrack(Robot* robot);
void randommove(Robot*robot);

#endif