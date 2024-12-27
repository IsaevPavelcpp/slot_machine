
#ifndef SLOT_MACHINE_TABLE_H
#define SLOT_MACHINE_TABLE_H



#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Table {
    sf::Texture texture;
    sf::Image fruits;

    int baseFruints[14] = {1260, 1360, 60, 160, 260, 360, 460,
                           560, 660, 760, 860, 960, 1060, 1160};

    int combination[3] = {-1, -1, -1};
    clock_t timeBoost = 0;
    int deltaTime = 0;
    int start = 0;
    int position[3]{}; // позиция отдельного(каждого) слота
    sf::Sprite sprite[3]; // слоты

public:
    Table();
    bool fieldAlignment(int place); /// выравнивание полей
    int speedSpin(double timer, int field); /// устанавливает скорость вращения полей
    double calculatCoef(); /// возвращает коэффициент выигрыша
    void zeroField();/// возвращает поле в 0 положение
    int moveSpin(bool buttonClick);
    void switchStart(int condition);/// переключатель состояний

    sf::Sprite sp0();
    sf::Sprite sp1();
    sf::Sprite sp2();
};


#endif //SLOT_MACHINE_TABLE_H
