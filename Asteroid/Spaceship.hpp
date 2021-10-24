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

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constants.h"

class Spaceship : public sf::Drawable, public sf::Transformable {
private:
    // 20 different rotation options for the ship
    const float rotationRate = 360/20;
    
    // ship properties
    sf::ConvexShape ship;
    sf::Vector2f velocity;
    
    // ship sound
    sf::SoundBuffer collisionBuffer;
    sf::Sound collision;
    
public:
    // constructor
    Spaceship();
    
    // accessors
    sf::Vector2f getVelocity() {return velocity;};
    sf::FloatRect getGlobalBounds() {return ship.getGlobalBounds();};
    float getAngle(){ return ship.getRotation(); };
    sf::Vector2f getPosition(){ return ship.getPosition(); };
    
    // member methods
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void thrust();
    void updateRotation(int);
    void update();
    void wrapScreen();
    void reset();
    
    
};
#endif /* Spaceship_hpp */
