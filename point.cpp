#include "point.h"

Point::Point(){
    this->x=0;
    this->y=0;
}

Point::Point(int x, int y){
    this->x=x;
    this->y=y;
}

int Point::getXPos(){
    return x;
}


int Point::getYPos(){
    return y;
}


void Point::setXPos(int x){
    this->x=x;
}


void Point::setYPos(int y){
    this->y=y;
}
