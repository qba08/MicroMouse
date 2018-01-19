#ifndef MOUSE_H
#define MOUSE_H
#include <queue>
#include <stack>
#include <cmath>
#include <stdexcept>
#include "point.h"
#include "maze.h"

using namespace std;
/*!
 * \brief The Mouse class - klasa reprezentująca robota.
 * Klasa symuluje zachowanie robota.
 * Implementuje algorytm zalewania.
 * Zawiera informacje o pozycji robota w labiryncie, wagach poszczególnych pól i zapamiętanym labiryncie.
 */
class Mouse
{
public:
    /*!
     * \brief Mouse - konstruktor domyślny.
     * Inicjalizuje mazeWeightInMemory wartościami największej możliwej wagi (256).
     */
    Mouse();

    /*!
     * \brief updatePosition - funkcja zmieniająca pozycję robota.
     * \param posX - współrzędna x
     * \param posY - współrzędna y
     * Funkcja ustawia nową pozycję robota na podstawie podanych parametrów.
     */
    void updatePosition(int posX, int posY);
    /*!
     * \brief getMousePositionX - getter
     * \return współrzędna x pozycji robota
     */
    int  getMousePositionX();
    /*!
     * \brief getMousePositionY - getter
     * \return współrzędna y pozycji robota
     */
    int  getMousePositionY();
    /*!
     * \brief setOnStart - funkcja ustawia robota na starcie.
     * \param maze - labirynt
     * Funkcja ustawia pozycję robota.
     * Aktualizuje wartości w pamięci, zapisując wagę oraz komórkę pola startowego.
     */
    void setOnStart(Maze maze);
    /*!
     * \brief floodAlgorithmNextStep - algorytm zalewania
     * \param maze - labirynt, po którym porusza się robot
     * \return Wartości 0 - ostatni krok algorytmu
     *                  1 - krok pośredni
     * Funkcja wyznacza wagi w labiryncie zgodnie z algorytmem zalewania.
     * Wagi liczone są od startu do pól środkowych.
     * Z każdym krokiem od startu zwiększane są o 1.
     * Funkcja kończy swoje działanie, gdy wyznaczy wagę dla wszystkich osiągalnych pól labiryntu.
     */
    int floodAlgorithmNextStep(Maze maze);
    /*!
     * \brief performManualStep - krok robota w trybie maualnym
     * \param manualStepDir - kierunek poruszania się robota
     * \param maze - labirynt, po którym porusza się robot
     * \return Wartości 0 - ostatni krok algorytmu
     *                  1 - krok pośredni
     */
    int performManualStep(char manualStepDir, Maze maze);
    /*!
     * \brief performStepToGoal - funkcja przechodzenia labiryntu
     * \return Wartości 0 - ostatni krok
     *                  1 - krok pośredni
     * Funkcja przechodzenia robota ze startu do środka labiryntu,
     * na podstawie pól wyznaczonych w funkcji calculateShortestRoad().;
     */
    int performStepToGoal();
    /*!
     * \brief calculateRoad - oblicza drogę z jednego punktu do drugiego
     * \param startPoint - punkt początkowy
     * \param endPoint - punkt końcowy
     * Funkcja wyznacza drogę pomiędzy dwoma punktami.
     * Pola na drodze dodawane są do kolejki road.
     */
    void calculateRoad(Point startPoint, Point endPoint);
    /*!
     * \brief calculateShortestRoad - obliczanie najktótszej drogi rozwiązania labiryntu.
     * Funkcja oblicza drogę z punktu startowego do środka labiryntu.
     * Dodaje kolejne pola do kolejki road.
     * Do obliczania drogi wykorzysuje wagi oraz labirynt zapisany w pamięci.
     * Droga liczona jest od środka do startu.
     */
    void calculateShortestRoad();
    /*!
     * \brief getMazeInMemory - getter
     * \return mazeInMemory
     * Pobranie labiryntu przechowywanego w pamięci robota
     */
    Maze getMazeInMemory();

private:
    /*!
     * \brief position - aktualna pozycja robota
     */
    Point position;
    /*!
     * \brief floodQeek - kolejka zalewania
     * Kolejka przechowuje informacje o kolejności zalewania pól labiryntu
     */
    queue <Point> floodQeek;
    /*!
     * \brief roadQeek - kolejka drogi
     * Kolejka zawiera drogę przejścia z jedneg punktu labiryntu do punktu celu
     */
    queue <Point> roadQeek;
    /*!
     * \brief mazeWeightInMemory - wagi
     * Tablica przechowuje informacje o wagach nadawanych komórkom labiryntu w kolejnych korkach algorytmu zalewania.
     */
    int mazeWeightInMemory [16][16];
    /*!
     * \brief mazeInMemory - labirynt w pamięci robota
     * Obiekt zawiera reprezentację pól labiryntu, które zostały odwiedzone przez robota.
     */
    Maze mazeInMemory;
};



#endif // MOUSE_H
