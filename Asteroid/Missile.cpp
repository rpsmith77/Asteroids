//
//  Missile.cpp
//  Asteroid
//
//  Created by Ryan Smith
//

#include "Missile.hpp"
#include <iostream>

Missile::Missile(){
    alive = false;
}

Missile::Missile(float angle,sf::Vector2f startingPoint){
    alive = true;
    
    missile.setSize(size);
    missile.setOutlineColor(sf::Color::Red);
    missile.setFillColor(sf::Color::White);
    missile.setOutlineThickness(3.f);
    missile.setPosition(startingPoint);
    missile.rotate(angle);
    setVelocity(angle);
    
    this->startingPoint = startingPoint;
    previousPoint = startingPoint;
    distanceTraveled = 0;
    
}

void Missile::setVelocity(float angle){
    velocity.x += ACCELERATION * cos(angle * DEG2RAD);
    velocity.y += ACCELERATION * sin(angle * DEG2RAD);
    float speed = sqrt(velocity.x * velocity.x  + velocity.y * velocity.y);
    velocity = sf::Vector2f(velocity.x/speed, velocity.y/speed) * 2.f * MAX_SPEED;
}

void Missile::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    if(alive){
        states.transform *= getTransform();
        target.draw(missile, states);
    }
}
void Missile::update(){
    if (alive){
        missile.move(velocity);
        setDistanceTraveled();
    }
    if (outOfRange())
        blowUp();
}
void Missile::setDistanceTraveled(){
    // distance formulat d=√((x_2-x_1)²+(y_2-y_1)²)
    distanceTraveled += sqrt(pow(missile.getPosition().x - previousPoint.x, 2) + pow(missile.getPosition().y - previousPoint.y, 2));
    previousPoint = missile.getPosition();
}
void Missile::blowUp(){
    alive = false;
    missile.setPosition(GAME_WIDTH * 10, GAME_HEIGHT * 10);
}
bool Missile::outOfRange(){
    return distanceTraveled >= (GAME_WIDTH + GAME_HEIGHT) / 4;
}
