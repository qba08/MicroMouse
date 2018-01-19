#ifndef MAZE_H
#define MAZE_H
#include "cell.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
/*!
 * \brief The Maze class - klasa labiryntu
 * Klasa zawiera reprezentajcę labiryntu po którym porusza się robot.
 */
class Maze
{
public:
    /*!
     * \brief Maze - konstruktor domyślny
     * Konstrukot domyślny tworzący instancję klasy.
     */
    Maze();
    /*!
     * \brief readFromFile - funkcja generująca labirynt na podstawie pliku
     * \param fileName - nazwa pliku
     * Funkcja na podstawie pliku zapisanego w formacie mz, wczytuje ściany algorytmu.
     */
    void readFromFile(string fileName);
    /*!
     * \brief checkDirection - sprawdzenie kierunku poruszania robota
     * \param dir - kierunek ruchu ('N', 'S', 'E', 'W')
     * \param posX - pozycja x sprawdzanego pola
     * \param posY - pozycja y sprawdzanego pola
     * \return bool true - robot może poruszać się w podanym kierunku
     *              false - na drodze robota stoi sciana
     * Funkcja sprawdza możliwość poruszania się po labiryncie w danym polu.
     */
    bool checkDirection(char dir, int posX, int posY);
    /*!
     * \brief getCell - getter
     * \param x - współrzędna x komórki
     * \param y - współrzędna y komórki
     * \return Cell
     * Funkcja zwraca komórkę znajdującą się na danej pozycji.
     */
    Cell<bool> getCell(int x, int y);
    /*!
     * \brief setCell - setter
     * \param x - współrzędna x komórki
     * \param y - współrzędna y komórki
     * \param cell - komórka do zapisania
     * Funkcja zapisuje podaną komórkę w wyznaczone miejsce.
     */
    void setCell(int x, int y, Cell<bool> cell);
private:
    /*!
     * \brief maze - labirynt
     * Parametr przechowujący informację o labiryncjie.
     * Macierz komórek labiryntu.
     */
    Cell<bool> maze [16][16];
};

#endif // MAZE_H
