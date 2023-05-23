#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTabBar"
#include "QScrollArea"
#include "stylehelper.h"
#include "compChoiceDifficult.h"
#include "QStyleOption"
#include "QFontDatabase"
#include "QGridLayout"
#include <time.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::computerClick);
    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide();
    ui->tabWidgetChoice->tabBar()->hide();
    ui->tabWidget->setCurrentIndex(2);
    ui->tabWidgetChoice->setCurrentIndex(1);
    field = new int*[3];
    for (int i = 0; i < 3; i++){
        field[i] = new int[3];
    }
    setInterfaceStyle();
    configPlayFieldButtons();

    QFontDatabase::addApplicationFont(":/tictactoe/fonts/Arial_Black.ttf");
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < 3; i++){
        delete[] field[i];
    }
    delete[] field;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}


    // Слоти

void MainWindow::on_crossButton_clicked()
{
    setCrossNoughtStatus(1);
    playerSymbol = 1;
    computerSymbol = 0;
}


void MainWindow::on_noughtButton_clicked()
{
    setCrossNoughtStatus(0);
    playerSymbol = 0;
    computerSymbol = 1;
}


void MainWindow::on_LetsPlayButton_clicked()
{
    if (!isGameStarted){
        if (isGameJustFinished){
            ui->curentGameStateLabel->setStyleSheet(StyleHelper::getEmptyLabelStyle());
            ui->curentGameStateLabel->setText("");
            ui->tabWidget->setCurrentIndex(0);
            if (isWithCompGame){
                if (playerSymbol == 1){
                    playerStyle = StyleHelper::getCrossPlayFieldButtonStyle();
                    computerStyle = StyleHelper::getNoughtPlayFieldButtonStyle();
                    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
                    ui->curentGameStateLabel->setText("Ваш хід");
                }
                else {
                    playerStyle = StyleHelper::getNoughtPlayFieldButtonStyle();
                    computerStyle = StyleHelper::getCrossPlayFieldButtonStyle();
                    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
                    ui->curentGameStateLabel->setText("Хід комп'ютера");
                }
            }
            else{
                firstPlayerSymbol = !firstPlayerSymbol;
                secondPlayerSymbol = !secondPlayerSymbol;
                if (firstPlayerSymbol == 1){
                    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
                    ui->curentGameStateLabel->setText("Ходить " + firstPlayerName);
                }
                else{
                    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
                    ui->curentGameStateLabel->setText("Ходить " + secondPlayerName);
                }
                setCrossNoughtStatus(1);
            }
            ui->LetsPlayButton->setStyleSheet(StyleHelper::getStartLoseButtonStyle());
            ui->LetsPlayButton->setText("Здавайся!");
            unGameButtonsLock();
            startGame();
        }
        else{
            ui->tabWidget->setCurrentIndex(3);
            ui->tabWidgetChoice->setCurrentIndex(0);
            ui->FriendGameButton->setStyleSheet(StyleHelper::getChoosePlayerButtonStyle());
            ui->ComputerGameButton->setStyleSheet(StyleHelper::getChooseComputerButtonStyle());
            ui->letsPlayChoiceButton->setStyleSheet(StyleHelper::getLetsPlayChoiceActiveButtonStyle());
            ui->letsPlayChoiceButton->setDisabled(true);
        }
    }
    else{
        ui->LetsPlayButton->setStyleSheet(StyleHelper::getStartButtonStyle());
        ui->LetsPlayButton->setText("Грати ще");
        if (isWithCompGame){
            compStatistics[difficult - 1][1]++;
            ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleLose());
            ui->curentGameStateLabel->setText("Ви програли :(");
        }
        else{
            if ((isOver+firstPlayerSymbol) % 2 == 1){
                playersNumStatistics[playersNumStatistics.size() - 1][1]++;
                ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleWin());
                ui->curentGameStateLabel->setText("Переможець: " + secondPlayerName);
            }
            else{
                playersNumStatistics[playersNumStatistics.size() - 1][0]++;
                ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleWin());
                ui->curentGameStateLabel->setText("Переможець: " + firstPlayerName);
            }
        }
        isGameJustFinished = true;
        playerFieldLock();
        unGameButtonsUnlock();
    }
}

