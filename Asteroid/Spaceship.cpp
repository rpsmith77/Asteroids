//
//  Spaceship.cpp
//  Asteroid
//
//  Created by Ryan Smith
//

#include "Spaceship.hpp"

Spaceship::Spaceship(){
    ship.setPointCount(3);
    ship.setPoint(0, sf::Vector2f(10.0f, 0.0f));
    ship.setPoint(1, sf::Vector2f(-10.0f, 7.5f));
    ship.setPoint(2, sf::Vector2f(-10.0f, -7.5f));
    ship.setFillColor(sf::Color::Black);
    ship.setOutlineColor(sf::Color::White);
    ship.setOutlineThickness(1);
    ship.setPosition(GAME_WIDTH / 2, GAME_HEIGHT / 2);
}




void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(ship, states);
}

void Spaceship::thrust(){
    float r = ship.getRotation();
    velocity.x += ACCELERATION * cos(r * DEG2RAD);
    velocity.y += ACCELERATION * sin(r * DEG2RAD);
    float speed = sqrt(velocity.x * velocity.x  + velocity.y * velocity.y);
    if (speed > MAX_SPEED){
        velocity.x = velocity.x/speed * MAX_SPEED;
        velocity.y = velocity.y/speed * MAX_SPEED;
    }
}

void Spaceship::updateRotation(int rotation){
    ship.rotate(rotation * rotationRate);
}

void Spaceship::update(){
    ship.move(velocity);
    
    // wrap screen
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

void Spaceship::reset(){
    velocity = sf::Vector2f(0,0);
    ship.setRotation(0);
    ship.setPosition(GAME_WIDTH/2, GAME_HEIGHT/2);
}
