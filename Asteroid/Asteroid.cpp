//
//  Asteroid.cpp
//  Asteroid
//
//  Created by Ryan Smith
//

#include "Asteroid.hpp"

Asteroid::Asteroid(){
    srand((unsigned) time(0));
    
    if(!explosionBuffer.loadFromFile("blip.wav"))
        return -1;
    explosion.setBuffer(explosionBuffer);
    explosion.setVolume(30);
    
    reset();
    
}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(asteroid, states);
}
void Asteroid::update(){
    asteroid.move(velocity);
    wrapScreen();
}

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

void Asteroid::reset(){
    asteroid.setPointCount(rand() % 5 + 7);
    asteroid.setRadius(rand() % 30 + 10);
    asteroid.setFillColor(sf::Color::Black);
    asteroid.setOutlineColor(sf::Color::White);
    asteroid.setOutlineThickness(1);
    asteroid.setOrigin(asteroid.getRadius(), asteroid.getRadius());
    asteroid.setPosition(rand() % GAME_WIDTH, rand() % GAME_HEIGHT);
    velocity.x = rand() % 2 == 0 ? float(rand() % 10) / 100 : -1 * float(rand() % 10) / 100;
    velocity.y = rand() % 2 == 0 ? float(rand() % 10) / 100 : -1 * float(rand() % 10) / 100;
    float speed = sqrt(velocity.x * velocity.x  + velocity.y * velocity.y);
    if (speed > .5 * MAX_SPEED){
        velocity = .5f * MAX_SPEED * sf::Vector2f(velocity.x/speed, velocity.y/speed);
    }
    explosion.play();
}
