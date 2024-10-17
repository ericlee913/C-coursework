#include "drawing.h"
#include <stdbool.h>
#include "marker.h"
#include "graphics.h"

//this function draws the grid of the map
void drawGrid(){ 
    background();
    for (int i=100;i<=900;i+=100){
        drawLine(100,i,900,i);
    }
    for (int j =100;j<=900;j+=100){
        drawLine(j,100,j,900);
    }
}

//this function plots the coordinates needed for the home and draws it
void createhome (Home* home){  
    foreground();
    setColour(gray);
    int home_x[4] = {home -> x - 50 , home -> x - 50 , home -> x +50, home -> x + 50};
    int home_y[4] = {home -> y - 50, home -> y + 50 , home -> y +50, home -> y - 50};
    fillPolygon(4,home_x,home_y);
}

//this function plots the coordinates needed for the markers and draws it
void drawingMarker (Marker* marker) 
{
    foreground();
    setColour(yellow);
    int marker_x[4] = {marker -> x - 50 , marker -> x - 50 , marker -> x +50, marker -> x + 50};
    int marker_y[4] = {marker -> y - 50, marker -> y + 50 , marker -> y +50, marker -> y - 50};
    fillPolygon(4,marker_x,marker_y);
}

//this function draws all the 3 markers 
void createmarkers (Marker* marker1, Marker* marker2, Marker* marker3){
    drawingMarker(marker1);
    drawingMarker(marker2);
    drawingMarker(marker3);
}

//this function plots the coordinates needed for the obstacles and draws it
void drawingObstacle (Obstacle* obstacle)
{
    foreground();
    setColour(red);
    int obstacle_x[4] = {obstacle -> x - 50 , obstacle -> x - 50 , obstacle -> x +50, obstacle -> x + 50};
    int obstacle_y[4] = {obstacle -> y - 50, obstacle -> y + 50 , obstacle -> y +50, obstacle -> y - 50};
    fillPolygon(4,obstacle_x,obstacle_y);
}

//this function draws all the 5 obstacles
void createObstacles( Obstacle*obstacle1, Obstacle* obstacle2, Obstacle* obstacle3 , Obstacle* obstacle4, Obstacle* obstacle5){
    drawingObstacle(obstacle1);
    drawingObstacle(obstacle2);
    drawingObstacle(obstacle3);
    drawingObstacle(obstacle4);
    drawingObstacle(obstacle5);
}

//this function plots the coordinates needed for the robot and draws it, taking into account which direction it is facing
void drawrobot(Robot* robot , Marker*marker1 , Home* home, Marker*marker2, Marker* marker3){
    foreground();
    setColour(blue);
    if (isCarryinganyMarker(marker1,marker2,marker3) == true) {
        setColour(yellow);
    }
    if (robot -> dir == north){
        int robot_x[3] = {robot -> x - 50 , robot -> x + 50 , robot -> x};
        int robot_y[3] = {robot -> y + 50, robot -> y +50 , robot -> y -50};
        fillPolygon(3,robot_x,robot_y);
    }
    else if (robot -> dir == east){
        int robot_x[3] = {robot -> x -50 , robot -> x -50 , robot -> x+50};
        int robot_y[3] = {robot -> y -50, robot -> y +50 , robot -> y};
        fillPolygon(3,robot_x,robot_y);
    }
    else if (robot -> dir == west){
        int robot_x[3] = {robot -> x +50 , robot -> x +50 , robot -> x-50};
        int robot_y[3] = {robot -> y +50, robot -> y -50 , robot -> y}; 
        fillPolygon(3,robot_x,robot_y);
    }
    else if (robot -> dir == south){
        int robot_x[3] = {robot -> x -50 , robot -> x +50 , robot -> x};
        int robot_y[3] = {robot -> y -50, robot -> y -50 , robot -> y +50};
        fillPolygon(3,robot_x,robot_y);
    }  
}

