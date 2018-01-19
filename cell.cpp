#include "cell.h"

template <class T>
Cell<T>::Cell(){

}

template <class T>
Cell<T>::Cell(T n, T e, T s, T w){

}

template <class T>
void Cell<T>::setNorth(T val)

template <class T>
void Cell<T>::setEast(T val){
    this->EAST = val;
}

template <class T>
void Cell<T>::setSouth(T val){
    this->SOUTH = val;
}

template <class T>
void Cell<T>::setWest(T val){
    this->WEST = val;
}

template <class T>
T Cell<T>::getEast(){
    return this->EAST;
}

template <class T>
T Cell<T>::getWest(){
    return this->WEST;
}

template <class T>
T Cell<T>::getNorth(){
    return this->NORTH;
}

template <class T>
T Cell<T>::getSouth(){
    return this->SOUTH;
}

void TemporaryFunction ()
{
    Cell<bool> TempObj;
}
