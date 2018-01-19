#include "mouse.h"

Mouse::Mouse()
{
    for(int i=0; i<16; i++){
        fill_n(mazeWeightInMemory[i],16,256);
    }

}

void Mouse::updatePosition(int posX, int posY){
    this->position.setXPos(posX);
    this->position.setYPos(posY);
}

int Mouse::getMousePositionX(){
    return position.getXPos();
}

int Mouse::getMousePositionY(){
    return position.getYPos();
}

void Mouse::setOnStart(Maze maze){
    this->position = Point(15,0);
    mazeWeightInMemory[15][0]=1;
    mazeInMemory.setCell(position.getXPos(),position.getYPos(),maze.getCell(position.getXPos(),position.getYPos()));
}

int Mouse::performStepToGoal(){
    if (this->roadQeek.empty()){
        return 0;
    }
    Point newPoint = this->roadQeek.front();
    this->roadQeek.pop();
    this->position.setXPos(newPoint.getXPos());
    this->position.setYPos(newPoint.getYPos());
    return 1;
}

void Mouse::calculateRoad(Point startPoint, Point endPoint){

    int minStartValue = mazeWeightInMemory[startPoint.getXPos()][startPoint.getYPos()];
    Point minStartPoint = startPoint;
    queue <Point> startQeek;

    int minEndValue = mazeWeightInMemory[endPoint.getXPos()][endPoint.getYPos()];
    Point minEndPoint= endPoint;
    stack <Point> endStack;

    while(minStartPoint.getXPos()!=minEndPoint.getXPos() || minStartPoint.getYPos()!=minEndPoint.getYPos()){
        if(mazeInMemory.checkDirection('N',minEndPoint.getXPos(),minEndPoint.getYPos()) && mazeWeightInMemory[minEndPoint.getXPos()-1][minEndPoint.getYPos()] == minEndValue-1){
           minEndValue = mazeWeightInMemory[minEndPoint.getXPos()-1][minEndPoint.getYPos()];
           minEndPoint = Point(minEndPoint.getXPos()-1,minEndPoint.getYPos());
           endStack.push(minEndPoint);
        }else if(mazeInMemory.checkDirection('E',minEndPoint.getXPos(),minEndPoint.getYPos()) && mazeWeightInMemory[minEndPoint.getXPos()][minEndPoint.getYPos()+1] == minEndValue-1){
           minEndValue = mazeWeightInMemory[minEndPoint.getXPos()][minEndPoint.getYPos()+1];
           minEndPoint = Point(minEndPoint.getXPos(),minEndPoint.getYPos()+1);
           endStack.push(minEndPoint);
        }else if(mazeInMemory.checkDirection('W',minEndPoint.getXPos(),minEndPoint.getYPos()) && mazeWeightInMemory[minEndPoint.getXPos()][minEndPoint.getYPos()-1] == minEndValue-1){
           minEndValue = mazeWeightInMemory[minEndPoint.getXPos()][minEndPoint.getYPos()-1];
           minEndPoint = Point(minEndPoint.getXPos(),minEndPoint.getYPos()-1);
           endStack.push(minEndPoint);
        }else if(mazeInMemory.checkDirection('S',minEndPoint.getXPos(),minEndPoint.getYPos()) && mazeWeightInMemory[minEndPoint.getXPos()+1][minEndPoint.getYPos()] == minEndValue-1){
           minEndValue = mazeWeightInMemory[minEndPoint.getXPos()+1][minEndPoint.getYPos()];
           minEndPoint = Point(minEndPoint.getXPos()+1,minEndPoint.getYPos());
           endStack.push(minEndPoint);
        }
        if(minStartPoint.getXPos()!=minEndPoint.getXPos() || minStartPoint.getYPos()!=minEndPoint.getYPos()){
            if(mazeInMemory.checkDirection('N',minStartPoint.getXPos(),minStartPoint.getYPos()) && mazeWeightInMemory[minStartPoint.getXPos()-1][minStartPoint.getYPos()] == minStartValue-1){
               minStartValue = mazeWeightInMemory[minStartPoint.getXPos()-1][minStartPoint.getYPos()];
               minStartPoint = Point(minStartPoint.getXPos()-1,minStartPoint.getYPos());
               startQeek.push(minStartPoint);
            }else if(mazeInMemory.checkDirection('E',minStartPoint.getXPos(),minStartPoint.getYPos()) && mazeWeightInMemory[minStartPoint.getXPos()][minStartPoint.getYPos()+1] == minStartValue-1){
               minStartValue = mazeWeightInMemory[minStartPoint.getXPos()][minStartPoint.getYPos()+1];
               minStartPoint = Point(minStartPoint.getXPos(),minStartPoint.getYPos()+1);
               startQeek.push(minStartPoint);
            }else if(mazeInMemory.checkDirection('W',minStartPoint.getXPos(),minStartPoint.getYPos()) && mazeWeightInMemory[minStartPoint.getXPos()][minStartPoint.getYPos()-1] == minStartValue-1){
               minStartValue = mazeWeightInMemory[minStartPoint.getXPos()][minStartPoint.getYPos()-1];
               minStartPoint = Point(minStartPoint.getXPos(),minStartPoint.getYPos()-1);
               startQeek.push(minStartPoint);
            }else if(mazeInMemory.checkDirection('S',minStartPoint.getXPos(),minStartPoint.getYPos()) && mazeWeightInMemory[minStartPoint.getXPos()+1][minStartPoint.getYPos()] == minStartValue-1){
               minStartValue = mazeWeightInMemory[minStartPoint.getXPos()+1][minStartPoint.getYPos()];
               minStartPoint = Point(minStartPoint.getXPos()+1,minStartPoint.getYPos());
               startQeek.push(minStartPoint);
            }
        }
    }
    if(!endStack.empty()){
        endStack.pop();//redundant point
    }
    while(!startQeek.empty()){
        roadQeek.push(startQeek.front());
        startQeek.pop();
    }
    while(!endStack.empty()){
        roadQeek.push(endStack.top());
        endStack.pop();
    }
    roadQeek.push(endPoint);
}

