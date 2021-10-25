//
//  Missile.hpp
//
//  Created by Ryan Smith
//
//  Header file for Missile object

#ifndef Missile_hpp
#define Missile_hpp

# include "Constants.h"

class Missile : public sf::Drawable, public sf::Transformable {
private:
    // missile properties
    sf::RectangleShape missile;
    sf::Vector2f velocity;
    sf::Vector2f previousPoint;
    float distanceTraveled;
    bool alive;
    int range;
    sf::Vector2f startingPoint;
    sf::Vector2f size = sf::Vector2f(10.f,5.f);
    
    void setVelocity(float angle);
    void setDistanceTraveled();
    bool outOfRange();
    
public:
    // constructors
    Missile();
    Missile(float angle, sf::Vector2f startingPoint);
    
    sf::FloatRect getGlobalBounds() {return missile.getGlobalBounds();};
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    void blowUp();

};

#endif /* Missile_hpp */
