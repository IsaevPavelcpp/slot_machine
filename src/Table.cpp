
#include "../headers/Table.h"

Table::Table() {
    srand(time(nullptr));
    fruits.loadFromFile(R"(..\resources\textures\fruitsTest.jpg)");
    texture.loadFromImage(fruits);
    texture.setSmooth(true);
    texture.setRepeated(true);
    // установка спрайтов текстур для каждого слота
    sprite[0].setTexture(texture);
    sprite[0].setScale(1.25,1.1);
    sprite[2] = sprite[1] = sprite[0];

    // постановка в окне
    sprite[0].setPosition(512,70);
    sprite[1].setPosition(746,70);
    sprite[2].setPosition(980,70);
    // установка начального положения слота
    position[0] = std::rand()%1400;
    position[1] = std::rand()%1400;
    position[2] = std::rand()%1400;

    sprite[0].setTextureRect(sf::IntRect (0, position[0],180,380));
    sprite[1].setTextureRect(sf::IntRect (0, position[1],180,380));
    sprite[2].setTextureRect(sf::IntRect (0, position[2],180,380));
}

bool Table::fieldAlignment(int place) {
    for(int i = 0; i < 14; ++i)
    {
        if( position[place] == baseFruints[i])
        {
            combination[place] = i;
            return true;
        }
    }
    return false;
}

int Table::speedSpin(double timer, int field) {
    if(start == 1 && timer <= 7000 ){
        if (timer >= 2000 && timer <= 7000) {
            return 50;
        } else if (timer >= 1000) {
            return 15;
        } else if (timer <= 1000)
        {
            return 10;
        }
    }
    if(start == 2 || timer >= 7000 )
    {
        if(timer >= 10000 && timer <= 11000)
        {
            return 10;
        }
        else if(timer <= 10000 && timer >= 8000)
        {
            return 15;
        }
        else if(timer <= 8000)
        {
            return 50;
        }
    }

    if(!fieldAlignment(field))
    {
        return 10;
    }
    else
    {
        if(field == 2)
        {
            timeBoost = 0;
            start = 0;
            return 0;
        }
    }
    return 0;
}

double Table::calculatCoef() {
    if(combination[0] == combination[1] && combination[1] == combination[2])
    {
        if(combination[0] == 3 || combination[0] == 6 || combination[0] == 7 || combination[0] == 9
           || combination[0] == 10 || combination[0] == 12 || combination[0] == 13 )
        {
            return 1.2;
        }
        else if(combination[0] == 0 || combination[0] == 8 || combination[0] == 5)
        {
            return 2;
        }
        else if(combination[0] == 2 || combination[0] == 11)
        {
            return 5;
        }
        else if(combination[0] == 4)
        {
            return 10;
        }
        else if(combination[0] == 1)
        {
            return 20;
        }
    }
    return 0;
}

void Table::zeroField() {
    if(position[0] > 1400)
    {
        position[0] = 0;
    }
    if(position[1] > 1400)
    {
        position[1] = 0;
    }
    if(position[2] > 1400)
    {
        position[2] = 0;
    }
}

int Table::moveSpin(bool buttonClick) {
    if(buttonClick)
    {
        deltaTime = clock();
    }

    if(start == 1)
        timeBoost = clock() - deltaTime;
    if(start == 2)
        timeBoost = clock() - deltaTime + 7000;

    position[0] += speedSpin(timeBoost,0);
    if (timeBoost > 200)
        position[1] += speedSpin(timeBoost*0.9, 1);
    if (timeBoost > 400)
        position[2] += speedSpin(timeBoost*0.8, 2);

    zeroField();

    sprite[0].setTextureRect(sf::IntRect(0, position[0], 180, 380));
    sprite[1].setTextureRect(sf::IntRect(0, position[1], 180, 380));
    sprite[2].setTextureRect(sf::IntRect(0, position[2], 180, 380));

    if(start == 1)
    {
        return 1;
    }
    else if (start == 2)
    {
        return 2;
    }

    return 0;

}

void Table::switchStart(int condition) {
    start = condition;
}

sf::Sprite Table::sp0() {
    return sprite[0];
}

sf::Sprite Table::sp1() {
    return sprite[1];
}

sf::Sprite Table::sp2() {
    return sprite[2];
}