int Mouse::floodAlgorithmNextStep(Maze maze){
    if (!roadQeek.empty()){
        performStepToGoal();
        if(!roadQeek.empty())
            return 1;
    }
    int value = mazeWeightInMemory[position.getXPos()][position.getYPos()];

    if(mazeInMemory.checkDirection('N',position.getXPos(),position.getYPos()) && mazeWeightInMemory[position.getXPos()-1][position.getYPos()]==256){
        mazeWeightInMemory[position.getXPos()-1][position.getYPos()]=value+1;
        floodQeek.push(Point(position.getXPos()-1,position.getYPos()));
        mazeInMemory.setCell(position.getXPos()-1,position.getYPos(),maze.getCell(position.getXPos()-1,position.getYPos()));
    }
    if(mazeInMemory.checkDirection('E',position.getXPos(),position.getYPos()) && mazeWeightInMemory[position.getXPos()][position.getYPos()+1]==256){
        mazeWeightInMemory[position.getXPos()][position.getYPos()+1]=value+1;
        floodQeek.push(Point(position.getXPos(),position.getYPos()+1));
        mazeInMemory.setCell(position.getXPos(),position.getYPos()+1,maze.getCell(position.getXPos(),position.getYPos()+1));
    }
    if(mazeInMemory.checkDirection('W',position.getXPos(),position.getYPos()) && mazeWeightInMemory[position.getXPos()][position.getYPos()-1]==256){
        mazeWeightInMemory[position.getXPos()][position.getYPos()-1]=value+1;
        floodQeek.push(Point(position.getXPos(),position.getYPos()-1));
        mazeInMemory.setCell(position.getXPos(),position.getYPos()-1,maze.getCell(position.getXPos(),position.getYPos()-1));
    }
    if(mazeInMemory.checkDirection('S',position.getXPos(),position.getYPos()) && mazeWeightInMemory[position.getXPos()+1][position.getYPos()]==256){
        mazeWeightInMemory[position.getXPos()+1][position.getYPos()]=value+1;
        floodQeek.push(Point(position.getXPos()+1,position.getYPos()));
        mazeInMemory.setCell(position.getXPos()+1,position.getYPos(),maze.getCell(position.getXPos()+1,position.getYPos()));
    }

    if(!floodQeek.empty()){
        Point nextPoint = floodQeek.front();
        floodQeek.pop();
        calculateRoad(position,nextPoint);
        return 1;
    }
    return 0;
}

