/*
 The purpose of this program was to teach me the basics of how to use SFML.
 It is based on Asteroid, the arcade game from 1979. In this I draw custom shapes,
 random shapes, give those shapses physics and handle collisions.
 
 Created by Ryan Smith
 Utilizing https://github.com/satanas/sfml-asteroids to help make this and understand
 how to use sfml
 
 Sounds from mixkit.co/free-sound-effects
 
 TODO:
    * get sounds working within Missle.cpp
    * score
    * death count
    * figure out cmake
 
 */

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Constants.h"
#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"


int main() {
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), GAME_NAME);
    
    
    // spaceship
    Spaceship ship;
    
    // load sound
    sf::SoundBuffer missileFiredBuffer;
    if(!missileFiredBuffer.loadFromFile("missile_fired.wav"))
        return -1;
    sf::Sound missileFired;
    missileFired.setBuffer(missileFiredBuffer);
    
    // load background music
    sf::Music backgroundMusic;
    if (!backgroundMusic.openFromFile("Underwater_Exploration_Godmode.ogg"))
        return -1;
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(80);
    backgroundMusic.play();
    
    
    
    // asteroids
    srand((unsigned int) time(0));
    int numAsteroids = rand() % 3 + 5;
    Asteroid asteroids[numAsteroids];
    for (int i = 0; i<numAsteroids; i++) { // all asteroids will be identical w/o this
        asteroids[i].reset();
    }
    
    int totalMissile = 5;
    Missile missile[totalMissile];
    int missileIndex = 0;
    
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            // keyboard input
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Up ){
                    ship.thrust();
                } else if(event.key.code == sf::Keyboard::Right){
                    ship.updateRotation(RIGHT);
                } else if(event.key.code == sf::Keyboard::Left){
                    ship.updateRotation(LEFT);
                } else if(event.key.code == sf::Keyboard::Space){
                    missile[missileIndex++] = Missile(ship.getAngle(), ship.getPosition());
                    missileFired.play();
                    if (missileIndex >= totalMissile)
                        missileIndex = 0;
                }
            }
            
        }
        
        // update positions
        ship.update();
        for(int i=0; i<numAsteroids; i++){
            asteroids[i].update();
        }
        for (int i=0; i<totalMissile; i++) {
            missile[i].update();
        }
        
        // if ship hasn't moved yet
        if (!(ship.getPosition() == sf::Vector2f(GAME_WIDTH/2,GAME_HEIGHT/2) && ship.getVelocity() == sf::Vector2f(0,0))){
            for (int i=0; i<numAsteroids; i++) {
                if (ship.getGlobalBounds().intersects(asteroids[i].getGlobalBounds())){
                    asteroids[i].reset();
                    ship.reset();
                }
                for (int j=0; j<totalMissile; j++) {
                    if (missile[j].getGlobalBounds().intersects(asteroids[i].getGlobalBounds())){
                        asteroids[i].reset();
                    }
                }
            }
        }
        
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        // draw everything
        for (int i=0; i<numAsteroids; i++) {
            window.draw(asteroids[i]);
        }
        window.draw(ship);
        for (int i=0; i<totalMissile; i++) {
            window.draw(missile[i]);
        }
        
        // end the current frame
        window.display();
        
    } // end game loop
    
    return 0;
} // end main
