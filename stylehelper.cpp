#include "stylehelper.h"

QString StyleHelper::getMainWindowStyle()
{
    return "QWidget{"
           "    background-image: url(:/tictactoe/images/dark_calm_blue_texture.png);"
            "}";
}

QString StyleHelper::getTabWidgetStyle()
{
    return "QWidget{"
           "    background: none;"
           "    background-image: url(:/tictactoe/images/dark_blue_texture.png);"
           "}"
           "QWidget::pane{"
           "    border: none;"
           "}";
}

QString StyleHelper::getTabAboutGameStyle()
{
    return "QLabel{"
           "    background: none;"
           "    background-color: #8cd7ff;"
           "    font-family: 'Arial Black';"
           "    font-size: 14px;"
           "    color: #203e25;"
           "    padding-left: 10px;"
           "    padding-right: 10px;"
           "    padding-top: 2px;"
           "    padding-bottom: 2px;"
           "    font-weight: bold;"
           "}"
           "QScrollArea{"
           "    border: 2px solid #2b8c57;"
           "}"

           "QScrollBar{"
           "    width: 22px;"
           "    border-left: 2px solid #2b8c57;"
           "    background-color: #135ae7;"
           "    padding: 1px;"
           "}"
           "QScrollBar::sub-line, QScrollBar::add-line{"
           "    background: none;"
           "    border: none;"
           "    height: 0px;"
           "}"
           "QScrollBar::sub-page, QScrollBar::add-page{"
           "    background-color: #104b35;"
           "}"
           "QScrollBar::handle {"
           "    border: 2px solid #405f29;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(94, 215, 217, 255), stop:1 rgba(124, 239, 104, 255));"
           "    height: 10px;"
           "}"
           "QScrollBar::handle:hover {"
            "    border: 2px solid #649440;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(71, 252, 255, 255), stop:1 rgba(86, 242, 59, 255));"
           "}"
           "QScrollBar::handle:pressed {"
            "    border: 2px solid #2f461e;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(37, 187, 189, 255), stop:1 rgba(67, 209, 42, 255));"
           "}";
}

QString StyleHelper::getStartButtonStyle()
{
    return "QPushButton{"
           "    color: #114fd3;"
           "    background: none;"
           "    border: none;"
           "    border: 2px solid #008d0c;"
           "    border-radius: 10px;"
           "    font-family: 'Arial Black';"
           "    font-size: 22px;"
           "    background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(95, 225, 156, 255), stop:1 rgba(152, 225, 57, 255))"
           "}"
           "QPushButton#LetsPlayButton{"
           "    border-bottom-left-radius: 0px;"
           "    border-bottom-right-radius: 0px;"
           "    border-bottom: none;"
           "}"
           "QPushButton::hover{"
           "    color: #135ae7;"
           "    background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(102, 241, 167, 255), stop:1 rgba(169, 249, 63, 255));"
           "    border: 2px solid #05df88;"
           "}"
           "QPushButton::pressed{"
           "    color: #0d3d9c;"
           "    background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(80, 189, 131, 255), stop:1 rgba(134, 194, 49, 255));"
           "    border: 2px solid #007009;"
           "}";
}

QString StyleHelper::getStartLoseButtonStyle()
{
    return getStartButtonStyle() +
           "QPushButton{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0.988636, x2:1, y2:0, stop:0.00568182 rgba(170, 81, 146, 255), stop:1 rgba(194, 97, 59, 255));"
           "    border: 2px solid #862f3f;"
           "    color: #2a0644;"
           "}"
           "QPushButton::hover{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0.988636, x2:1, y2:0, stop:0.00568182 rgba(207, 98, 178, 255), stop:1 rgba(231, 113, 71, 255));"
           "    border: 2px solid #b13e55;"
           "    color: #3c0963;"
           "}"
           "QPushButton::pressed{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0.988636, x2:1, y2:0, stop:0.00568182 rgba(135, 64, 116, 255), stop:1 rgba(159, 78, 49, 255));"
           "    border: 2px solid #5f212e;"
           "    color: #1e0431;"
           "}";
}