int Mouse::performManualStep(char manualStepDir, Maze maze){
    if(manualStepDir == 'N' && mazeInMemory.checkDirection('N',position.getXPos(),position.getYPos())){
        position.setXPos(position.getXPos()-1);
        mazeInMemory.setCell(position.getXPos(),position.getYPos(),maze.getCell(position.getXPos(),position.getYPos()));
    }else if(manualStepDir == 'S' && mazeInMemory.checkDirection('S',position.getXPos(),position.getYPos())){
        position.setXPos(position.getXPos()+1);
        mazeInMemory.setCell(position.getXPos(),position.getYPos(),maze.getCell(position.getXPos(),position.getYPos()));
    }else if(manualStepDir == 'E' && mazeInMemory.checkDirection('E',position.getXPos(),position.getYPos())){
        position.setYPos(position.getYPos()+1);
        mazeInMemory.setCell(position.getXPos(),position.getYPos(),maze.getCell(position.getXPos(),position.getYPos()));
    }else if(manualStepDir == 'W' && mazeInMemory.checkDirection('W',position.getXPos(),position.getYPos())){
        position.setYPos(position.getYPos()-1);
        mazeInMemory.setCell(position.getXPos(),position.getYPos(),maze.getCell(position.getXPos(),position.getYPos()));
    }
    if((position.getXPos()==7 || position.getXPos()==8) && (position.getYPos()==7 || position.getYPos()==8))
        return 0;
    return 1;
}

void Mouse::calculateShortestRoad(){
    int minValue = 256;
    Point minPoint;
    stack <Point> road;
    //Find min value of target
    if(mazeWeightInMemory[7][7]<minValue){
        minValue = mazeWeightInMemory[7][7];
        minPoint.setXPos(7);
        minPoint.setYPos(7);
    }
    if(mazeWeightInMemory[7][8]<minValue){
        minValue = mazeWeightInMemory[7][8];
        minPoint.setXPos(7);
        minPoint.setYPos(8);
    }
    if(mazeWeightInMemory[8][7]<minValue){
        minValue = mazeWeightInMemory[8][7];
        minPoint.setXPos(8);
        minPoint.setYPos(7);
    }
    if(mazeWeightInMemory[8][8]<minValue){
        minValue = mazeWeightInMemory[8][8];
        minPoint.setXPos(8);
        minPoint.setYPos(8);
    }
    while (minValue!=1){
        road.push(minPoint);
        if(mazeInMemory.checkDirection('N',minPoint.getXPos(),minPoint.getYPos()) && mazeWeightInMemory[minPoint.getXPos()-1][minPoint.getYPos()] < minValue){
            minValue = mazeWeightInMemory[minPoint.getXPos()-1][minPoint.getYPos()];
            minPoint.setXPos(minPoint.getXPos()-1);
            minPoint.setYPos(minPoint.getYPos());
        }else if(mazeInMemory.checkDirection('E',minPoint.getXPos(),minPoint.getYPos()) && mazeWeightInMemory[minPoint.getXPos()][minPoint.getYPos()+1] < minValue){
            minValue = mazeWeightInMemory[minPoint.getXPos()][minPoint.getYPos()+1];
            minPoint.setXPos(minPoint.getXPos());
            minPoint.setYPos(minPoint.getYPos()+1);
        }else if(mazeInMemory.checkDirection('W',minPoint.getXPos(),minPoint.getYPos()) && mazeWeightInMemory[minPoint.getXPos()][minPoint.getYPos()-1] < minValue){
            minValue = mazeWeightInMemory[minPoint.getXPos()][minPoint.getYPos()-1];
            minPoint.setXPos(minPoint.getXPos());
            minPoint.setYPos(minPoint.getYPos()-1);
        }else if(mazeInMemory.checkDirection('S',minPoint.getXPos(),minPoint.getYPos()) && mazeWeightInMemory[minPoint.getXPos()+1][minPoint.getYPos()] < minValue){
            minValue = mazeWeightInMemory[minPoint.getXPos()+1][minPoint.getYPos()];
            minPoint.setXPos(minPoint.getXPos()+1);
            minPoint.setYPos(minPoint.getYPos());
        }
    }

    while(!road.empty()){
        minPoint = road.top();
        road.pop();
        roadQeek.push(minPoint);
    }
}

Maze Mouse::getMazeInMemory(){
    return this->mazeInMemory;
}
