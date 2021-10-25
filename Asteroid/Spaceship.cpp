//
//  Spaceship.cpp
//
//  Created by Ryan Smith
//
//  Implementation of Spaceship object that utilizes SFML Libraries
//  to create a "spaceship" that has physics
//

#include "Spaceship.hpp"

// constructor
Spaceship::Spaceship(){
    // ship is an isosceles triangle
    ship.setPointCount(3);
    ship.setPoint(0, sf::Vector2f(10.0f, 0.0f));
    ship.setPoint(1, sf::Vector2f(-10.0f, 7.5f));
    ship.setPoint(2, sf::Vector2f(-10.0f, -7.5f));
    ship.setFillColor(sf::Color::Black);
    ship.setOutlineColor(sf::Color::White);
    ship.setOutlineThickness(1);
    // center of a triangle = ((x1+ x2 +x3)/3 , (y1+ y2 + y3)/3)
    ship.setOrigin((ship.getPoint(0).x + ship.getPoint(1).x + ship.getPoint(2).x)/3,
                   (ship.getPoint(0).y + ship.getPoint(1).y + ship.getPoint(2).y)/3);
    
    // start in center of screen
    ship.setPosition(GAME_WIDTH / 2, GAME_HEIGHT / 2);
    
}

// draws current state of the ship
void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(ship, states);
}

// adds velocity in current direction
void Spaceship::thrust(float direction){
    float r = ship.getRotation();
    velocity.x += ACCELERATION * cos(r * DEG2RAD) * direction;
    velocity.y += ACCELERATION * sin(r * DEG2RAD) * direction;
    // speed = magnitude of vector
    float speed = sqrt(pow(velocity.x, 2)  + pow(velocity.y, 2));
    // normalize vector then scale it by the max speed
    if (speed > MAX_SPEED){
        velocity = MAX_SPEED * sf::Vector2f(velocity.x/speed, velocity.y/speed);
    }
}

// rotate ship
void Spaceship::updateRotation(int rotation){
    ship.rotate(rotation * rotationRate);
}

// move ship position
void Spaceship::update(){
    ship.move(velocity);
    wrapScreen();
}

// move ship to opposite side of screen if leaving game bounds
void Spaceship::wrapScreen(){
    if (ship.getPosition().x < 0){
        ship.setPosition(GAME_WIDTH, ship.getPosition().y);
    } else if (ship.getPosition().x > GAME_WIDTH){
        ship.setPosition(0, ship.getPosition().y);
    }
    if (ship.getPosition().y < 0 ){
        ship.setPosition(ship.getPosition().x, GAME_HEIGHT);
    } else if(ship.getPosition().y > GAME_HEIGHT){
        ship.setPosition(ship.getPosition().x, 0);
    }
}

// reset ships velocity, rotation, and position
void Spaceship::reset(){
    velocity = sf::Vector2f(0,0);
    ship.setRotation(0);
    ship.setPosition(GAME_WIDTH/2, GAME_HEIGHT/2);
}