QString StyleHelper::getNoughtButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(55, 177, 221, 255), stop:1 rgba(45, 234, 155, 255));"
           "    background-image: url(:/tictactoe/images/little_nought_try1.com.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    border: none;"
           "    border: 2px solid #0037fc;"
           "    border-left: 1px solid #0037fc;"
           "    border-bottom-right-radius: 10px;"
           "}"
           "QPushButton::hover{"
           "    background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(63, 207, 255, 255), stop:1 rgba(55, 255, 155, 255));"
           "    border: 2px solid #0771fc;"
           "    border-left: 1px solid #0771fc;"
           "}"
           "QPushButton::pressed{"
           "    background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(36, 118, 194, 255), stop:1 rgba(33, 173, 112, 255));"
           "    border: 2px solid #002cbd;"
           "    border-left: 1px solid #002cbd;"
           "}";
}

QString StyleHelper::getCrossButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(55, 177, 221, 255), stop:1 rgba(45, 234, 155, 255));"
           "    background-image: url(:/tictactoe/images/little_cross_try1.com.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    border: none;"
           "    border: 2px solid #0037fc;"
           "    border-right: 1px solid #0037fc;"
           "    border-bottom-left-radius: 10px;"
           "}"
           "QPushButton::hover{"
           "    background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(63, 207, 255, 255), stop:1 rgba(55, 255, 155, 255));"
           "    border: 2px solid #0771fc;"
           "    border-right: 1px solid #0771fc;"
           "}"
           "QPushButton::pressed{"
           "    background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(36, 118, 194, 255), stop:1 rgba(33, 173, 112, 255));"
           "    border: 2px solid #002cbd;"
           "    border-right: 1px solid #002cbd;"
           "}";
}

QString StyleHelper::getNoughtButtonActiveStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(36, 118, 194, 255), stop:1 rgba(33, 173, 112, 255));"
           "    background-image: url(:/tictactoe/images/little_nought_try1.com.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    border: 2px solid #002cbd;"
           "    border-left: 1px solid #002cbd;"
           "    border-bottom-right-radius: 10px;"
           "}";
}

QString StyleHelper::getCrossButtonActiveStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(36, 118, 194, 255), stop:1 rgba(33, 173, 112, 255));"
           "    background-image: url(:/tictactoe/images/little_cross_try1.com.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    border: 2px solid #002cbd;"
           "    border-right: 1px solid #002cbd;"
           "    border-bottom-left-radius: 10px;"
           "}";
}

QString StyleHelper::getEmptyPlayFieldButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.3, fx:0.5, fy:0.5, stop:0 rgba(140, 206, 69, 255), stop:0.586395 rgba(74, 195, 143, 255), stop:1 rgba(41, 173, 162, 255));"
           "    border: none;"
           "    border: 2px solid #000981;"
           "}"
           "QPushButton::hover{"
           "    background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.3, fx:0.5, fy:0.5, stop:0.00627746 rgba(134, 209, 59, 255), stop:0.914773 rgba(34, 255, 145, 255));"
           "}"
           "QPushButton::pressed{"
           "    background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.3, fx:0.5, fy:0.5, stop:0.00568182 rgba(109, 167, 47, 255), stop:0.914773 rgba(34, 255, 145, 255));"
           "}";
}

QString StyleHelper::getCrossPlayButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    border: none;"
           "    border: 2px solid #000981;"
           "    background-image: url(:/tictactoe/images/large_cross_try1.com.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "}";
}

QString StyleHelper::getCrossPlayFieldButtonStyle()
{
    return getCrossPlayButtonStyle() +
            "QPushButton{"
           "    background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.3, fx:0.5, fy:0.5, stop:0.00627746 rgba(134, 209, 59, 255), stop:0.914773 rgba(34, 255, 145, 255));"
           "}";
}

QString StyleHelper::getCrossEndPlayFieldButtonStyle()
{
    return getCrossPlayButtonStyle() +
           "QPushButton{"
           "    background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.3, fx:0.5, fy:0.5, stop:0.00568182 rgba(255, 165, 123, 255), stop:0.914773 rgba(233, 65, 13, 255));"
           "}";
}

