#ifndef GAME_H
#define GAME_H
#include <unistd.h>
#include <QGraphicsItem>
#include"maze.h"
#include"mouse.h"

using namespace std;

/*!
 * \brief The Game class -klasa symulująca grę.
 * Inicjalizuje labirynt, steruje kolejnymi krokami oraz szybkością gry.
 * Przeprowadza kolejne etapy rozgrywki w trybie automatycznym lub przechowuje kierunek następnego ruchu w trybie manualnym.
 */
class Game
{
public:
    /*!
     * \brief Game()- konstruktor domyślny
     * Wczytuje labirynt z pliku oraz ustawia speed na 1 i stage 1
     * Ustawia domyślne parametry visibility 'A' i mode 'A'.
     */
    Game();
    /*!
     * \brief Game - konstruktor z parametrami
     * \param mode - tryb pracy
     * \param visibility - widoczność
     * Wczytuje labirynt z pliku oraz ustawia speed na 1 i stage 1
     * Ustawia domyślne parametry visibility i mode parametrami podanymi do konstrukotra.
     */
    Game(char mode, char visibility,string fileName);
    /*!
     * \brief setSpeed - setter
     * \param s - szybkość
     * Funkcja ustawia parametr speed
     *
     */
    void setSpeed(int s);
    /*!
     * \brief setVisibility - setter
     * \param v - widoczność
     * Funkcja ustawia parametr visibility
     */
    void setVisibility(char v);
    /*!
     * \brief getVisibility - getter
     * \return visibility
     * Funkcja zwraca parametr visibility
     */
    char getVisibility();
    /*!
     * \brief setMode - setter
     * \param m - tryb pracy
     * Funkcja ustawia parametr mode
     */
    void setMode(char m);
    /*!
     * \brief getMode - getter
     * \return mode
     * Funkcja zwraca parametr mode
     */
    char getMode();
    /*!
     * \brief setManualStepDir - setter
     * \param d - kierunek następnego ruchu
     * Funkcja używana w trybie manualnym, ustawia kierunek następnego ruchu robota.
     */
    void setManualStepDir(char d);
    /*!
     * \brief performNextStep - funkcja przeprowadzająca kolejny krok robota
     * \return integer: 0 - wykonano ostatni krok, robot jest w polu koncowym; 1 - krok pośredni
     * W zależności od trybu gry, funkcja wywołuje funkcje zmieniające pozycje robota w labiryncie.
     * W trybie automatycznym wywołanie odpowiednich funkcju uzależnione jest od etapu (stage).
     */
    int  performNextStep();
    /*!
     * \brief getMazeView - pobranie obecnego stanu labiryntu do wyświetlenia
     * \param size - rozmiar pola
     * \param border - rozmiar obramowania
     * \return stos lini tworzących obraz labiryntu oraz położenia robota.
     * Funkcja w zależności od parametru visibility pobiera labirynt.
     * Na podstawie labiryntu dodaje do stosu linie, które reprezentują kolejne sciany labiryntu.
     * Na końcu do stosu dodawane jest położenie robota w labiryncie.
     */
    stack<QLineF> getMazeView(int size,int border);
private:
    /*!
     * \brief speed - parametr szybkości ruchu robota.
     * Parametr określa czas oczekiwania robota na nasępny ruch.
     * Wartości: Min - 1
     *           Max - 10
     */
    int speed;
    /*!
     * \brief stage - parametr etapu algorytmu zalewania
     * Parametr steruje wywołaniem funkcji algorytmu zalewania.
     * Wartości: 1 - algorytm zalewania
     *           2 - obliczanie najkrótszej drogi
     *           3 - wykonanie przejścia od startu do punktu końcowego
     *           4 - osiągnięto punkt końcowy
     */
    int stage;
    /*!
     * \brief mode - parametr sterowania ruchami robota
     * Parametr określa sposób sterowania robotem.
     * Wartości: A - automatyczne poruszanie robota
     *           M - sterowanie manualne
     */
    char mode;
    /*!
     * \brief visibility - parametr widoczności
     * Parametr określa jaki obraz labiryntu zostanie wyświetlony.
     * Wartości: A - wyświetlanie całego labiryntu
     *           M - wyświetlanie labiryntu z pamięci robota
     */
    char visibility;
    /*!
     * \brief manualStepDir - kierunek następnego ruchu
     * Parametr określający kierunek ruchu robota w trybie manualnym
     * Wartości N - północ
     *          S - południe
     *          E - wschód
     *          W - zachód
     */
    char manualStepDir;
    /*!
     * \brief mouse obiekt klasy Mouse
     * Obiekt symulujący robota w grze
     */
    Mouse mouse;
    /*!
     * \brief maze obiekt klasy Maze
     * Obiekt przedstawiający labirynt
     */
    Maze maze;
};

#endif // GAME_H
