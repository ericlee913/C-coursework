#ifndef DEFINITION_H
#define DEFINITION_H

//this is where all the structs and enums are defined

typedef enum {north,east,south,west} direction;
typedef struct {
    int x;
    int y;
    direction dir;
    char movement[10000][10];
    int numMovement;
    int markercounter;
} Robot;

typedef struct {
    int x;
    int y;
} Marker;

typedef struct {
    int x;
    int y;
} Obstacle;

typedef struct {
    int x;
    int y;
} Home;


#endif