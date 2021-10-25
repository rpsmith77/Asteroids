//
//  Spaceship.hpp
//
//  Created by Ryan Smith
//
//  Header File for Spaceship object that utilizes SFML Libraries
//  to create a "spaceship" that has physics
//

#ifndef Spaceship_hpp
#define Spaceship_hpp

#include "Constants.h"

class Spaceship : public sf::Drawable, public sf::Transformable {
private:
    // 20 different rotation options for the ship
    const float rotationRate = 360/20;
    
    // ship properties
    sf::ConvexShape ship;
    sf::Vector2f velocity;
    void wrapScreen();
    
public:
    // constructor
    Spaceship();
    
    sf::Vector2f getVelocity() {return velocity;};
    sf::FloatRect getGlobalBounds() {return ship.getGlobalBounds();};
    float getAngle(){ return ship.getRotation(); };
    sf::Vector2f getPosition(){ return ship.getPosition(); };
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void thrust(float direction = 1);
    void updateRotation(int);
    void update();
    void reset();
    
    
};
#endif /* Spaceship_hpp */
