//
//  Asteroid.hpp
//
//  Created by Ryan Smith
//

#ifndef Asteroid_hpp
#define Asteroid_hpp

#include "Constants.h"

class Asteroid : public sf::Drawable, public sf::Transformable {
private:
    // asteroid properties
    sf::CircleShape asteroid;
    sf::Vector2f velocity;
    
    float getSpeed() { return sqrt(pow(velocity.x, 2)  + pow(velocity.y, 2)); };
    sf::Vector2f getVelocity() { return velocity; };
    void wrapScreen();
    void randomVelocity();

public:
    // constructor
    Asteroid();
    
    sf::FloatRect getGlobalBounds() { return asteroid.getGlobalBounds(); };
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    void reset();
    
};
#endif /* Asteroid_hpp */
