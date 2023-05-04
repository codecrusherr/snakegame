// File : Wall.h
// Class: COP 2001 Summer B 2022
// Dev  : Jose Suarez
// Desc : Wall declaration
// --------------------------------------------------------

#ifndef SNAKEGAME_WALL_H
#define SNAKEGAME_WALL_H

#include <Eagles/AnimatedRectangle.h>
#include <SFML/Graphics.hpp>
#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>
#include "Snake.h"

class Snake;

class Wall {
public:
    Wall(int x, int y, int w, int h);
    void draw(sf::RenderWindow& window);
    bool isCollision(Snake & snake);

private:
    fgcu::AnimatedRectangle wall;
};

#endif //SNAKEGAME_WALL_H
