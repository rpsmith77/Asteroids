//
//  Missile.cpp
//  Asteroid
//
//  Created by Ryan Smith
//

#include "Missile.hpp"
#include <iostream>

Missile::Missile(){ alive = false; }

Missile::Missile(float angle,sf::Vector2f startingPoint){
    missile.setSize(size);
    missile.setOutlineColor(sf::Color::Red);
    missile.setFillColor(sf::Color::White);
    missile.setOutlineThickness(3.f);
    missile.setPosition(startingPoint);
    missile.rotate(angle);
    
    alive = true;
    velocity.x += ACCELERATION * cos(angle * DEG2RAD);
    velocity.y += ACCELERATION * sin(angle * DEG2RAD);
    float speed = sqrt(velocity.x * velocity.x  + velocity.y * velocity.y);
    velocity = sf::Vector2f(velocity.x/speed, velocity.y/speed) * 2.f * MAX_SPEED;
    this->startingPoint = startingPoint;
}


void Missile::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(missile, states);
}
void Missile::update(){
    if (alive)
        missile.move(velocity);
    if (outOfFrame())
        blowUp();

}
void Missile::blowUp(){
    alive = false;
}
bool Missile::outOfFrame(){
    return missile.getPosition().x < 0 || missile.getPosition().x > GAME_WIDTH ||
           missile.getPosition().y < 0 || missile.getPosition().y > GAME_HEIGHT;
}