void MainWindow::on_AboutGameButton_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    isGameJustFinished = false;
    ui->crossButton->setDisabled(false);
    ui->noughtButton->setDisabled(false);
    setCrossNoughtStatus(1);
    playerSymbol = 1;
    computerSymbol = 0;
    ui->LetsPlayButton->setText("Грати");
    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getEmptyLabelStyle());
    ui->curentGameStateLabel->setText("");
}

void MainWindow::on_StatisticsButton_clicked()
{
    computerStatistics();
    playerStatistics();
    ui->statTextLabel1->setText(withCompGameStatistics);
    ui->statTextLabel2->setText(playersGameStatistics);
    ui->tabWidget->setCurrentIndex(4);

    isGameJustFinished = false;
    ui->crossButton->setDisabled(false);
    ui->noughtButton->setDisabled(false);
    setCrossNoughtStatus(1);
    playerSymbol = 1;
    computerSymbol = 0;
    ui->LetsPlayButton->setText("Грати");
    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getEmptyLabelStyle());
    ui->curentGameStateLabel->setText("");
}

void MainWindow::on_ExitButton_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
    isGameJustFinished = false;
    ui->crossButton->setDisabled(false);
    ui->noughtButton->setDisabled(false);
    setCrossNoughtStatus(1);
    playerSymbol = 1;
    computerSymbol = 0;
    ui->LetsPlayButton->setText("Грати");
    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getEmptyLabelStyle());
    ui->curentGameStateLabel->setText("");
    ui->kittyLabel->setText("Ви зараз у головному меню\n");
}


void MainWindow::on_FriendGameButton_clicked()
{
    isWithCompGame = false;
    setFriendComputerGameButtonStatus(0);
    ui->tabWidgetChoice->setCurrentIndex(1);
    ui->letsPlayChoiceButton->setStyleSheet(StyleHelper::getLetsPlayChoiceButtonStyle());
    ui->letsPlayChoiceButton->setDisabled(false);
    ui->lineEditPlayer1->setText("Гравець 1");
    ui->lineEditPlayer2->setText("Гравець 2");
}


void MainWindow::on_ComputerGameButton_clicked()
{
    isWithCompGame = true;
    setFriendComputerGameButtonStatus(1);
    ui->tabWidgetChoice->setCurrentIndex(2);
    ui->easyChoiceButton->setStyleSheet(StyleHelper::getEasyChoiceButtonStyle());
    ui->middleChoiceButton->setStyleSheet(StyleHelper::getMiddleChoiceButtonStyle());
    ui->difficultChoiceButton->setStyleSheet(StyleHelper::getDifficultChoiceButtonStyle());
    ui->easyChoiceButton->setDisabled(false);
    ui->middleChoiceButton->setDisabled(false);
    ui->difficultChoiceButton->setDisabled(false);
    ui->letsPlayChoiceButton->setStyleSheet(StyleHelper::getLetsPlayChoiceActiveButtonStyle());
    ui->letsPlayChoiceButton->setDisabled(true);
}


