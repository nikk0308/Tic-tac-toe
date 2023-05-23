#include "compChoiceDifficult.h"

// Private functions


 int CompChoice::lineCombinations[][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {1, 4, 7},
    {2, 5, 8},
    {3, 6, 9},
    {1, 5, 9},
    {3, 5, 7},
};

int CompChoice::numToRowIndex(int num)
{
    return (num - 1) / 3;
}

int CompChoice::numToColIndex(int num)
{
    return (num - 1) % 3;
}

int CompChoice::rowColIndexToNum(int row, int col)
{
    return row*3 + (col + 1);
}

int CompChoice::noZeroSymbolsInArr(int *array, int arrSize)
{
    int counter = 0;
    for (int i = 0; i < arrSize; i++){
        if (array[i] != 0){
            counter++;
        }
    }
    return counter;
}

int CompChoice::chooseRandIndexInArr(int *array, int arrSize)
{
    int localNoZeroIndexArr[4][9];
    int firstCounterNoZeroSymbols = 0;
    int secondCounterNoZeroSymbols = 0;

    for (int i = 0; i < 4; i++){
        for (int k = 0; k < 9; k++){
            localNoZeroIndexArr[i][k] = 0;
        }
    }


    for (int i = 0; i < arrSize; i++){ // Знаходимо всі індекси, куди можна поставити символ та зсуваємо їх до початку
        if (array[i] != 0){
            localNoZeroIndexArr[0][firstCounterNoZeroSymbols] = array[i];
            firstCounterNoZeroSymbols++;
        }
    }

    secondCounterNoZeroSymbols = firstCounterNoZeroSymbols;
    memcpy(localNoZeroIndexArr[1], localNoZeroIndexArr[0], 36);

    //----------

    // Видаляємо з переліку індекс 5, так як він найбільш вигідний для виграшу (можна побудувати 4 лінії)

    for (int i = 0; i < firstCounterNoZeroSymbols; i++){
        if (localNoZeroIndexArr[1][i] == 5){ // Якщо індекс 5 знайдено, формуємо другий масив, у якому зсуваємо єлементи так, щоб "знищити" 5
            for (int k = i; k < firstCounterNoZeroSymbols - 1; k++){
                localNoZeroIndexArr[1][i] = localNoZeroIndexArr[1][i + 1];
            }
            localNoZeroIndexArr[1][firstCounterNoZeroSymbols - 1] = 0;
            secondCounterNoZeroSymbols--;
            break;
        }
    }

    if (noZeroSymbolsInArr(localNoZeroIndexArr[1], 9) == 0){ // Якщо в масиві індексів не залишилось не 0 значень (всі можливі випадки поставити символ призводять до виграшу комп'ютера, обирається рандомний індекс з першого масиву)
        return localNoZeroIndexArr[0][rand() % firstCounterNoZeroSymbols];
    }

    //----------

    // Видаляємо з переліку всі інші непарні індекси також, так як вони більш менш вигідні для виграшу (можна побудувати 3 лінії)

    firstCounterNoZeroSymbols = secondCounterNoZeroSymbols;
    memcpy(localNoZeroIndexArr[2], localNoZeroIndexArr[1], 36);

    for (int i = 0; i < firstCounterNoZeroSymbols; i++){
        if (localNoZeroIndexArr[2][i] % 2 == 1){
            localNoZeroIndexArr[2][i] = 0;
            secondCounterNoZeroSymbols--;
        }
    }

    if (noZeroSymbolsInArr(localNoZeroIndexArr[2], 9) == 0){ // Якщо в масиві індексів не залишилось не 0 значень (всі можливі випадки поставити символ призводять до виграшу комп'ютера, обирається рандомний індекс з першого масиву)
        return localNoZeroIndexArr[1][rand() % firstCounterNoZeroSymbols];
    }

    //-------------

    // Зсуваємо індекси, що залишилися (парні), які є найбільш вигідними для постановки символа (можна утворити всього лиш 2 лінії)

    secondCounterNoZeroSymbols = 0;
    for (int i = 0; i < 9; i++){
        if (localNoZeroIndexArr[2][i] != 0){
            localNoZeroIndexArr[3][secondCounterNoZeroSymbols] = localNoZeroIndexArr[2][i];
            secondCounterNoZeroSymbols++;
        }
    }

    return localNoZeroIndexArr[3][rand() % secondCounterNoZeroSymbols];
}


