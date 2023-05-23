#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <Qvector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);

private slots:

    // Слоти
    void on_crossButton_clicked();

    void on_noughtButton_clicked();

    void on_LetsPlayButton_clicked();

    void on_AboutGameButton_clicked();

    void on_StatisticsButton_clicked();

    void on_ExitButton_clicked();

    void on_FriendGameButton_clicked();

    void on_ComputerGameButton_clicked();

    void on_letsPlayChoiceButton_clicked();

    void on_easyChoiceButton_clicked();

    void on_middleChoiceButton_clicked();

    void on_difficultChoiceButton_clicked();

    void onPlayFieldClicked();

    void computerClick();

private:
    Ui::MainWindow *ui;

    int** field;
    int lineCombinations[8][3]{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9},
        {1, 5, 9},
        {3, 5, 7},
    };
    int compStatistics[3][3]{
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };
    QVector<int*> playersNumStatistics;
    QVector<QString*> playersNamesStatistics;
    QString withCompGameStatistics, playersGameStatistics;
    int howManyGameIsInPlayersStatistics = 0;
    int victoryLine[3];
    bool playerSymbol = 1, computerSymbol = 0, firstPlayerSymbol = 1, secondPlayerSymbol = 0;
    int playerChoice = 0, computerChoice = 0, isOver = 0, whoWinner = -1, difficult = 0;
    bool isGameStarted = false, isGameOver = false, isWithCompGame = true, isGameJustFinished = false;
    QString playerStyle, computerStyle, firstPlayerName, secondPlayerName;
    QTimer* timer;

    // Функції початкових налаштувань
    void setInterfaceStyle();
    void configPlayFieldButtons();

    // Функції для доступу до кнопок
    void setPlayFieldToBeginSettings();
    void setWinCombination();
    void setDrawField();
    void playerFieldLock();
    void playerFieldUnlock();
    void unGameButtonsLock();
    void unGameButtonsUnlock();

    // Функції для гри
    void startGame();
    void computerTurn();
    void checkEndGame();
    int isEndGame();
    void computerStatistics();
    void playerStatistics();

    // Функції для обчислень
    int numToRowIndex(int num);
    int numToColIndex(int num);
    int rowColIndexToNum(int row, int col);

    // Стилі кнопок
    void setCrossNoughtStatus(int indexButton);
    void setFriendComputerGameButtonStatus(int indexButton);
    void setEasyMiddleDifficultButtonStatus(int indexButton);
    void playFieldButtonStyle(int row, int col, QString style);
};
#endif // MAINWINDOW_H