void MainWindow::on_letsPlayChoiceButton_clicked()
{
    if (isWithCompGame){
        if (playerSymbol == 1){
            playerStyle = StyleHelper::getCrossPlayFieldButtonStyle();
            computerStyle = StyleHelper::getNoughtPlayFieldButtonStyle();
            ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
            ui->curentGameStateLabel->setText("Ваш хід");
        }
        else {
            playerStyle = StyleHelper::getNoughtPlayFieldButtonStyle();
            computerStyle = StyleHelper::getCrossPlayFieldButtonStyle();
            ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
            ui->curentGameStateLabel->setText("Хід комп'ютера");
        }
    }
    else{
        firstPlayerName = ui->lineEditPlayer1->text();
        secondPlayerName = ui->lineEditPlayer2->text();

        int* playersStat = new int[3];
        for (int i = 0; i < 3; i++){
            playersStat[i] = 0;
        }
        playersNumStatistics.push_back(playersStat);

        QString* playersNames = new QString[2];
        playersNames[0] = firstPlayerName;
        playersNames[1] = secondPlayerName;
        playersNamesStatistics.push_back(playersNames);

        setCrossNoughtStatus(1);
        firstPlayerSymbol = 1;
        secondPlayerSymbol = 0;
        ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
        ui->curentGameStateLabel->setText("Ходить " + firstPlayerName);
    }
    ui->tabWidget->setCurrentIndex(0);
    ui->LetsPlayButton->setStyleSheet(StyleHelper::getStartLoseButtonStyle());
    ui->LetsPlayButton->setText("Здавайся!");
    unGameButtonsLock();
    startGame();
}


void MainWindow::on_easyChoiceButton_clicked()
{
    setEasyMiddleDifficultButtonStatus(0);
    difficult = 1;
    ui->letsPlayChoiceButton->setStyleSheet(StyleHelper::getLetsPlayChoiceButtonStyle());
    ui->letsPlayChoiceButton->setDisabled(false);
}


void MainWindow::on_middleChoiceButton_clicked()
{
    setEasyMiddleDifficultButtonStatus(1);
    difficult = 2;
    ui->letsPlayChoiceButton->setStyleSheet(StyleHelper::getLetsPlayChoiceButtonStyle());
    ui->letsPlayChoiceButton->setDisabled(false);
}


void MainWindow::on_difficultChoiceButton_clicked()
{
    setEasyMiddleDifficultButtonStatus(2);
    difficult = 3;
    ui->letsPlayChoiceButton->setStyleSheet(StyleHelper::getLetsPlayChoiceButtonStyle());
    ui->letsPlayChoiceButton->setDisabled(false);
}

void MainWindow::onPlayFieldClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    int row = button->property("row").toInt();
    int col = button->property("col").toInt();
    if (field[row][col] == -1){
        if (isWithCompGame){
            playFieldButtonStyle(button->property("row").toInt(), button->property("col").toInt(), playerStyle);
            field[button->property("row").toInt()][button->property("col").toInt()] = playerSymbol;
            playerFieldLock();
            isOver++;
            ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
            ui->curentGameStateLabel->setText("Хід комп'ютера");
            checkEndGame();
            computerTurn();
        }
        else{
            if (isOver % 2 == 0){
                playFieldButtonStyle(button->property("row").toInt(), button->property("col").toInt(), StyleHelper::getCrossPlayFieldButtonStyle());
                field[button->property("row").toInt()][button->property("col").toInt()] = 1;
                if (firstPlayerSymbol == 1){
                    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
                    ui->curentGameStateLabel->setText("Ходить " + secondPlayerName);
                }
                else{
                    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
                    ui->curentGameStateLabel->setText("Ходить " + firstPlayerName);
                }

            }
            else{
                playFieldButtonStyle(button->property("row").toInt(), button->property("col").toInt(), StyleHelper::getNoughtPlayFieldButtonStyle());
                field[button->property("row").toInt()][button->property("col").toInt()] = 0;
                if (firstPlayerSymbol == 1){
                    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
                    ui->curentGameStateLabel->setText("Ходить " + firstPlayerName);
                }
                else{
                    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
                    ui->curentGameStateLabel->setText("Ходить " + secondPlayerName);
                }
            }
            isOver++;
            checkEndGame();
            setCrossNoughtStatus(!(isOver % 2));
        }
    }
}

