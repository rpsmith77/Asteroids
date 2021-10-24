//
//  Asteroid.hpp
//
//  Created by Ryan Smith
//

#ifndef Asteroid_hpp
#define Asteroid_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constants.h"

class Asteroid : public sf::Drawable, public sf::Transformable {
private:
    // asteroid properties
    sf::CircleShape asteroid;
    sf::Vector2f velocity;
    
    // sound
    sf::SoundBuffer explosionBuffer;
    sf::Sound explosion;
    
public:
    // constructor
    Asteroid();
    
    // accessors
    sf::Vector2f getVelocity() {return velocity;};
    sf::FloatRect getGlobalBounds() {return asteroid.getGlobalBounds();};
    
    // methods
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    void wrapScreen();
    void reset();
    
    
};
#endif /* Asteroid_hpp */
