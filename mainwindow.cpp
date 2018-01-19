#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->createScene();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    string filePath = ui->FilePathArea->text().toStdString();
    if (!filePath.empty()){
        game = Game(game.getMode(),game.getVisibility(),filePath);
        this->stop = false;
        refreshView();
        int i = 0;
        while(game.performNextStep()!=0 && !stop){
            if(game.getMode()== 'A')
              ui->lcdNumber->display(i++);
            refreshView();
            qApp->processEvents();
        }
   }
}

void MainWindow::on_dialSpeed_valueChanged(int value)
{
    game.setSpeed(value);
}

void MainWindow::on_pushButton_clicked()
{
    stop = true;
    this->ui->dialSpeed->setValue(1);
     ui->lcdNumber->display(0);
}

void MainWindow::createScene()
{

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 650, 650);

    paintBorder();

    ui->graphicsView->setScene(scene);
}

void MainWindow::paintBorder()
{
    QPen myPen = QPen(Qt::black);
    myPen.setWidth(5);

    QLineF topLine(scene->sceneRect().topLeft(),
                   scene->sceneRect().topRight());
    QLineF leftLine(scene->sceneRect().topLeft(),
                    scene->sceneRect().bottomLeft());
    QLineF rightLine(scene->sceneRect().topRight(),
                     scene->sceneRect().bottomRight());
    QLineF bottomLine(scene->sceneRect().bottomLeft(),
                      scene->sceneRect().bottomRight());

    scene->addLine(topLine, myPen);
    scene->addLine(leftLine, myPen);
    scene->addLine(rightLine, myPen);
    scene->addLine(bottomLine, myPen);

}

void MainWindow::refreshView()
{
    QPen pen = QPen(Qt::blue);
    pen.setWidth(10);

    scene->clear();
    paintBorder();

    stack<QLineF> allLines = game.getMazeView(40,5);

    scene->addEllipse(allLines.top().x1()-10,allLines.top().y1()-10,20,20, pen);
    allLines.pop();

    pen.setColor(Qt::red);

    while (!allLines.empty()) {
        scene->addLine(allLines.top(), pen);
        allLines.pop();
    }
}

void MainWindow::on_radioButtonMaze_clicked()
{
    this->game.setVisibility('A');
}

void MainWindow::on_radioButtonMemory_clicked()
{
    this->game.setVisibility('M');
}

void MainWindow::on_radioButtonManual_clicked()
{
    this->game.setMode('M');
}

void MainWindow::on_radioButtonAuto_clicked()
{
    this->game.setMode('A');
}

void MainWindow::on_Up_clicked()
{
    this->game.setManualStepDir('N');
}

void MainWindow::on_Left_clicked()
{
    this->game.setManualStepDir('W');
}

void MainWindow::on_Down_clicked()
{
    this->game.setManualStepDir('S');
}

void MainWindow::on_Right_clicked()
{
    this->game.setManualStepDir('E');
}
