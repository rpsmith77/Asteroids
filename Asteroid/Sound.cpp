//
//  Sound.cpp
//  Asteroid
//
//  Created by Ryan Smith on 10/25/21.
//  Copyright © 2021 Ryan Smith. All rights reserved.
//

#include "Sound.hpp"

Sound::Sound(std::string file) {
    setBuffer(file);
    setSound();
}
