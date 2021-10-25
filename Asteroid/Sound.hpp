//
//  Sound.hpp
//  Asteroid
//
//  Created by Ryan Smith on 10/25/21.
//  Copyright © 2021 Ryan Smith. All rights reserved.
//

#ifndef Sound_hpp
#define Sound_hpp

# include "Constants.h"

class Sound {
private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
    
public:
    Sound(std::string file);
    
    void setBuffer(std::string file){ buffer.loadFromFile(file); };
    void setSound() { sound.setBuffer(buffer); };
    void setVolume(float volume) { sound.setVolume(volume); };
    void setPitch(float pitch) { sound.setPitch(pitch); };
    void setLoop(bool loop) { sound.setLoop(loop); };
    void play() { sound.play(); };
    
};

#endif /* Sound_hpp */
