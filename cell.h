#ifndef CELL_H
#define CELL_H

using namespace std;
/*!
 * \brief The Cell class - klasa komórki labiryntu.
 * Klasa reprezentuje jedną komórkę zawartą w labiryncie.
 * Zawiera informacje o ścianach w komórki.
 * Implementuje szablon, aby zmieniać typ pól przechowywania informacji o ścianach labiryntu.
 * Implementacja zawarta jest w pliku nagłówkowym, aby uniknąć błędów związanych z referencjami.
 */
template <class T>
class Cell
{
public:
    /*!
     * \brief Cell - konstruktor domyślny
     * Konstruktor uzupełnia dane domyślnymi wartościami dla danego typu
     */
    Cell(){
        this->NORTH = T();
        this->SOUTH = T();
        this->WEST = T();
        this->EAST = T();
    }
    /*!
     * \brief Cell - konstruktor
     * \param n wartość NORTH
     * \param e wartość EAST
     * \param s wartość SOUTH
     * \param w wartość WEST
     * Konstruktor wypełnia dane wartościami podanymi jako parametry wejściowe.
     */
    Cell(T n, T e,T s, T w){
        this->NORTH = n;
        this->SOUTH = s;
        this->WEST = w;
        this->EAST = e;
    }

    /*!
     * \brief setNorth - setter
     * \param val wartość do ustawienia
     */
    void setNorth(T val){
        this->NORTH = val;
    }
    /*!
     * \brief setEast - setter
     * \param val wartość do ustawienia
     */
    void setEast(T val){
        this->EAST = val;
    }
    /*!
     * \brief setSouth - setter
     * \param val wartość do ustawienia
     */
    void setSouth(T val){
        this->SOUTH = val;
    }
    /*!
     * \brief setWest - setter
     * \param val wartość do ustawienia
     */
    void setWest(T val){
        this->WEST = val;
    }
    /*!
     * \brief getNorth - getter
     * \param pobranie wartości z NORTH
     */
    T getNorth(){
        return this->NORTH;
    }
    /*!
     * \brief getEast - getter
     * \param pobranie wartości z EAST
     */
    T getEast(){
        return this->EAST;
    }
    /*!
     * \brief getSouth - getter
     * \param pobranie wartości z SOUTH
     */
    T getSouth(){
        return this->SOUTH;
    }
    /*!
     * \brief getWest - getter
     * \param pobranie wartości z WEST
     */
    T getWest(){
        return this->WEST;
    }


private:
    /*!
     * \brief NORTH informacja o północnej ścianie
     */
    T NORTH;
    /*!
     * \brief EAST informacja o wschodniej ścianie
     */
    T EAST;
    /*!
     * \brief SOUTH informacja o południowej ścianie
     */
    T SOUTH;
    /*!
     * \brief WEST informacja o zachodniej ścianie
     */
    T WEST;
};

#endif // CELL_H
