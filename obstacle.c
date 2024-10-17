#include "obstacle.h"
#include "stdbool.h"

//this inteager returns true if the robot is facing an obstacle
int obstacleinfront(Obstacle* obstacle, Robot*robot)
{ 
    int proxmityrange =100;
    if ((obstacle -> x - robot-> x  == proxmityrange && obstacle ->y == robot-> y && robot -> dir == east) || 
    (obstacle ->y - robot-> y == proxmityrange &&  obstacle ->x == robot-> x && robot -> dir == south) ||
    (obstacle ->x - robot-> x == -proxmityrange && obstacle ->y == robot-> y && robot -> dir == west) ||
    (obstacle ->y - robot-> y == -proxmityrange && obstacle ->x == robot-> x && robot -> dir == north)){
        return true;
    }
    else{
        return false;
    }
}

//if there are any one of the 5 obstacles infront of the robot, this inteager returns true
int anyobstacleinfront(Obstacle* obstacle1 , Obstacle* obstacle2, Obstacle* obstacle3, Obstacle* obstacle4, Obstacle* obstacle5, Robot*robot)
{
    if (obstacleinfront(obstacle1,robot) ||
    obstacleinfront(obstacle2,robot) || 
    obstacleinfront(obstacle3,robot) ||
    obstacleinfront(obstacle4,robot) ||
    obstacleinfront(obstacle5,robot))
    {
        return true;
    }
}