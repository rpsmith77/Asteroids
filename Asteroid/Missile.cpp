//
//  Missile.cpp
//  Asteroid
//
//  Created by Ryan Smith
//

#include "Missile.hpp"
#include <iostream>

// default constructor
Missile::Missile(){ alive = false; }

// constructor for live missile
Missile::Missile(float angle,sf::Vector2f startingPoint){
    
    alive = true;
    
    missile.setSize(size);
    missile.setFillColor(sf::Color::White);
    missile.setPosition(startingPoint);
    missile.rotate(angle);
    setVelocity(angle);
    
    this->startingPoint = startingPoint;
    previousPoint = startingPoint;
    distanceTraveled = 0;
    // range = sqrt(pow(GAME_WIDTH,2) + pow(GAME_HEIGHT,2));
    range = 500;
    
}

// set velocity based on ship's current rotation
void Missile::setVelocity(float angle){
    velocity.x += ACCELERATION * cos(angle * DEG2RAD);
    velocity.y += ACCELERATION * sin(angle * DEG2RAD);
    // speed = magnitude of vector
    float speed = sqrt(pow(velocity.x, 2)  + pow(velocity.y, 2));
    // normalize vector then scale it by double the max speed
    velocity = sf::Vector2f(velocity.x/speed, velocity.y/speed) * 2.f * MAX_SPEED;
}

// draws current state of the missile
void Missile::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    if(alive){
        states.transform *= getTransform();
        target.draw(missile, states);
    }
}

// move missile position and track distance travled
void Missile::update(){
    if (alive){
        missile.move(velocity);
        setDistanceTraveled();
    }
    if (outOfRange())
        blowUp();
}

// calculate how far it has moved since last position
void Missile::setDistanceTraveled(){
    // distance formulat d=√((x_2-x_1)²+(y_2-y_1)²)
    distanceTraveled += sqrt(pow(missile.getPosition().x - previousPoint.x, 2) + pow(missile.getPosition().y - previousPoint.y, 2));
    previousPoint = missile.getPosition();
}

// set missle as dead, move object off screen.
void Missile::blowUp(){
    alive = false;
    missile.setPosition(GAME_WIDTH * 10, GAME_HEIGHT * 10);
}

// check to see if total distance traveld exceeds the missile's range
bool Missile::outOfRange(){
    return distanceTraveled >= range;
}
