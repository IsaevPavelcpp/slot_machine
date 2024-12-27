#include "../headers/slotMachine.h"

slotMachine::slotMachine(int cash_)
{
    cash = cash_;/// установка банка игрока

    mainMusic.openFromFile(R"(..\resources\sounds\mainMusic.mp3)");
    mainMusic.setLoop(true);
    mainMusic.setVolume(40);
    mainMusic.play();

    sB[0].loadFromFile(R"(..\resources\sounds\pressButton.mp3)");
    sB[1].loadFromFile(R"(..\resources\sounds\slotmachineSound.mp3)");

    setMainWindow();///установка основного окна и иконки

    ///настройка окон
    setCombinationWindow();
    setBankWindow();
    setBetWindow();
    setChargeWindow();

    ///настройки кнопок
    customButtonStart();
    customButtonStop();
    customButtonBetUp();
    customButtonBetDown();
    customButtonChargeUp();
    customButtonChargeDown();

}

void slotMachine::setMainWindow()
{
    window.create(sf::VideoMode(1300,950), "Bandit");
    imWindow.loadFromFile(R"(..\resources\textures\mainScreen.png)");

    txWindow.loadFromImage(imWindow);
    spWindow.setTexture(txWindow);
    spWindow.setScale(1.1,1.15);
    spWindow.setPosition(300,0);

    /// установка иконки
    icon.loadFromFile(R"(..\resources\textures\icon.jpg)");
    window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
}
void slotMachine::setCombinationWindow()
{
    imWindowScore.loadFromFile(R"(..\resources\textures\fieldWin.jpg)");
    txWindowScore.loadFromImage(imWindowScore);
    spWindowScore.setTexture(txWindowScore);
    spWindowScore.setPosition(0,0);
    spWindowScore.setScale(0.65 ,0.89);
}
void slotMachine::setBankWindow()
{
    fontString.loadFromFile(R"(..\resources\fonts\tetsuya-demo.regular.ttf)");
    textBank.setFont(fontString);
    textBank.setString(L"Bank");
    textBank.setFillColor(sf::Color::Red);
    textBank.setOrigin(50,80);
    textBank.setPosition(1035, 650);
    ///
    fontNumber.loadFromFile(R"(..\resources\fonts\fontNumber.ttf)");
    countBank.setFont(fontNumber);
    countBank.setFillColor(sf::Color::Red);
    countBank.setCharacterSize(40);
    countBank.setOrigin(50,80);
    countBank.setPosition(940,700);
}
void slotMachine::setBetWindow()
{
    textBet.setFont(fontString);
    textBet.setString(L"BET");
    textBet.setFillColor(sf::Color::Red);
    textBet.setOrigin(50,80);
    textBet.setPosition(790, 650);
    ///
    countBet.setFont(fontNumber);
    countBet.setFillColor(sf::Color::Red);
    countBet.setOrigin(50,80);
    countBet.setPosition(760,700);
}
void slotMachine::setChargeWindow()
{
    textCharge.setFont(fontString);
    textCharge.setString(L"Charge");
    textCharge.setFillColor(sf::Color::Red);
    textCharge.setOrigin(50,80);
    textCharge.setPosition(595, 650);
    ///
    countCharge.setFont(fontNumber);
    countCharge.setFillColor(sf::Color::Red);
    countCharge.setOrigin(50,80);
    countCharge.setPosition(585,700);
}

