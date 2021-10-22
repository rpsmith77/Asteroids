//
//  Constants.h
//  Asteroid
//
//  Created by Ryan Smith on 10/21/21.
//  Copyright © 2021 Ryan Smith. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

#include <math.h>
#include <string.h>

const std::string GAME_NAME = "Asteroids!";
const int GAME_WIDTH = 1000;
const int GAME_HEIGHT = 1000;
const float PI = atan(1) * 4;
const float DEG2RAD = PI / 180.f;
const float MAX_SPEED = .15;
const float ACCELERATION = MAX_SPEED / 6;
const int LEFT = -1;
const int RIGHT = 1;

#endif /* Constants_h */
