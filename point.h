#ifndef POINT_H
#define POINT_H

using namespace std;
/*!
 * \brief The Point class - klasa przechowująca współrzędne labiryntu
 * Klasa przechowuje parametr x oraz parametr y.
 * Używana w procesie poruszania się po labiryncie oraz zapamiętywania pozycji robota.
 */
class Point
{
public:
    /*!
     * \brief Point - konsturktor domyślny
     * Konstruktor uzupełnia pola x i y wartością 1.
     */
    Point();
    /*!
     * \brief Point - konstruktor
     * \param x parametr współrzędnej x
     * \param y parametr współrzędnej y
     * Konstruktor uzupełnia pola x i y watorściami podanymi w parametrach.
     */
    Point(int x, int y);
    /*!
     * \brief getXPos - getter
     * \return wartość współrzędnej x
     */
    int getXPos();
    /*!
     * \brief getYPos - getter
     * \return wartość współrzędnej y
     */
    int getYPos();
    /*!
     * \brief setXPos - setter
     * \param x wartość ustawiana w polu x
     */
    void setXPos(int x);
    /*!
     * \brief setYPos - setter
     * \param y wartość ustawiana w polu y
     */
    void setYPos(int y);
private:
    /*!
     * \brief x współrzędna wysokości
     */
    int x;
    /*!
     * \brief y współrzędna szerokości
     */
    int y;
};

#endif // POINT_H