void MainWindow::computerClick()
{
    timer->stop();

    if (difficult == 1){
        computerChoice = CompChoice::easyCompPlayChoice(field, computerSymbol);
    }
    else if (difficult == 2){
        computerChoice = CompChoice::middleCompPlayChoice(field);
    }
    else if (difficult == 3){
        computerChoice = CompChoice::difficultCompPlayChoice(field, computerSymbol, isOver);
    }

    int row = numToRowIndex(computerChoice), col = numToColIndex(computerChoice);
    field[row][col] = computerSymbol;
    playFieldButtonStyle(row, col, computerStyle);
    playerFieldUnlock();
    isOver++;
    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleTurnChange());
    ui->curentGameStateLabel->setText("Ваш хід");
    checkEndGame();
}


    // Функції початкових налаштувань

void MainWindow::setInterfaceStyle()
{
    this->setStyleSheet(StyleHelper::getMainWindowStyle());

    ui->LetsPlayButton->setStyleSheet(StyleHelper::getStartButtonStyle());
    ui->AboutGameButton->setStyleSheet(StyleHelper::getStartButtonStyle());
    ui->ExitButton->setStyleSheet(StyleHelper::getStartButtonStyle());
    ui->StatisticsButton->setStyleSheet(StyleHelper::getStartButtonStyle());

    ui->crossButton->setStyleSheet(StyleHelper::getCrossButtonActiveStyle());
    ui->noughtButton->setStyleSheet(StyleHelper::getNoughtButtonStyle());

    ui->tabWidget->setStyleSheet(StyleHelper::getTabWidgetStyle());
    ui->tabAboutGame->setStyleSheet(StyleHelper::getTabAboutGameStyle());
    ui->tabStatistics->setStyleSheet(StyleHelper::getTabAboutGameStyle());

    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getEmptyLabelStyle());
    ui->curentGameStateLabel->setText("");

    ui->kittyLabel->setStyleSheet(StyleHelper::getKittyLabelStyle());
    ui->mainLabel->setStyleSheet(StyleHelper::getMainLabelStyle());

    ui->FriendGameButton->setStyleSheet(StyleHelper::getChoosePlayerButtonStyle());
    ui->ComputerGameButton->setStyleSheet(StyleHelper::getChooseComputerButtonStyle());

    ui->easyChoiceButton->setStyleSheet(StyleHelper::getEasyChoiceButtonStyle());
    ui->middleChoiceButton->setStyleSheet(StyleHelper::getMiddleChoiceButtonStyle());
    ui->difficultChoiceButton->setStyleSheet(StyleHelper::getDifficultChoiceButtonStyle());
    ui->chooseCatLabel->setStyleSheet(StyleHelper::chooseCatLabelStyle());

    ui->letsPlayChoiceButton->setStyleSheet(StyleHelper::getLetsPlayChoiceActiveButtonStyle());

    ui->lineEditPlayer1->setStyleSheet(StyleHelper::getLineEditChoiceStyle());
    ui->lineEditPlayer2->setStyleSheet(StyleHelper::getLineEditChoiceStyle());

    ui->chooseModeGameLabel->setStyleSheet(StyleHelper::getChooseGamesLabelStyle());
    ui->inputPlayersNameLabel->setStyleSheet(StyleHelper::getChooseGamesLabelStyle());
    ui->chooseDifficultGameLabel->setStyleSheet(StyleHelper::getChooseGamesLabelStyle());

    ui->descrWelcomeLabel->setStyleSheet(StyleHelper::descrWelcomeLabelStyle());
    ui->descrByeLabel->setStyleSheet(StyleHelper::descrWelcomeLabelStyle());
    ui->descrTitleLabel1->setStyleSheet(StyleHelper::descrTitleLabelStyle());
    ui->descrTitleLabel2->setStyleSheet(StyleHelper::descrTitleLabelStyle());
    ui->descrTitleLabel3->setStyleSheet(StyleHelper::descrTitleLabelStyle());
    ui->descrTitleLabel4->setStyleSheet(StyleHelper::descrTitleLabelStyle());
    ui->descrTextLabel1->setStyleSheet(StyleHelper::descrTextLabelStyle());
    ui->descrTextLabel2->setStyleSheet(StyleHelper::descrTextLabelStyle());
    ui->descrTextLabel3->setStyleSheet(StyleHelper::descrTextLabelStyle());
    ui->descrTextLabel4->setStyleSheet(StyleHelper::descrTextLabelStyle());
    ui->descrCatLabel->setStyleSheet(StyleHelper::descrCatLabelStyle());

    ui->statWelcomeLabel->setStyleSheet(StyleHelper::descrWelcomeLabelStyle());
    ui->statByeLabel->setStyleSheet(StyleHelper::descrWelcomeLabelStyle());
    ui->statTitleLabel1->setStyleSheet(StyleHelper::descrTitleLabelStyle());
    ui->statTitleLabel2->setStyleSheet(StyleHelper::descrTitleLabelStyle());
    ui->statTextLabel1->setStyleSheet(StyleHelper::descrTextLabelStyle());
    ui->statTextLabel2->setStyleSheet(StyleHelper::descrTextLabelStyle());
    ui->statCatLabel->setStyleSheet(StyleHelper::statCatLabelStyle());
}

