//
//  Missile.hpp
//  Asteroid
//
//  Created by Ryan Smith
//

#ifndef Missile_hpp
#define Missile_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Constants.h"

class Missile : public sf::Drawable, public sf::Transformable {
private:
    sf::RectangleShape missile;
    sf::Vector2f size = sf::Vector2f(10.f,5.f);
    sf::Vector2f velocity;
    bool alive;
    sf::Vector2f startingPoint;
public:
    Missile();
    Missile(float angle, sf::Vector2f startingPoint);
    
    sf::FloatRect getGlobalBounds() {return missile.getGlobalBounds();};
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    void blowUp();
    bool outOfFrame();
};

#endif /* Missile_hpp */
