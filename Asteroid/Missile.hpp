//
//  Missile.hpp
//
//  Created by Ryan Smith
//
//  Header file for Missile object

#ifndef Missile_hpp
#define Missile_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constants.h"

class Missile : public sf::Drawable, public sf::Transformable {
private:
    // missile properties
    sf::RectangleShape missile;
    sf::Vector2f velocity;
    sf::Vector2f previousPoint;
    float distanceTraveled;
    bool alive;
    sf::Vector2f startingPoint;
    // dimensions of missle
    const sf::Vector2f size = sf::Vector2f(10.f,5.f);
    
    // missile sound
    sf::SoundBuffer missileFiredBuffer;
    sf::Sound missileFired;
    
public:
    // constructors
    Missile();
    Missile(float angle, sf::Vector2f startingPoint);
    
    // accessors
    sf::FloatRect getGlobalBounds() {return missile.getGlobalBounds();};
    void setVelocity(float angle);
    void setDistanceTraveled();
    
    // methods
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    void blowUp();
    bool outOfRange();
};

#endif /* Missile_hpp */
