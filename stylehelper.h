#ifndef STYLEHELPER_H
#define STYLEHELPER_H

#include <QString>

class StyleHelper
{
public:
    static QString getMainWindowStyle();

    static QString getTabWidgetStyle();
    static QString getTabAboutGameStyle();

    static QString getStartButtonStyle();
    static QString getStartLoseButtonStyle();

    static QString getNoughtButtonStyle();
    static QString getCrossButtonStyle();
    static QString getNoughtButtonActiveStyle();
    static QString getCrossButtonActiveStyle();

    static QString getEmptyPlayFieldButtonStyle();

    static QString getCrossPlayButtonStyle();
    static QString getCrossPlayFieldButtonStyle();
    static QString getCrossEndPlayFieldButtonStyle();
    static QString getCrossDrawPlayFieldButtonStyle();

    static QString getNoughtPlayButtonStyle();
    static QString getNoughtPlayFieldButtonStyle();
    static QString getNoughtEndPlayFieldButtonStyle();
    static QString getNoughtDrawPlayFieldButtonStyle();

    static QString getChooseButtonStyle();
    static QString getChoosePlayerButtonStyle();
    static QString getChooseComputerButtonStyle();
    static QString getLetsPlayChoiceButtonStyle();
    static QString getChooseActiveButtonStyle();
    static QString getChoosePlayerActiveButtonStyle();
    static QString getChooseComputerActiveButtonStyle();
    static QString getLetsPlayChoiceActiveButtonStyle();

    static QString getLineEditChoiceStyle();

    static QString getChooseGamesLabelStyle();

    static QString chooseCatLabelStyle();

    static QString getEasyChoiceButtonStyle();
    static QString getEasyChoiceActiveButtonStyle();
    static QString getMiddleChoiceButtonStyle();
    static QString getMiddleChoiceActiveButtonStyle();
    static QString getDifficultChoiceButtonStyle();
    static QString getDifficultChoiceActiveButtonStyle();

    static QString getEmptyLabelStyle();
    static QString getLetsPlayLabelStyle();
    static QString getLetsPlayLabelStyleDraw();
    static QString getLetsPlayLabelStyleLose();
    static QString getLetsPlayLabelStyleWin();
    static QString getLetsPlayLabelStyleTurnChange();

    static QString getKittyLabelStyle();
    static QString getMainLabelStyle();

    static QString descrWelcomeLabelStyle();
    static QString descrTitleLabelStyle();
    static QString descrTextLabelStyle();
    static QString descrCatLabelStyle();
    static QString statCatLabelStyle();

};

#endif // STYLEHELPER_H
