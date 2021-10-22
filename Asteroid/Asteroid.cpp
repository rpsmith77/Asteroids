//
//  Asteroid.cpp
//  Asteroid
//
//  Created by Ryan Smith on 10/21/21.
//  Copyright © 2021 Ryan Smith. All rights reserved.
//

#include "Asteroid.hpp"

Asteroid::Asteroid(){
    srand((unsigned) time(0));
    reset();
}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(asteroid, states);
}
void Asteroid::update(){
    asteroid.move(velocity);
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
    float speed = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    if (speed > MAX_SPEED * (2/3)){
        velocity.x = (velocity.x/speed) * MAX_SPEED * .5;
        velocity.y = (velocity.y/speed) * MAX_SPEED * .5;
    }

}
