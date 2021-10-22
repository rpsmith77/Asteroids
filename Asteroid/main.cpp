// Utilizing https://github.com/satanas/sfml-asteroids to help make this and understand
// how to use sfml

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Constants.h"
#include "Spaceship.hpp"
#include "Asteroid.hpp"


int main() {
   
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), GAME_NAME);
    
    // load sounds
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("blip.wav"))
        return -1;
    sf::Sound collision;
    collision.setBuffer(buffer);
    collision.setVolume(30);
    collision.setPitch(.5);
    
    // spaceship
    Spaceship ship;
    
    // asteroids
    srand((unsigned int) time(0));
    int numAsteroids = rand() % 3 + 5;
    Asteroid asteroids[numAsteroids];
    for (int i = 0; i<numAsteroids; i++) { // all asteroids will be identical w/o this
        asteroids[i].reset();
    }
    

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
                }
            }
            
        }
        
        ship.update();
        for(int i=0; i<numAsteroids; i++){
            asteroids[i].update();
        }
        
        
        // if ship hasn't moved yet
        // buggy resets even when ship isn't moving
        if (!(ship.getPosition() == sf::Vector2f(GAME_WIDTH/2,GAME_HEIGHT/2) && ship.getVelocity() == sf::Vector2f(0,0))){
            for (int i=0; i<numAsteroids; i++) {
                if (ship.getGlobalBounds().intersects(asteroids[i].getGlobalBounds())){
                    asteroids[i].reset();
                    //ship.reset();
                    collision.play();
                }
            }
        }
        

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        for (int i=0; i<numAsteroids; i++) {
            window.draw(asteroids[i]);
        }
        window.draw(ship);


        // end the current frame
        window.display();
    }

    return 0;
}