QString StyleHelper::getCrossDrawPlayFieldButtonStyle()
{
    return getCrossPlayButtonStyle() +
           "QPushButton{"
           "    background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.3, fx:0.5, fy:0.5, stop:0.005 rgba(151, 213, 220, 255), stop:0.914 rgba(0, 200, 187, 255));"
           "}";
}

QString StyleHelper::getNoughtPlayButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    border: none;"
           "    border: 2px solid #000981;"
           "    background-image: url(:/tictactoe/images/large_nought_try2.com.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "}";
}

QString StyleHelper::getNoughtPlayFieldButtonStyle()
{
    return getNoughtPlayButtonStyle() +
           "QPushButton{"
           "    background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.3, fx:0.5, fy:0.5, stop:0.00627746 rgba(134, 209, 59, 255), stop:0.914773 rgba(34, 255, 145, 255));"
           "}";
}

QString StyleHelper::getNoughtEndPlayFieldButtonStyle()
{
    return getNoughtPlayButtonStyle() +
           "QPushButton{"
           "    background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.3, fx:0.5, fy:0.5, stop:0.00568182 rgba(255, 165, 123, 255), stop:0.914773 rgba(233, 65, 13, 255));"
           "}";
}

QString StyleHelper::getNoughtDrawPlayFieldButtonStyle()
{
    return getNoughtPlayButtonStyle() +
           "QPushButton{"
           "    background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.3, fx:0.5, fy:0.5, stop:0.005 rgba(151, 213, 220, 255), stop:0.914 rgba(0, 200, 187, 255));"
           "}";
}

QString StyleHelper::getChooseButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(43, 173, 230, 255), stop:1 rgba(34, 235, 185, 255));"
           "    border: none;"
           "    border: 2px solid #082687;"
           "    font-family: 'Arial Black';"
           "    font-size: 19px;"
           "    color: #0b30ac;"
           "}"
           "QPushButton::hover{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(47, 188, 250, 255), stop:1 rgba(36, 250, 196, 255));"
           "    color: #0d39cb;"
           "    border-color: #0c3dcf;"
           "}"
           "QPushButton::pressed{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(34, 137, 182, 255), stop:1 rgba(25, 177, 139, 255));"
           "    color: #082687;"
           "    border-color: #051955;"
           "}";
}

QString StyleHelper::getChooseActiveButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(34, 137, 182, 255), stop:1 rgba(25, 177, 139, 255));"
           "    border: none;"
           "    border: 2px solid #051955;"
           "    font-family: 'Arial Black';"
           "    font-size: 19px;"
           "    color: #082687;"
           "}";
}

QString StyleHelper::getChoosePlayerButtonStyle()
{
    return getChooseButtonStyle() +
           "QPushButton{"
           "    border-right-width: 1px;"
           "    border-bottom-left-radius: 10px;"
           "    border-top-left-radius: 10px;"
           "}";
}

QString StyleHelper::getChoosePlayerActiveButtonStyle()
{
    return getChooseActiveButtonStyle() +
           "QPushButton{"
           "    border-right-width: 1px;"
           "    border-bottom-left-radius: 10px;"
           "    border-top-left-radius: 10px;"
           "}";
}

QString StyleHelper::getChooseComputerButtonStyle()
{
    return getChooseButtonStyle() +
           "QPushButton{"
           "    border-left-width: 1px;"
           "    border-bottom-right-radius: 10px;"
           "    border-top-right-radius: 10px;"
           "}";
}

QString StyleHelper::getChooseComputerActiveButtonStyle()
{
    return getChooseActiveButtonStyle() +
           "QPushButton{"
           "    border-left-width: 1px;"
           "    border-bottom-right-radius: 10px;"
           "    border-top-right-radius: 10px;"
           "}";
}

QString StyleHelper::getLetsPlayChoiceButtonStyle()
{
    return getChooseButtonStyle() +
           "QPushButton{"
           "    border-radius: 10px;"
           "}";
}

QString StyleHelper::getLetsPlayChoiceActiveButtonStyle()
{
    return getChooseActiveButtonStyle() +
           "QPushButton{"
           "    border-radius: 10px;"
           "}";
}