// Public functions

int CompChoice::easyCompPlayChoice(int** field, bool computerSymbol)
{
    int choiceArr[5][9];
    int lineSymbolCounter;

    for (int i = 0; i < 9; i++){ // Заповнюємо масиви числами від 1 до 9 (всі комірки, які можуть бути) та видаляємо (перетворюємо на 0) номери заповнених комірок
        if (field[numToRowIndex(i+1)][numToColIndex(i+1)] != -1){
            choiceArr[0][i] = 0;
        }
        else{
            choiceArr[0][i] = i+1;
        }
    }

    // Перший масив - всі пусті комірки

    memcpy(choiceArr[1], choiceArr[0], 36);

    //-------------------------------------------------------------------------

    // Другий масив - пусті комірки без виграшних для комп'ютера комбінацій (два символи в ряд і пуста комірка)

    for (int i = 0; i < 8; i++){ // Чи є виграшні комбінації
        lineSymbolCounter = 0; // Оновлення лічильника дружніх символів
        for (int k = 0; k < 3; k++){ // Підрахунок кількості "дружніх" комп'ютеру символів
            if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == computerSymbol){
                lineSymbolCounter++;
            }
        }
        if (lineSymbolCounter == 2){ // У строці є два "дружніх" комп'ютеру символи
            for (int k = 0; k < 3; k++){ // Йдемо по цій строці
                if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == -1){ // Третій символ — пусте місце (там нічого немає)
                    choiceArr[1][lineCombinations[i][k] - 1] = 0; // Прибираємо цей символ з можливих для вибору
                }
            }
        }
    }
    if (noZeroSymbolsInArr(choiceArr[1], 9) == 0){ // Якщо в масиві індексів не залишилось не 0 значень (всі можливі випадки поставити символ призводять до виграшу комп'ютера, обирається рандомний індекс з першого масиву)
        return chooseRandIndexInArr(choiceArr[0], 9);
    }

    memcpy(choiceArr[2], choiceArr[1], 36);

    //--------------------------------------------------------------

    // Третій масив - Другий масив мінус пусті комірки без програшних для комп'ютера комбінацій (два символи гравця в ряд і пуста комірка)

    for (int i = 0; i < 8; i++){ // Чи є програшні комбінації
        lineSymbolCounter = 0;
        for (int k = 0; k < 3; k++){ // Підрахунок кількості "ворожих" комп'ютеру символів
            if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == !computerSymbol){
                lineSymbolCounter++;
            }
        }
        if (lineSymbolCounter == 2){ //У строці є два "ворожих" комп'ютеру символи
            for (int k = 0; k < 3; k++){ // Йдемо по цій строці
                if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == -1){ // Третій символ — пусте місце (там нічого немає)
                    choiceArr[2][lineCombinations[i][k] - 1] = 0; // Ставимо символ у пропуск щоб не програти
                }
            }
        }
    }

    if (noZeroSymbolsInArr(choiceArr[2], 9) == 0){ // Якщо в масиві індексів не залишилось не 0 значень (всі можливі випадки поставити символ призводять до виграшу комп'ютера, обирається рандомний індекс з першого масиву)
        return chooseRandIndexInArr(choiceArr[1], 9);
    }

    memcpy(choiceArr[3], choiceArr[2], 36);

    //--------------------------------------------------------------

    // Четвертий масив - Третій масив мінус вільні лінії, на яких, в теорії, можна виграти

    for (int i = 0; i < 8; i++){ // Чи є вільні лінії, на яких можна виграти (не зайняті "ворожими" символами)
        lineSymbolCounter = 0;
        for (int k = 0; k < 3; k++){ // Підрахунок кількості дружніх символів на лінії
            if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == computerSymbol){
                lineSymbolCounter++;
            }
        }
        if (lineSymbolCounter == 1){ // Сценарій із 2 дружніми символами описаний у 1 блоці, тут сценарій з одним дружнім символом
            int spaceSymbolCounter = 0; // Кількість вільних місць у строці
            for (int k = 0; k < 3; k++){ // Підрахунок кількості пропусків
                if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == -1){
                    spaceSymbolCounter++;
                }
            }
            if (spaceSymbolCounter == 2){ // У строці лише один дружній символ та два пропуски (ворожих немає)
                for (int k = 0; k < 3; k++){ // Записуємо лінію, як претендента, куди можна поставити свій символ
                // Просто скопіювати строку не можна через особливості об'єктів, необхідно копіювати поелементно
                    choiceArr[3][lineCombinations[i][k] - 1] = 0;
                }
            }
        }
    }

    if (noZeroSymbolsInArr(choiceArr[3], 9) == 0){ // Якщо в масиві індексів не залишилось не 0 значень (всі можливі випадки поставити символ призводять до виграшу комп'ютера, обирається рандомний індекс з першого масиву)
        return chooseRandIndexInArr(choiceArr[2], 9);
    }

    memcpy(choiceArr[4], choiceArr[3], 36);

    //--------------------------------------------------------------

    // П'ятий масив - Четвертий масив мінус вільні лінії, на яких, в теорії, можна програти

    for (int i = 0; i < 8; i++){ // Чи є вільні лінії, на яких можна програти (не зайняті "своїми" символами)
        lineSymbolCounter = 0;
        for (int k = 0; k < 3; k++){ // Підрахунок кількості ворожих символів на лінії
            if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == !computerSymbol){
                lineSymbolCounter++;
            }
        }
        if (lineSymbolCounter == 1){ // Сценарій із 2 ворожими символами описаний у 2 блоці, тут сценарій з одним ворожим символом
            int spaceSymbolCounter = 0; // Кількість вільних місць у строці
            for (int k = 0; k < 3; k++){ // Підрахунок кількості пропусків
                if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == -1){
                    spaceSymbolCounter++;
                }
            }
            if (spaceSymbolCounter == 2){ // У строці лише один ворожий символ та два пропуски (дружніх немає)
                for (int k = 0; k < 3; k++){ // Записуємо лінію, як претендента, куди можна поставити свій символ
                // Просто скопіювати строку не можна через особливості об'єктів, необхідно копіювати поелементно
                    choiceArr[4][lineCombinations[i][k] - 1] = 0;
                }
            }
        }
    }

    if (noZeroSymbolsInArr(choiceArr[4], 9) == 0){ // Якщо в масиві індексів не залишилось не 0 значень (всі можливі випадки поставити символ призводять до виграшу комп'ютера, обирається рандомний індекс з першого масиву)
        return chooseRandIndexInArr(choiceArr[3], 9);
    }
    else{
        return chooseRandIndexInArr(choiceArr[4], 9);
    }
}