void MainWindow::configPlayFieldButtons()
{
    QGridLayout* grid = qobject_cast <QGridLayout*>(ui->tabPlayField->layout());
    for (int i = 0; i < 3; i++){
        for (int k = 0; k < 3; k++){
            QPushButton* button = qobject_cast <QPushButton*>(grid->itemAtPosition(i, k)->widget());
            button->setProperty("row", i);
            button->setProperty("col", k);
            connect(button, &QPushButton::clicked, this, &MainWindow::onPlayFieldClicked);
        }
    }
}


    // Функції для доступу до кнопок

void MainWindow::setPlayFieldToBeginSettings()
{
    for (int i = 0; i < 3; i++){
        for (int k = 0; k < 3; k++){
            playFieldButtonStyle(i, k, StyleHelper::getEmptyPlayFieldButtonStyle());
        }
    }
    for (int i = 0; i < 3; i++){
        for (int k = 0; k < 3; k++){
            field[i][k] = -1;
        }
    }
    playerFieldUnlock();
}

void MainWindow::setWinCombination()
{
    if (whoWinner != -1){
        QString style;
        if (whoWinner == 1){
            style = StyleHelper::getCrossEndPlayFieldButtonStyle();
        }
        else{
            style = StyleHelper::getNoughtEndPlayFieldButtonStyle();
        }

        for (int i = 0; i < 3; i++){
            playFieldButtonStyle(numToRowIndex(victoryLine[i]), numToColIndex(victoryLine[i]), style);
        }
    }
}

void MainWindow::setDrawField()
{
    for (int i = 0; i < 3; i++){
        for (int k = 0; k < 3; k++){
            if (field[i][k] == 1){
                playFieldButtonStyle(i, k, StyleHelper::getCrossDrawPlayFieldButtonStyle());
            }
            else{
                playFieldButtonStyle(i, k, StyleHelper::getNoughtDrawPlayFieldButtonStyle());
            }
        }
    }
}

void MainWindow::playerFieldLock()
{
    QGridLayout* grid = qobject_cast <QGridLayout*>(ui->tabPlayField->layout());
    QPushButton* button;
    for (int i = 0; i < 3; i++){
        for (int k = 0; k < 3; k++){
            button = qobject_cast <QPushButton*>(grid->itemAtPosition(i, k)->widget());
            button->setDisabled(true);
        }
    }
}

void MainWindow::playerFieldUnlock()
{
    QGridLayout* grid = qobject_cast <QGridLayout*>(ui->tabPlayField->layout());
    QPushButton* button;
    for (int i = 0; i < 3; i++){
        for (int k = 0; k < 3; k++){
            button = qobject_cast <QPushButton*>(grid->itemAtPosition(i, k)->widget());
            button->setDisabled(false);
        }
    }
}