QString StyleHelper::getLineEditChoiceStyle()
{
    return "QLineEdit{"
           "    background: none;"
           "    background-color: #6cb67f;"
           "    border: none;"
           "    border: 2px solid #157c4e;"
           "    border-radius: 3px;"
           "    font-family: 'Arial Black';"
           "    font-size: 24px;"
           "    color: #273822;"
           "}"
           "QLineEdit::hover{"
           "    border-color: #0d4b2f;"
           "}"
           "QLineEdit::focus{"
           "    border-color: #24d686;"
           "    background-color: #6cb67f;"
           "}";
}

QString StyleHelper::getChooseGamesLabelStyle()
{
    return "QLabel{"
           "    color: #6bffb0;"
           "    font-family: 'Arial Black';"
           "    font-size: 21px;"
           "    border: 1px solid #6bffb0;"
           "}";
}

QString StyleHelper::chooseCatLabelStyle()
{
    return "QLabel{"
           "    background-image: url(:/tictactoe/images/imgonline-com-ua-Resize-v8ffI2paiqs.jpg);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    padding-bottom: 10px;"
           "}";
}

QString StyleHelper::getEasyChoiceButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(67, 184, 129, 255), stop:1 rgba(97, 233, 38, 255));"
           "    border-bottom-left-radius: 10px;"
           "    border-bottom-right-radius: 10px;"
           "    border-top-left-radius: 10px;"
           "    border: none;"
           "    border: 2px solid #075d1b;"
           "    font-family: 'Arial Black';"
           "    font-size: 19px;"
           "    color: #075d1b;"
           "}"
           "QPushButton::hover{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(81, 222, 156, 255), stop:1 rgba(105, 253, 42, 255));"
           "    color: #097320;"
           "    border: 2px solid #097320;"
           "}"
           "QPushButton::pressed{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(55, 151, 106, 255), stop:1 rgba(88, 211, 35, 255));"
           "    color: #04350e;"
           "    border: 2px solid #04350e;"
           "}";
}

QString StyleHelper::getEasyChoiceActiveButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(55, 151, 106, 255), stop:1 rgba(88, 211, 35, 255));"
           "    border-bottom-left-radius: 10px;"
           "    border-bottom-right-radius: 10px;"
           "    border-top-left-radius: 10px;"
           "    border: none;"
           "    border: 2px solid #04350e;"
           "    font-family: 'Arial Black';"
           "    font-size: 19px;"
           "    color: #04350e;"
           "}";
}

QString StyleHelper::getMiddleChoiceButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(218, 218, 37, 255), stop:1 rgba(216, 189, 36, 255));"
           "    border-top-left-radius: 10px;"
           "    border-bottom-right-radius: 10px;"
           "    border: none;"
           "    border: 2px solid #606206;"
           "    font-family: 'Arial Black';"
           "    font-size: 19px;"
           "    color: #606206;"
           "}"
           "QPushButton::hover{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(246, 246, 42, 255), stop:1 rgba(228, 199, 38, 255));"
           "    color: #787a08;"
           "    border: 2px solid #787a08;"
           "}"
           "QPushButton::pressed{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(197, 197, 33, 255), stop:1 rgba(188, 164, 31, 255));"
           "    color: #434304;"
           "    border: 2px solid #434304;"
           "}";
}

QString StyleHelper::getMiddleChoiceActiveButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(197, 197, 33, 255), stop:1 rgba(188, 164, 31, 255));"
           "    border-bottom-right-radius: 10px;"
           "    border-top-left-radius: 10px;"
           "    border: none;"
           "    border: 2px solid #434304;"
           "    font-family: 'Arial Black';"
           "    font-size: 19px;"
           "    color: #434304;"
           "}";
}

QString StyleHelper::getDifficultChoiceButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(218, 107, 33, 255), stop:1 rgba(171, 83, 28, 255));"
           "    border-bottom-right-radius: 10px;"
           "    border-top-right-radius: 10px;"
           "    border-top-left-radius: 10px;"
           "    border: none;"
           "    border: 2px solid #6c0000;"
           "    font-family: 'Arial Black';"
           "    font-size: 19px;"
           "    color: #6c0000;"
           "}"
           "QPushButton::hover{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(237, 116, 36, 255), stop:1 rgba(199, 96, 33, 255));"
           "    color: #8b0000;"
           "    border: 2px solid #8b0000;"
           "}"
           "QPushButton::pressed{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(184, 90, 28, 255), stop:1 rgba(140, 68, 23, 255));"
           "    color: #4b0000;"
           "    border: 2px solid #4b0000;"
           "}";
}

