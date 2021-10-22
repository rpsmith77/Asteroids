//
//  Spaceship.hpp
//
//
//  Created by Ryan Smith
//

#ifndef Spaceship_hpp
#define Spaceship_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Constants.h"

class Spaceship : public sf::Drawable, public sf::Transformable {
private:
    sf::ConvexShape ship;
    sf::Vector2f velocity;
    float rotationRate = 360/20;
    
public:
    Spaceship();
    
    sf::Vector2f getVelocity() {return velocity;};
    sf::FloatRect getGlobalBounds() {return ship.getGlobalBounds();};
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void thrust();
    void updateRotation(int);
    void update();
    void reset();
    
};
#endif /* Spaceship_hpp */
