// File : Food.h
// Class: COP 2001 Summer B 2022
// Dev  : Jose Suarez
// Desc : Food declaration
// --------------------------------------------------------

#ifndef SNAKEGAME_FOOD_H
#define SNAKEGAME_FOOD_H


#include <Eagles/AnimatedCircle.h>
#include <SFML/Graphics.hpp>
#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>

class Snake;

class Food {
public:
    Food();
    void draw(sf::RenderWindow& window);
    void respawn();
    bool isEaten(Snake& snake);
    void update(Snake &snake);

private:
    static const int FOOD_SIZE = 10;

    fgcu::AnimatedCircle food;

};

#endif //SNAKEGAME_FOOD_H
