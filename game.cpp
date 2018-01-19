#include "game.h"


Game::Game(){
    this->mode = 'A';
    this->visibility = 'A';
    //this->maze.readFromFile("/home/jakub/Dokumenty/C++/MicroMouse/fm.mz");
    this->mouse.setOnStart(maze);
    this->speed = 1;
    this->stage = 1;
}

Game::Game(char mode, char visibility,string fileName){
    if(mode =='A' || mode =='M'){
      this->mode = mode;
    }else{
      this->mode ='A';
    }
    if (visibility == 'A' || visibility == 'M'){
        this->visibility = visibility;
    }else{
        this->visibility = 'A';
    }
    this->maze.readFromFile(fileName);
    this->mouse.setOnStart(maze);
    this->speed = 1;
    this->stage = 1;
}

void Game::setSpeed(int s){
    if(s<1){
        this->speed=1;
    }else if(s>10){
        this->speed=10;
    }else{
        this->speed=s;
    }
}

void Game::setVisibility(char v){
    if (v == 'A' || v == 'M'){
        this->visibility = v;
    }else{
        this->visibility = 'A';
    }
}

char Game::getVisibility(){
    return visibility;
}

void Game::setMode(char m){
    if (m == 'A' || m == 'M'){
        this->mode = m;
    }else{
        this->mode = 'A';
    }
}

char Game::getMode(){
    return mode;
}

void Game::setManualStepDir(char d){
    if(d=='N' || d=='S' || d=='E' || d=='W')
        this->manualStepDir = d;
    else
        this->manualStepDir = '0';
}

int Game::performNextStep(){
    if(mode == 'A'){
        if(stage == 1){
            if(mouse.floodAlgorithmNextStep(maze) == 0)
                stage = 2;
        }else if(stage == 2){
            mouse.calculateShortestRoad();
            mouse.updatePosition(15,0);
            stage =3;
        }else if(stage == 3){
            if (mouse.performStepToGoal() == 0)
                stage = 4;
        }else if(stage == 4){
            return 0;
        }
    }else{
      if(manualStepDir != '0'){
          if(mouse.performManualStep(manualStepDir, maze)==0)
              return 0;
          manualStepDir = '0';
      }
      return 1;
    }

    usleep(10000000*speed/200);
    return 1;
}

stack<QLineF> Game::getMazeView(int size, int border){
    stack<QLineF> result;
    Maze mazeToShow;

    if(visibility == 'A'){
        mazeToShow = this->maze;
    }else{
        mazeToShow = this->mouse.getMazeInMemory();
    }
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            if(!mazeToShow.checkDirection('N',i,j)){
                result.push(QLineF((border+j*size),(border+i*size),(border+(j+1)*size),(border+i*size)));
            }
            if(!mazeToShow.checkDirection('S',i,j)){
                result.push(QLineF((border+j*size),(border+(i+1)*size),(border+(j+1)*size),(border+(i+1)*size)));
            }
            if(!mazeToShow.checkDirection('E',i,j)){
                result.push(QLineF(border+(j+1)*size,border+i*size,border+(j+1)*size,border+(i+1)*size));
            }
            if(!mazeToShow.checkDirection('W',i,j)){
                result.push(QLineF(border+j*size,border+i*size,border+j*size,border+(i+1)*size));
            }
        }
    }

    result.push(QLineF(border+mouse.getMousePositionY()*size+size/2,
                       border+mouse.getMousePositionX()*size+size/2,
                       border+mouse.getMousePositionY()*size+size/2,
                       border+mouse.getMousePositionX()*size+size/2));

    return result;
}

