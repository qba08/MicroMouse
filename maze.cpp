#include "maze.h"

Maze::Maze(){}

void Maze::readFromFile(string fileName){

  string firstLine;
  string secondLine;
  string thirdLine;

  ifstream infile;

  infile.open(fileName.c_str());

  if(!infile.is_open()){
      throw std::invalid_argument("File not exists.");
  }

  getline( infile, firstLine );
  for(int i=0; i<16; i++)
  {
      //north
      for(int j=0;j<16;j++){
       if(firstLine[j*2+1]=='-'){
         maze[i][j].setNorth(true);
       }else{
         maze[i][j].setNorth(false);
       }
      }

      getline( infile, secondLine );
      //west east
      for(int j=0;j<16;j++){
       if(secondLine[j*2]=='|'){
         maze[i][j].setWest(true);
       }else{
         maze[i][j].setWest(false);
       }

       if(secondLine[(j+1)*2]=='|'){
         maze[i][j].setEast(true);
       }else{
         maze[i][j].setEast(false);
       }
      }


      getline( infile, thirdLine );
      //south
      for(int j=0;j<16;j++){
       if(thirdLine[j*2+1]=='-'){
         maze[i][j].setSouth(true);
       }else{
         maze[i][j].setSouth(false);
       }
      }

      firstLine = thirdLine;
  }

  infile.close();

}

bool Maze::checkDirection(char dir, int posX, int posY){
    switch( dir )
    {
    case 'N':
        return !this->maze[posX][posY].getNorth();
    case 'S':
        return !this->maze[posX][posY].getSouth();
    case 'E':
        return !this->maze[posX][posY].getEast();
    case 'W':
        return !this->maze[posX][posY].getWest();
    default:
        return false;
    }
}

Cell<bool> Maze::getCell(int x, int y){
    return maze[x][y];
}

void Maze::setCell(int x, int y, Cell<bool> cell){
    maze[x][y] = cell;
}
