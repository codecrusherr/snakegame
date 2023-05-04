// File : Snake.cpp
// Class: COP 2001 Summer B 2022
// Dev  : Jose Suarez
// Desc : Snake implementation
// --------------------------------------------------------

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>
#include "Snake.h"
#include "Food.h"
#include "Wall.h"

Snake::Snake(int windowWidth, int windowHeight) : WINDOW_WIDTH(windowWidth), WINDOW_HEIGHT(windowHeight) {
    // Spawn the snake in the middle of the window
    int rows = 600 / SNAKE_SIZE;
    int columns = 800 / SNAKE_SIZE;
    int x = columns / 2;
    int y = rows / 2;
    length = 1;
    dir = North;
    body[0].shape = fgcu::AnimatedRectangle(SNAKE_SIZE, SNAKE_SIZE);
    body[0].shape.setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);
    body[0].shape.setPosition(x * SNAKE_SIZE, y * SNAKE_SIZE);
    body[0].shape.setFillColor(sf::Color::Blue);
}

void Snake::draw(sf::RenderWindow& window) {
    for (int i = 0; i < length; i++) {
        window.draw(body[i].shape);
    }
}

void Snake::update(sf::RenderWindow& window, Wall& topWall, Wall& leftWall, Wall& rightWall, Wall& bottomWall, Food &food) {
    // Move the body
    for (int i = length - 1; i > 0; i--) {
        body[i].shape.setPosition(body[i - 1].shape.getPosition());
        body[i].shape.setRotation(body[i-1].shape.getRotation());
    }

    // Move the head in the current direction
    switch (dir) {
        case North:
            body[0].shape.move(0, -SNAKE_SIZE);
            body[0].shape.setRotation(North);
            break;
        case South:
            body[0].shape.move(0, SNAKE_SIZE);
            body[0].shape.setRotation(South);
            break;
        case West:
            body[0].shape.move(-SNAKE_SIZE, 0);
            body[0].shape.setRotation(West);
            break;
        case East:
            body[0].shape.move(SNAKE_SIZE, 0);
            body[0].shape.setRotation(East);
            break;
    }


    // Check for collision with walls
    if (topWall.isCollision(*this) || leftWall.isCollision(*this) ||
        rightWall.isCollision(*this) || bottomWall.isCollision(*this)) {
        std::cout << "Snake collided with wall" << std::endl;
        window.close();
    }

    // Check for collision with self
    for (int i = 1; i < length; i++) {
        if (body[0].shape.getGlobalBounds().intersects(body[i].shape.getGlobalBounds())) {
            std::cout << "Snake collided with self" << std::endl;
            window.close();
        }
    }

    // Check for eating food
    if (food.isEaten(*this)) {
        std::cout << "Snake ate food" << std::endl;
        length++;
        body[length - 1].shape = fgcu::AnimatedRectangle(SNAKE_SIZE, SNAKE_SIZE);
        body[length - 1].shape.setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);
        body[length - 1].shape.setPosition(body[length - 2].shape.getPosition());
        body[length - 1].shape.setFillColor(sf::Color::Blue);
        switch (dir) {
            case North:
                body[length - 1].shape.move(0, SNAKE_SIZE);
                break;
            case South:
                body[length - 1].shape.move(0, -SNAKE_SIZE);
                break;
            case West:
                body[length - 1].shape.move(SNAKE_SIZE, 0);
                break;
            case East:
                body[length - 1].shape.move(-SNAKE_SIZE, 0);
                break;
        }

        food.respawn(); // Make sure to respawn the food after it's eaten
    }
}


void Snake::handleInput(sf::Keyboard::Key key) {
    if (key != sf::Keyboard::Left && key != sf::Keyboard::A &&
        key != sf::Keyboard::Right && key != sf::Keyboard::D &&
        key != sf::Keyboard::Up && key != sf::Keyboard::W &&
        key != sf::Keyboard::Down && key != sf::Keyboard::S) {
        return; // Ignores any other key input from user
    }
    switch (key) {
        case sf::Keyboard::Left:
        case sf::Keyboard::A:
            if (dir != East) {
                dir = West;
            }
            break;
        case sf::Keyboard::Right:
        case sf::Keyboard::D:
            if (dir != West) {
                dir = East;
            }
            break;
        case sf::Keyboard::Up:
        case sf::Keyboard::W:
            if (dir != South) {
                dir = North;
            }
            break;
        case sf::Keyboard::Down:
        case sf::Keyboard::S:
            if (dir != North) {
                dir = South;
            }
            break;
    }
}