QString StyleHelper::getDifficultChoiceActiveButtonStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(184, 90, 28, 255), stop:1 rgba(140, 68, 23, 255));"
           "    border-bottom-right-radius: 10px;"
           "    border-top-right-radius: 10px;"
           "    border-top-left-radius: 10px;"
           "    border: none;"
           "    border: 2px solid #4b0000;"
           "    font-family: 'Arial Black';"
           "    font-size: 19px;"
           "    color: #4b0000;"
           "}";
}

QString StyleHelper::getEmptyLabelStyle()
{
    return "QLabel{"
           "}";
}

QString StyleHelper::getLetsPlayLabelStyle()
{
    return "QLabel{"
           "    font-family: 'Roboto MediumItalic';"
           "    font-size: 18px;"
           "    background: none;"
           "    border-bottom-left-radius: 5px;"
           "    border-bottom-right-radius: 5px;"
           "}";
}

QString StyleHelper::getLetsPlayLabelStyleDraw()
{
    return getLetsPlayLabelStyle() +
           "QLabel{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(57, 200, 171, 255), stop:1 rgba(97, 222, 218, 255));"
           "}";
}

QString StyleHelper::getLetsPlayLabelStyleLose()
{
    return getLetsPlayLabelStyle() +
           "QLabel{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(200, 100, 122, 255), stop:1 rgba(255, 133, 129, 255));"
           "}";
}

QString StyleHelper::getLetsPlayLabelStyleWin()
{
    return getLetsPlayLabelStyle() +
           "QLabel{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(83, 200, 47, 255), stop:1 rgba(152, 222, 48, 255));"
           "}";
}

QString StyleHelper::getLetsPlayLabelStyleTurnChange()
{
    return getLetsPlayLabelStyle() +
           "QLabel{"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(114, 152, 215, 255), stop:1 rgba(110, 232, 244, 255));"
           "}";
}



QString StyleHelper::getKittyLabelStyle()
{
    return "QLabel{"
           "    background: none;"
           "    background-image: url(:/tictactoe/images/imgonline-com-ua-Resize-v1ml0tJoawRibh.jpg);"
           "    background-repeat: no-repeat;"
           "    border-radius: 10px;"
           "    color: #00008a;"
           "    font-family: 'Arial Black';"
           "    font-size: 23px;"
           "}";
}

QString StyleHelper::getMainLabelStyle()
{
    return "QLabel{"
           "    color: #1c04a3;"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(48, 162, 231, 255), stop:1 rgba(147, 211, 226, 255));"
           "    border-top-right-radius: 10px;"
           "    border-top-left-radius: 10px;"
           "    font-family: 'Arial Black';"
           "    font-size: 20px;"
           "}";
}

QString StyleHelper::descrWelcomeLabelStyle()
{
    return "QLabel{"
           "    font-family: 'Roboto-Medium';"
           "    font-size: 25px;"
           "}";
}

QString StyleHelper::descrTitleLabelStyle()
{
    return "QLabel{"
           "    font-family: 'Roboto-Medium';"
           "    font-size: 22px;"
           "    text-decoration: underline overline;"
           "}";
}

QString StyleHelper::descrTextLabelStyle()
{
    return "QLabel{"
           "    font-family: 'Roboto-Medium';"
           "    font-size: 18px;"
           "}";
}

QString StyleHelper::descrCatLabelStyle()
{
    return "QLabel{"
           "    background-image: url(:/tictactoe/images/imgonline-com-ua-Resize-LTkijoQbR4Y4027s.jpg);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    padding-bottom: 10px;"
           "}";
}

QString StyleHelper::statCatLabelStyle()
{
    return "QLabel{"
           "    background-image: url(:/tictactoe/images/imgonline-com-ua-Resize-c4e3XhddBGpP.jpg);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    padding-bottom: 10px;"
           "}";
}