void slotMachine::customButtonStart()
{
    imSpinButton.loadFromFile(R"(..\resources\textures\buttonSpin.png)");
    txSpinButton.loadFromImage(imSpinButton);
    buttonSpin.setTexture(txSpinButton);
    buttonSpin.setTextureRect(sf::IntRect(0,0,650,650));
    buttonSpin.setScale(0.2,0.2);
    buttonSpin.setPosition(480,790);
}
void slotMachine::customButtonStop()
{
    imStopButton.loadFromFile(R"(..\resources\textures\buttonStop.png)");
    txStopButton.loadFromImage(imStopButton);
    buttonStop.setTexture(txStopButton);
    buttonStop.setTextureRect(sf::IntRect(0,0,650,650));
    buttonStop.setScale(0.2,0.2);
    buttonStop.setPosition(600,790);
}
void slotMachine::customButtonBetUp()
{
    imBetUpButton.loadFromFile(R"(..\resources\textures\buttonBetUp.png)");
    txBetUpButton.loadFromImage(imBetUpButton);
    buttonBetUp.setTexture(txBetUpButton);
    buttonBetUp.setTextureRect(sf::IntRect(0,0,650,650));
    buttonBetUp.setScale(0.2,0.2);
    buttonBetUp.setPosition(727,790);
}
void slotMachine::customButtonBetDown()
{
    imBetDownButton.loadFromFile(R"(..\resources\textures\buttonBetDown.png)");
    txBetDownButton.loadFromImage(imBetDownButton);
    buttonBetDown.setTexture(txBetDownButton);
    buttonBetDown.setTextureRect(sf::IntRect(0,0,650,650));
    buttonBetDown.setScale(0.2,0.2);
    buttonBetDown.setPosition(847,790);
}
void slotMachine::customButtonChargeUp()
{
    imChangeButtonUp.loadFromFile(R"(..\resources\textures\buttonChangeUp.png)");
    txChangeButtonUp.loadFromImage(imChangeButtonUp);
    buttonChangeUp.setTexture(txChangeButtonUp);
    buttonChangeUp.setTextureRect(sf::IntRect(0,0,650,650));
    buttonChangeUp.setScale(0.2,0.2);
    buttonChangeUp.setPosition(972,790);
}
void slotMachine::customButtonChargeDown()
{
    imChangeButtonDown.loadFromFile(R"(..\resources\textures\buttonChangeDown.png)");
    txChangeButtonDown.loadFromImage(imChangeButtonDown);
    buttonChangeDown.setTexture(txChangeButtonDown);
    buttonChangeDown.setTextureRect(sf::IntRect(0,0,650,650));
    buttonChangeDown.setScale(0.2,0.2);
    buttonChangeDown.setPosition(1092,790);
}

void slotMachine::xBet(int charge)
{
    if(positionBet >= 0 && positionBet < 6)
    {
        if((charge > 0 && bet + howAdd[positionBet] < cash))
        {
            bet += (charge * howAdd[positionBet]);
        }
        else if(bet + (howAdd[positionBet]*charge) > 0)
        {
            bet += (charge * howAdd[positionBet]);
        }
    }
    else
    {
        bet = cash;
    }
}

void slotMachine::setUpDown(int shift)
{
    if(positionBet + shift >= 0)
    {
        if(positionBet + shift > 6)
            positionBet = 0;
        else
            positionBet += shift;
    }
}

void slotMachine::renderingWindow() {
    window.draw(spWindow);
    ///отрисовка барабанов
    window.draw(my_table.sp0());
    window.draw(my_table.sp1());
    window.draw(my_table.sp2());

    /// отрисовка кнопок
    window.draw(buttonSpin);
    window.draw(buttonStop);
    window.draw(buttonBetUp);/// кнопка для увеличения ставки
    window.draw(buttonBetDown);/// кнопка уменьшения ставки
    window.draw(buttonChangeUp);/// кнопка для выбора величины увеличения ставки
    window.draw(buttonChangeDown);///кнопка для выбора величины уменьшения ставки

    ///отрисовка информационных окон и текстов
    window.draw(spWindowScore);
    window.draw(countBank);
    window.draw(textBank);
    window.draw(textBet);
    window.draw(countBet);
    window.draw(textCharge);
    window.draw(countCharge);
}

void slotMachine::updatingInf()
{
    countBank.setString(std::to_string(cash));/// обновление остатка банка игрока
    countBet.setString(std::to_string(bet));/// обновление окна BET
    /// обновление окна charge
    if(positionBet >= 0 || positionBet < 6)
    {
        countCharge.setString(std::to_string(howAdd[positionBet]));
    }
    if(positionBet == 6)
    {
        countCharge.setString(L"TOTAL");
    }
}

