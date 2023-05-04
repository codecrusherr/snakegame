// File : Wall.cpp
// Class: COP 2001 Summer B 2022
// Dev  : Jose Suarez
// Desc : Wall implementation
// --------------------------------------------------------

#include "Wall.h"

#include <SFML/Graphics.hpp>
#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>
#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>


Wall::Wall(int x, int y, int w, int h) {
    wall = fgcu::AnimatedRectangle(w, h);
    wall.setPosition(x, y);
    wall.setFillColor(sf::Color::White);
}

void Wall::draw(sf::RenderWindow& window) {
    window.draw(wall);
}

bool Wall::isCollision(Snake& snake) {
    if (snake.body[0].shape.getGlobalBounds().intersects(wall.getGlobalBounds())) {
        return true;
    }
    return false;
}
