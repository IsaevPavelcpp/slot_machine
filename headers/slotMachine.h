
#ifndef SLOT_MACHINE_SLOTMACHINE_H
#define SLOT_MACHINE_SLOTMACHINE_H

#include "Table.h"


class slotMachine {
    ///основное окно выполнения
    sf::RenderWindow window;
    sf::Image imWindow;
    sf::Texture txWindow;
    sf::Sprite spWindow;
    sf::Image icon;

    ///текстуры для игровых кнопок
    sf::Image imSpinButton;
    sf::Texture txSpinButton;

    sf::Image imStopButton;
    sf::Texture txStopButton;

    sf::Image imBetUpButton;
    sf::Texture txBetUpButton;

    sf::Image imBetDownButton;
    sf::Texture txBetDownButton;

    sf::Image imChangeButtonUp;
    sf::Texture txChangeButtonUp;

    sf::Image imChangeButtonDown;
    sf::Texture txChangeButtonDown;

    ///текстуры для окна счета
    sf::Image imWindowScore;
    sf::Texture txWindowScore;
    sf::Sprite spWindowScore;
    ///шрифты
    sf::Font fontNumber;
    sf::Font fontString;
    ///банк
    sf::Text countBank;
    sf::Text textBank;
    ///ставка игрока
    sf::Text textBet;
    sf::Text countBet;
    ///коэфициент увеличения/уменьшения ставки
    sf::Text textCharge;
    sf::Text countCharge;


    /// кнопки управления
    sf::Sprite buttonSpin;
    sf::Sprite buttonStop;
    sf::Sprite buttonBetUp;
    sf::Sprite buttonBetDown;
    sf::Sprite buttonChangeUp;
    sf::Sprite buttonChangeDown;


    //Музыка и звуки
    sf::Music mainMusic;
    sf::SoundBuffer sB[2];
    sf::Sound sound;

    Table my_table; /// игровое окно
    int state_machine = 0; /// режимы барабана (2 - остановка, 1 - вращение, 0 - ожидание)
    bool buttonClick = false;
    int countSpin = 0;
    int cash = 0;
    bool calculateStart = false;
    int bet = 100; // ставка
    int positionBet = 0; // позиция в массиве на сколько увеличить ставку
    int howAdd[7] = {100,500,1000,5000,10000,100000}; // возможные варианты увеличения ставки



    void setMainWindow();
    void setCombinationWindow();
    void setBankWindow();
    void setBetWindow();
    void setChargeWindow();
    void customButtonStart();
    void customButtonStop();
    void customButtonBetUp();
    void customButtonBetDown();
    void customButtonChargeUp();
    void customButtonChargeDown();
    void xBet(int charge);
    void setUpDown(int shift);
    void renderingWindow();
    void updatingInf();
    void returnButton();
    void turnOnRotation();
    void turnOffRotation();
    void setBetUp();
    void setBetDown();
    void setChargeUp();
    void setChargeDown();
public:
    slotMachine(int cash_);
    void work();
};


#endif //SLOT_MACHINE_SLOTMACHINE_H