void slotMachine::returnButton()
{
    buttonSpin.setTextureRect(sf::IntRect(0,0,650,650));
    buttonStop.setTextureRect(sf::IntRect(0, 0, 650, 650));
    buttonBetUp.setTextureRect(sf::IntRect(0, 0, 650, 650));
    buttonBetDown.setTextureRect(sf::IntRect(0, 0, 650, 650));
    buttonChangeUp.setTextureRect(sf::IntRect(0, 0, 650, 650));
    buttonChangeDown.setTextureRect(sf::IntRect(0, 0, 650, 650));

}

void slotMachine::turnOnRotation()
{
    if (sf::IntRect(480, 790, 100, 100).contains(sf::Mouse::getPosition(window))) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sound.setBuffer(sB[1]);
            sound.setLoop(true);
            sound.play();
            cash -= bet;
            state_machine = 1;
            buttonClick = true;
            buttonSpin.setTextureRect(sf::IntRect(650, 0, 650, 650));
            my_table.switchStart(1);
            countSpin++;
            calculateStart = true;
        }
    }
}

void slotMachine::turnOffRotation()
{
    if (sf::IntRect(600, 790, 100, 100).contains(sf::Mouse::getPosition(window))) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            state_machine = 2;
            buttonClick = true;
            my_table.switchStart(2);
            buttonStop.setTextureRect(sf::IntRect(650, 0, 650, 650));
        }
    }
}

void slotMachine::setBetUp()
{
    if (sf::IntRect(972, 790, 100, 100).contains(sf::Mouse::getPosition(window))) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sound.play();
            buttonChangeUp.setTextureRect(sf::IntRect(650, 0, 650, 650));
            Sleep(300);
            setUpDown(1);
        }
    }
}

void slotMachine::setBetDown()
{
    if (sf::IntRect(1092, 790, 100, 100).contains(sf::Mouse::getPosition(window))) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sound.play();
            buttonChangeDown.setTextureRect(sf::IntRect(650, 0, 650, 650));
            Sleep(300);
            setUpDown(-1);
        }
    }
}

void slotMachine::setChargeUp()
{
    if (sf::IntRect(727, 790, 100, 100).contains(sf::Mouse::getPosition(window))) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sound.play();
            buttonBetUp.setTextureRect(sf::IntRect(650, 0, 650, 650));
            Sleep(300);
            xBet(1);
        }
    }
}

void slotMachine::setChargeDown()
{
    if (sf::IntRect(847, 790, 100, 100).contains(sf::Mouse::getPosition(window))) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sound.play();
            buttonBetDown.setTextureRect(sf::IntRect(650, 0, 650, 650));
            Sleep(300);
            xBet(-1);
        }
    }
}

void slotMachine::work()
{
    while(window.isOpen())
    {
        sf::Event event{};
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        updatingInf();
        window.clear(sf::Color::Cyan);
        renderingWindow(); /// отрисовка окна
        returnButton();///возвращение кнопок в исходное положение

        /// включение вращения
        if(state_machine == 0 && cash > 100) {
          turnOnRotation();
        }
        /// выключение вращения
        if(state_machine == 1 ) {
           turnOffRotation();
        }
        /// калькуляция выигрыша
        if(state_machine == 0 && countSpin != 0 && calculateStart)
        {
            calculateStart = false;
            cash += bet * my_table.calculatCoef();
        }
        ///управление ставкой
        if(state_machine == 0 ){
            sound.stop();
            sound.setBuffer(sB[0]);
            sound.setVolume(40);
            setBetUp();/// увеличения ставки
            setBetDown();///уменьшениe ставки
            setChargeUp();///увеличение ставки на значение
            setChargeDown(); ///уменьшение ставки на значение
        }

        /// рабочий цикл вращение -> остановка
        if(state_machine != 0) {
            state_machine = my_table.moveSpin(buttonClick);
            buttonClick = false;
        }
        Sleep(10);
        window.display();
    }
}

