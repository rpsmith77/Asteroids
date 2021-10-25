//
//  Asteroid.cpp
//  Asteroid
//
//  Created by Ryan Smith
//

#include "Asteroid.hpp"

// constructor
Asteroid::Asteroid(){
    // create random
    srand((unsigned) time(0));
    
    // all asteroids share these
    asteroid.setFillColor(sf::Color::Black);
    asteroid.setOutlineColor(sf::Color::White);
    asteroid.setOutlineThickness(1);
    
    // set remaining asteroid info
    reset();
    
}

// draw current state of asteroid object
void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(asteroid, states);
}

// move asteroid to correct position
void Asteroid::update(){
    asteroid.move(velocity);
    wrapScreen();
}

// move asteroid to other side of the screen, dependent on previous position and game boundaries
void Asteroid::wrapScreen(){
    if (asteroid.getPosition().x < 0){
        asteroid.setPosition(GAME_WIDTH, asteroid.getPosition().y);
    } else if (asteroid.getPosition().x > GAME_WIDTH){
        asteroid.setPosition(0, asteroid.getPosition().y);
    }
    if (asteroid.getPosition().y < 0 ){
        asteroid.setPosition(asteroid.getPosition().x, GAME_HEIGHT);
    } else if(asteroid.getPosition().y > GAME_HEIGHT){
        asteroid.setPosition(asteroid.getPosition().x, 0);
    }
}

// runs eachtime the asteroid dies/is created
void Asteroid::reset(){
    
    // create random sized asteroid
    asteroid.setPointCount(rand() % 5 + 7);
    asteroid.setRadius(rand() % 30 + 10);
    asteroid.setOrigin(asteroid.getRadius(), asteroid.getRadius());
    
    // randomize asteroid position
    asteroid.setPosition(rand() % GAME_WIDTH, rand() % GAME_HEIGHT);
    
    // randomize velocity
    randomVelocity();
    // speed = magnitude of vector
    float speed = getSpeed();
    // normalize vector then times it by half the max speed
    if (speed > .5 * MAX_SPEED){
        velocity = .5f * MAX_SPEED * sf::Vector2f(velocity.x/speed, velocity.y/speed);
    }

}

void Asteroid::randomVelocity(){
    velocity.x = rand() % 2 == 0 ? float(rand() % 10) / 100 : -1 * float(rand() % 10) / 100;
    velocity.y = rand() % 2 == 0 ? float(rand() % 10) / 100 : -1 * float(rand() % 10) / 100;
    
    if(getSpeed() == 0)
        randomVelocity();
    
}
