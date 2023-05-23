#ifndef COMPCHOICEDIFFICULT_H
#define COMPCHOICEDIFFICULT_H

#include <mainwindow.h>

class CompChoice{
private:

    static int lineCombinations[8][3];

    static int numToRowIndex(int num);
    static int numToColIndex(int num);
    static int rowColIndexToNum(int row, int col);
    static int noZeroSymbolsInArr(int* array, int arrSize);
    static int chooseRandIndexInArr(int* array, int arrSize);

public:
    static int easyCompPlayChoice(int** field, bool computerSymbol);
    static int middleCompPlayChoice(int** field);
    static int difficultCompPlayChoice(int** field, bool computerSymbol, int isOver);
};

#endif // COMPCHOICEDIFFICULT_H
