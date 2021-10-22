//
//  Asteroid.hpp
//  Asteroid
//
//  Created by Ryan Smith on 10/21/21.
//  Copyright © 2021 Ryan Smith. All rights reserved.
//

#ifndef Asteroid_hpp
#define Asteroid_hpp

#include <SFML/Graphics.hpp>
#include "Constants.h"

class Asteroid : public sf::Drawable, public sf::Transformable {
private:
    sf::CircleShape asteroid;
    sf::Vector2f velocity;

public:
    Asteroid();
    
    sf::Vector2f getVelocity() {return velocity;};
    sf::FloatRect getGlobalBounds() {return asteroid.getGlobalBounds();};
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    void reset();
    
    
};
#endif /* Asteroid_hpp */