int CompChoice::middleCompPlayChoice(int** field)
{
    int choice;
    while(1){
        int row = rand()%3, col = rand()%3;
        if (field[row][col] == -1){
            choice = rowColIndexToNum(row, col);
            break;
        }
    }
    return choice;
}

int CompChoice::difficultCompPlayChoice(int** field, bool computerSymbol, int isOver)
{
    // Позначення /**/ на початку строки позначає повернення якогось числа (для легшої орієнтації)
    int choice = 0;

    if (computerSymbol == 1 && isOver == 0){// Користувач грає за О, комп'ютер ходить перший
/**/    return ((rand() % 5 + 1) * 2) - 1; // Генерація непарного індексу від 1 до 9
    }

    else if (computerSymbol == 0 && isOver == 1){ // Користувач грає за Х, користувач ходить перший
        int playerChoice = 0;
        for (int i = 0; i < 3; i++){ // Знаходження комірки, куди користувач поставив Х
            for (int k = 0; k < 3; k++){
                if (field[i][k] == 1){
                    playerChoice = rowColIndexToNum(i, k);
                }
            }
            if (playerChoice != 0){
                break;
            }
        }

        if ((numToRowIndex(playerChoice) % 2 == 0) && (numToColIndex(playerChoice) % 2 == 0)){ // Користувач поставив Х в кут

/**/        return 5; // Комп'ютер відповідає користувачеві ходом у центр
        }

        else if (playerChoice == 5){ // Користувач поставив Х в центр
            do{ // Відповідаємо ходом у будь-який із кутів
                choice = ((rand() % 5 + 1) * 2) - 1; // Генерація непарного індексу від 1 до 9
            } while(choice == 5); // Кути розташовані в усіх непарних індексах, крім 5 (1, 3, 7, 9)

/**/        return choice;
        }

        else { // Користувач поставив Х в якусь зі сторін
            int* randChoicer = new int[3]; // Можна відповісти ходом у центр, ходом у протилежну сторону та в якийсь
            // З кутів (завжди 4 можливі варіанти). тому будемо рандомно обирати один із чотирьох
            randChoicer[0] = 5; // Додаємо варіант центру
            //randChoicer[1] = 10 - playerChoice; // Додаємо варіант протилежної сторони

            if (numToColIndex(playerChoice) == 1){ // Х користувача стоїть в першій або третій строці поля
                randChoicer[1] = playerChoice - 1; // Додаємо два прилеглих кути (зліва і справа)
                randChoicer[2] = playerChoice + 1;
            }
            else{ // Х користувача стоїть в другій строці поля
                randChoicer[1] = playerChoice - 3; // Додаємо два прилеглих кути (зверху і знизу)
                randChoicer[2] = playerChoice + 3;
            }

/**/        return randChoicer[rand() % 3]; // Обираємо випадковий варіант з тих чотирьох
        }

    }
    else if ((computerSymbol == 0) && (isOver == 3)){
/**/    if (((field[0][0] == 1 && field[2][2] == 1) || (field[0][2] == 1 && field[2][0] == 1))){// Користувач поставив Х на 2 ході у протилежний кут від початкового ходу
            return (rand() % 4 + 1) * 2; // Відповідаємо ходом у будь-яку зі сторін
        }
        if (field[1][1] == 0){ // Користувач поставив Х на 2 ході У суміжну бокову клітинку, а комп'ютер у центр
            if (field[0][1] == 1 && field[1][0] == 1){
                return 1;
            }
            else if (field[0][1] == 1 && field[1][2] == 1){
                return 3;
            }
            else if (field[2][1] == 1 && field[1][0] == 1){
                return 7;
            }
            else if (field[2][1] == 1 && field[1][2] == 1){
                return 9;
            }
        }
    }

    // Майже універсальний алгоритм постановки ходу (без перших ходів, описаних вище)

    // Чи є виграшні комбінації

    int lineSymbolCounter;
    for (int i = 0; i < 8; i++){ // Чи є виграшні комбінації
        lineSymbolCounter = 0; // Оновлення лічильника дружніх символів
        for (int k = 0; k < 3; k++){ // Підрахунок кількості "дружніх" комп'ютеру символів
            if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == computerSymbol){
                lineSymbolCounter++;
            }
        }
        if (lineSymbolCounter == 2){ // У строці є два "дружніх" комп'ютеру символи
            for (int k = 0; k < 3; k++){ // Йдемо по цій строці
                if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == -1){ // Третій символ — пусте місце (там нічого немає)
/**/                return lineCombinations[i][k]; // Ставимо символ у пропуск та виграємо
                }
            }
        }
    }

    //--------------------------------------------------------------

    // Чи є програшні комбінації

    for (int i = 0; i < 8; i++){ // Чи є програшні комбінації
        lineSymbolCounter = 0;
        for (int k = 0; k < 3; k++){ // Підрахунок кількості "ворожих" комп'ютеру символів
            if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == !computerSymbol){
                lineSymbolCounter++;
            }
        }
        if (lineSymbolCounter == 2){ //У строці є два "ворожих" комп'ютеру символи
            for (int k = 0; k < 3; k++){ // Йдемо по цій строці
                if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == -1){ // Третій символ — пусте місце (там нічого немає)
/**/                return lineCombinations[i][k]; // Ставимо символ у пропуск щоб не програти
                }
            }
        }
    }

    //--------------------------------------------------------------

    // Чи вільний центр

    if (field[1][1] == -1){ // Чи вільний центр (найбільш вигідна позиція)
/**/    return 5; // Якщо вільний, ставимо свій символ туди
    }

    //--------------------------------------------------------------

    // Чи є ще вільні лінії, на яких, в теорії, можна виграти

    int currentLinesAmount = 0; // Кількість строк, які підходять для того, щоб туди поставити свій символ
    int freeLines[8][3]; // Масив, куди ці строки зберігатимуться
    for (int i = 0; i < 8; i++){ // Чи є вільні лінії, на яких можна виграти (не зайняті "ворожими" символами)
        lineSymbolCounter = 0;
        for (int k = 0; k < 3; k++){ // Підрахунок кількості дружніх символів на лінії
            if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == computerSymbol){
                lineSymbolCounter++;
            }
        }
        if (lineSymbolCounter == 1){ // Сценарій із 2 дружніми символами описаний у 1 блоці, тут сценарій з одним дружнім символом
            int spaceSymbolCounter = 0; // Кількість вільних місць у строці
            for (int k = 0; k < 3; k++){ // Підрахунок кількості пропусків
                if (field[numToRowIndex(lineCombinations[i][k])][numToColIndex(lineCombinations[i][k])] == -1){
                    spaceSymbolCounter++;
                }
            }
            if (spaceSymbolCounter == 2){ // У строці лише один дружній символ та два пропуски (ворожих немає)
                for (int k = 0; k < 3; k++){ // Записуємо лінію, як претендента, куди можна поставити свій символ
                // Просто скопіювати строку не можна через особливості об'єктів, необхідно копіювати поелементно
                    freeLines[currentLinesAmount][k] = lineCombinations[i][k];
                }
                currentLinesAmount++;
            }
        }
    }

    if (currentLinesAmount != 0) { // Якщо є вільні лінії (один дружній символ та два пропуски)
        for (int i = 0; i < currentLinesAmount; i++) { // Прохід по вільних лініях. Прохід здійснюється лише по краях лінії
            // (кутах), оскільки, де б символ у строці не стояв, у ній завжди буде вільний кут (хоча б один). А якщо обирати
            // куди поставити свій символ (між стороною та кутом), кут буде вигіднішим, оскільки входить до складу одразу
            // трьох ліній, в той час, як сторона лише до двох
            // Тому здійснюється прохід по кутах. Вже зайняті кути (дружнім символом) заміняються у масиві ліній на нуль.
            // Це зроблено для того, щоб, коли ми випадково обирали кут, куди поставити дружній символ, він точно був пустим

            if (field[numToRowIndex(freeLines[i][0])][numToColIndex(freeLines[i][0])] != -1) { // Якщо кут не вільний, його значення в лінії замінюється
                // на 0. Так як в лініях знаходяться номери клітинок (числа від 1 до 9), коли ми будемо бачити 0, ми
                // знатимемо, що ця клітинка вже зайнята
                freeLines[i][0] = 0;
            }

            if (field[numToRowIndex(freeLines[i][2])][numToColIndex(freeLines[i][2])] != -1) { // Перевірка іншого кута строки
                freeLines[i][2] = 0;
            }
        }

        int anyIndex1, anyIndex2; // Індекс строки та колонки елемента з масиву вільних ліній
        do {
            anyIndex1 = rand() % currentLinesAmount; // Випадкова лінія з масиву ліній
            anyIndex2 = (rand() % 4 / 2) * 2; // Випадковий індекс (або 0, або 2) з обраної лінії

            if (freeLines[anyIndex1][anyIndex2] != 0){ // Якщо клітинка поля під обраним індексом пуста, ставимо туди дружній символ
/**/            return freeLines[anyIndex1][anyIndex2];
            }
        } while (true); // Якщо ж клітинка не пуста, повторюємо цикл, доки не натрапимо на пусту
    }

    //--------------------------------------------------------------

    // Якщо нічого з вищеперерахованого, обираємо рандомну пусту клітинку

/**/return middleCompPlayChoice(field);

}
