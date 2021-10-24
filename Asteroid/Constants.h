//
//  Constants.h
//  Asteroid
//
//  Created by Ryan Smith
//

#ifndef Constants_h
#define Constants_h

#include <math.h>
#include <string.h>

// game properties
const std::string GAME_NAME = "Asteroids!";
const int GAME_WIDTH = 1000;
const int GAME_HEIGHT = 1000;
const int GAME_DIAGONAL = sqrt(GAME_WIDTH * GAME_WIDTH + GAME_HEIGHT * GAME_HEIGHT);
// math definitions
const float PI = atan(1) * 4;
const float DEG2RAD = PI / 180.f;

// entity propeties
const float MAX_SPEED = .15;
const float ACCELERATION = MAX_SPEED / 6;

// roation input
const int LEFT = -1;
const int RIGHT = 1;

#endif /* Constants_h */