void MainWindow::unGameButtonsLock()
{
    isGameStarted = true;
    ui->crossButton->setDisabled(true);
    ui->noughtButton->setDisabled(true);
    ui->AboutGameButton->setDisabled(true);
    ui->ExitButton->setDisabled(true);
    ui->StatisticsButton->setDisabled(true);
}

void MainWindow::unGameButtonsUnlock()
{
    isGameStarted = false;
    ui->AboutGameButton->setDisabled(false);
    ui->ExitButton->setDisabled(false);
    ui->StatisticsButton->setDisabled(false);
    if (isWithCompGame){
        ui->crossButton->setDisabled(false);
        ui->noughtButton->setDisabled(false);
    }

}


    // Функції для гри

void MainWindow::startGame()
{
    setPlayFieldToBeginSettings();
    whoWinner = -1;
    isOver = 0;
    isGameOver = false;
    playerChoice = 0;
    computerChoice = 0;

    if (isWithCompGame){
        if (!(playerSymbol == 1)){
            playerFieldLock();
        }
        else {
            playerFieldUnlock();
        }
        if (playerSymbol == 0){
            computerTurn();
        }
    }
    else{
        playerFieldUnlock();
    }
}

void MainWindow::computerTurn()
{
    srand(time(NULL));
    if (isGameOver){
        return;
    }
    timer->start(300);
}

void MainWindow::checkEndGame()
{
    whoWinner = isEndGame();
    if (whoWinner != -1 || isOver == 9){
        isGameOver = true;
        isGameJustFinished = true;
        ui->LetsPlayButton->setStyleSheet(StyleHelper::getStartButtonStyle());
        ui->LetsPlayButton->setText("Грати ще");
        setWinCombination();
        playerFieldLock();
        unGameButtonsUnlock();
        if (isOver == 9 && whoWinner == -1){
            if (isWithCompGame){
                compStatistics[difficult - 1][2]++;
            }
            else{
                playersNumStatistics[playersNumStatistics.size() - 1][2]++;
            }
            ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleDraw());
            ui->curentGameStateLabel->setText("Нічия!");
            setDrawField();
        }
        else {
            if (isWithCompGame){
                if (whoWinner == playerSymbol){
                    compStatistics[difficult - 1][0]++;
                    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleWin());
                    ui->curentGameStateLabel->setText("Ви виграли :)");
                }
                else {
                    compStatistics[difficult - 1][1]++;
                    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleLose());
                    ui->curentGameStateLabel->setText("Ви програли :(");
                }
            }
            else{
                if (whoWinner == firstPlayerSymbol){
                    playersNumStatistics[playersNumStatistics.size() - 1][0]++;
                    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleWin());
                    ui->curentGameStateLabel->setText("Переможець: " + firstPlayerName);
                }
                else{
                    playersNumStatistics[playersNumStatistics.size() - 1][1]++;
                    ui->curentGameStateLabel->setStyleSheet(StyleHelper::getLetsPlayLabelStyleWin());
                    ui->curentGameStateLabel->setText("Переможець: " + secondPlayerName);
                }
            }
        }
    }
}

int MainWindow::isEndGame()
{
    int symbols[] = {0, 1}; // Два можливих символи на полі (Х та О)
    bool isLine = true; // Чи знайдена лінія із трьох однакових символів
    int i = 0; // Об'явили ітератор поза циклом, щоб, у разі виграшу когось, знати який саме символ виграв

    for (; i < 2; i++){ // Беремо якийсь із двох символів
        for (int k = 0; k < 8; k++){ // Шукаємо три однакові символи по всім 8 можливим комбінаціям ліній
            isLine = true;
            for (int j = 0; j < 3; j++){ // Йдемо по строці індексів лінії
                if (field[numToRowIndex(lineCombinations[k][j])][numToColIndex(lineCombinations[k][j])] != symbols[i]){
                    isLine = false; // Якщо хоча б один символ не дорівнює тому, який ми взяли (інший символ або пропуск), лінія не повна
                    break;
                }
            }
            if (isLine){ // Якщо лінія не змінилась на false, строка складається з трьох однакових символів. Тому виходимо з усіх циклів
                for (int j = 0; j < 3; j++){
                    victoryLine[j] = lineCombinations[k][j];
                }
                break;
            }
        }
        if (isLine){
            break;
        }
    }

    if (isLine){ // Якщо лінія не змінилась на false, хтось виграв
        return symbols[i];
    }
    return -1; // Якщо лінія змінилась на false, ніхто ще (або вже) не виграв
}

