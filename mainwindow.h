#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"game.h"
#include <iostream>
#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimeLine>
#include <QGraphicsItemAnimation>



namespace Ui {
class MainWindow;
}
/*!
 * \brief The MainWindow class - klasa GUI.
 * Klasa zawiera graficzny interfejs użytkownika oraz panel wyświetlający labirynt i robota.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow - konstruktor
     * \param parent obiekt nadrzędny
     */
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    /*!
     * \brief on_startButton_clicked - funkcja przycisku start.
     * Funkcja uruchamia grę.
     * Odświeża widok labiryntu.
     */
    void on_startButton_clicked();
    /*!
     * \brief on_dialSpeed_valueChanged - zmiana szybkości.
     * \param value wartość pobrana z suwaka
     * Funkcja ustawia szybkość gry.
     */
    void on_dialSpeed_valueChanged(int value);
    /*!
     * \brief on_pushButton_clicked - funkcja przycisku restart.
     * Funkcja zatrzymuje grę oraz nadpisuje grę nowym obiektem.
     */
    void on_pushButton_clicked();

    /*!
     * \brief on_radioButtonMaze_clicked - przełącznik widoku.
     * Funkcja ustawia widok gry na cały labirynt.
     */
    void on_radioButtonMaze_clicked();
    /*!
     * \brief on_radioButtonMemory_clicked - przełącznik widoku.
     * Funkcja ustawia widok gry na labirynt zapisany w pamięci robota.
     */
    void on_radioButtonMemory_clicked();
    /*!
     * \brief on_radioButtonManual_clicked - przełącznik trybu.
     * Funkcja zmienia tryb rozgrywki na manualną.
     */
    void on_radioButtonManual_clicked();
    /*!
     * \brief on_radioButtonAuto_clicked - przełącznik trybu.
     * Funkcja zmienia tryb rozgrywki na automatyczną.
     */
    void on_radioButtonAuto_clicked();
    /*!
     * \brief on_Up_clicked - funkcja przycisku poruszania manualnego .
     * Funkcja ustawia kierunek następnego kroku na 'N'.
     */
    void on_Up_clicked();
    /*!
     * \brief on_Left_clicked - funkcja przycisku poruszania manualnego .
     * Funkcja ustawia kierunek następnego kroku na 'W'.
     */
    void on_Left_clicked();
    /*!
     * \brief on_Down_clicked - funkcja przycisku poruszania manualnego .
     * Funkcja ustawia kierunek następnego kroku na 'S'.
     */
    void on_Down_clicked();
    /*!
     * \brief on_Right_clicked - funkcja przycisku poruszania manualnego .
     * Funkcja ustawia kierunek następnego kroku na 'E'.
     */
    void on_Right_clicked();

private:
    /*!
     * \brief ui - Obiekt reprezentujący główne okno programu.
     */
    Ui::MainWindow *ui;
    /*!
     * \brief scene - obiekt wyświetlający labirynt.
     */
    QGraphicsScene *scene;
    /*!
     * \brief game - obiekt symulujący grę.
     */
    Game game;
    /*!
     * \brief stop - flaga używana do zatrzymania procesu przechodzenia przez labirynt.
     */
    bool stop;
    /*!
     * \brief createScene - funkcja tworząca scenę.
     * Funkcja inicjalizuje obiekt scene, określa jego wymiary oraz dodaje go do GUI.
     */
    void createScene();
    /*!
     * \brief paintBorder - wyświetlanie granic labiryntu.
     * Funkcja rysuje na scenie linie graniczne całego labiryntu.
     */
    void paintBorder();
    /*!
     * \brief refreshView - odświeżenie wyświetlanego labiryntu.
     * Funkcja na podstawie danych pobranych z obiektu game, czyści scenę,
     * a następnie wyświetla stan labiryntu
     */
    void refreshView();
};

#endif // MAINWINDOW_H