void MainWindow::computerStatistics()
{
    QString modes[3] = {"Легкий", "\nСередній", "\nСкладний"};
    withCompGameStatistics = "";
    double percentage[3];
    int allGames;
    for (int i = 0; i < 3; i++){
        allGames = compStatistics[i][0] + compStatistics[i][1] + compStatistics[i][2];
        if (allGames == 0){
            for (int k = 0; k < 2; k++){
                percentage[k] = 33.33;
            }
        }
        else{
            for (int k = 0; k < 2; k++){
                percentage[k] = (double)compStatistics[i][k] / allGames * 10000;
                percentage[k] = (int)percentage[k];
                percentage[k] = (double)percentage[k] / 100;
            }
        }
        percentage[2] = 100 - (percentage[0] + percentage[1]);

        withCompGameStatistics += modes[i] + " режим\n";
        withCompGameStatistics += "    Всього ігор: " + QString::number(allGames) + "\n";
        withCompGameStatistics += "        Виграно:   " + QString::number(compStatistics[i][0]) + " (" + QString::number(percentage[0]) + "%)\n";
        withCompGameStatistics += "        Програно: " + QString::number(compStatistics[i][1]) + " (" + QString::number(percentage[1]) + "%)\n";
        withCompGameStatistics += "        Нічия:        " + QString::number(compStatistics[i][2]) + " (" + QString::number(percentage[2]) + "%)";
    }

}

void MainWindow::playerStatistics()
{
    int currentGamesAmount = playersNumStatistics.size();
    if (currentGamesAmount == 0){
        playersGameStatistics = "Ще ігор не було :(\n";
        return;
    }
    if (howManyGameIsInPlayersStatistics == 0){
        playersGameStatistics = "";
    }
    double percentage[3];
    int allGames;
    QString curStr = "";

    for (int i = currentGamesAmount - 1; i >= howManyGameIsInPlayersStatistics; i--){
        allGames = playersNumStatistics[i][0] + playersNumStatistics[i][1] + playersNumStatistics[i][2];
        if (allGames == 0){
            for (int k = 0; k < 2; k++){
                percentage[k] = 33.33;
            }
        }
        else{
            for (int k = 0; k < 2; k++){
                percentage[k] = (double)playersNumStatistics[i][k] / allGames * 10000;
                percentage[k] = (int)percentage[k];
                percentage[k] = (double)percentage[k] / 100;
            }
        }
        percentage[2] = 100 - (percentage[0] + percentage[1]);

        curStr += playersNamesStatistics[i][0] + " VS " + playersNamesStatistics[i][1] + "\n";
        curStr += "    Всього ігор: " + QString::number(allGames) + "\n";
        curStr += "        Виграв(ла) " + playersNamesStatistics[i][0] + ": " +
                QString::number(playersNumStatistics[i][0]) + " (" + QString::number(percentage[0]) + "%)\n";
        curStr += "        Виграв(ла) " + playersNamesStatistics[i][1] + ": " +
                QString::number(playersNumStatistics[i][1]) + " (" + QString::number(percentage[1]) + "%)\n";
        curStr += "        Нічия: " + QString::number(playersNumStatistics[i][2]) +
                " (" + QString::number(percentage[2]) + "%)\n";
        if (playersNumStatistics[i][0] == playersNumStatistics[i][1]){
            curStr += "За загальним рахунком, нічия!\n";
        }
        else if (playersNumStatistics[i][0] > playersNumStatistics[i][1]){
            curStr += "За загальним рахунком,\nперемога за гравцем " + playersNamesStatistics[i][0] + "!\n";
        }
        else{
            curStr += "За загальним рахунком,\nперемога за гравцем " + playersNamesStatistics[i][1] + "!\n";
        }
        curStr += "----------------------------------------------------------------\n";
    }
    playersGameStatistics = curStr + playersGameStatistics;
    howManyGameIsInPlayersStatistics = currentGamesAmount;
}


    // Функції для обчислень

int MainWindow::numToRowIndex(int num)
{
    return (num - 1) / 3;
}

int MainWindow::numToColIndex(int num)
{
    return (num - 1) % 3;
}

int MainWindow::rowColIndexToNum(int row, int col)
{
    return row*3 + (col + 1);
}


    // Стилі кнопок

void MainWindow::setCrossNoughtStatus(int indexButton)
{
    if (indexButton == 0){
        ui->crossButton->setStyleSheet(StyleHelper::getCrossButtonStyle());
        ui->noughtButton->setStyleSheet(StyleHelper::getNoughtButtonActiveStyle());
    }
    else{
        ui->crossButton->setStyleSheet(StyleHelper::getCrossButtonActiveStyle());
        ui->noughtButton->setStyleSheet(StyleHelper::getNoughtButtonStyle());
    }
}

void MainWindow::setFriendComputerGameButtonStatus(int indexButton)
{
    if (indexButton == 0){
        ui->FriendGameButton->setStyleSheet(StyleHelper::getChoosePlayerActiveButtonStyle());
        ui->ComputerGameButton->setStyleSheet(StyleHelper::getChooseComputerButtonStyle());
    }
    else{
        ui->FriendGameButton->setStyleSheet(StyleHelper::getChoosePlayerButtonStyle());
        ui->ComputerGameButton->setStyleSheet(StyleHelper::getChooseComputerActiveButtonStyle());
    }
}

void MainWindow::setEasyMiddleDifficultButtonStatus(int indexButton)
{
    switch (indexButton) {
    case 0:
        ui->easyChoiceButton->setStyleSheet(StyleHelper::getEasyChoiceActiveButtonStyle());
        ui->middleChoiceButton->setStyleSheet(StyleHelper::getMiddleChoiceButtonStyle());
        ui->difficultChoiceButton->setStyleSheet(StyleHelper::getDifficultChoiceButtonStyle());
        ui->easyChoiceButton->setDisabled(true);
        ui->middleChoiceButton->setDisabled(false);
        ui->difficultChoiceButton->setDisabled(false);
        break;

    case 1:
        ui->easyChoiceButton->setStyleSheet(StyleHelper::getEasyChoiceButtonStyle());
        ui->middleChoiceButton->setStyleSheet(StyleHelper::getMiddleChoiceActiveButtonStyle());
        ui->difficultChoiceButton->setStyleSheet(StyleHelper::getDifficultChoiceButtonStyle());
        ui->easyChoiceButton->setDisabled(false);
        ui->middleChoiceButton->setDisabled(true);
        ui->difficultChoiceButton->setDisabled(false);

        break;

    case 2:
        ui->easyChoiceButton->setStyleSheet(StyleHelper::getEasyChoiceButtonStyle());
        ui->middleChoiceButton->setStyleSheet(StyleHelper::getMiddleChoiceButtonStyle());
        ui->difficultChoiceButton->setStyleSheet(StyleHelper::getDifficultChoiceActiveButtonStyle());
        ui->easyChoiceButton->setDisabled(false);
        ui->middleChoiceButton->setDisabled(false);
        ui->difficultChoiceButton->setDisabled(true);
        break;

    default:
        break;
    }
}

void MainWindow::playFieldButtonStyle(int row, int col, QString style)
{
    QGridLayout* grid = qobject_cast <QGridLayout*>(ui->tabPlayField->layout());
    QPushButton* button = qobject_cast <QPushButton*>(grid->itemAtPosition(row, col)->widget());
    button->setStyleSheet(style);
}

