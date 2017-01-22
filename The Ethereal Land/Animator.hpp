//
//  Utilities.hpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 19/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//
#pragma once
#ifndef Utilities_hpp
#define Utilities_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <list>

class Animator {
    public :
    std::string GetCurrentAnimationName();
    struct Animation {
        std::string m_Name;
        sf::Texture m_Texture;
        bool m_playing;
        std::vector<sf::IntRect> m_Frames;
        sf::Time m_Duration;
        bool m_Looping;
        
        // Constructor
        Animation(std::string const &name, sf::Texture &texture,
                  sf::Time const &duration, bool looping) : m_Name(name), m_Texture(texture), m_Duration(duration), m_Looping(looping)
        { m_playing = true; }
        
        // Add Frames Horizontally
        void AddFrames(sf::Vector2i const& startFrom, sf::Vector2i const& frameSize, unsigned int frames) {
            sf::Vector2i current = startFrom;
            for (unsigned int i = 0; i < frames; i++) {
//                // Add current Frame from position and frame size
                m_Frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
                // Advance current Frame horizontally
                current.x += frameSize.x;
            }
        }
    };
    Animator(sf::Sprite& sprite);
    
    Animation& CreateAnimation(std::string const& name, sf::Texture& texture, sf::Time const& duration, bool loop = true);
    void update(sf::Time const& dt);
    
    // return if the switch was successful
    bool SwitchAnimation(std::string const& name);
    
    std::string getCurrentAnimationName() const;
    void bakeAnimation(Animator &animator, int count, int dimX, sf::Vector2i spriteSize, sf::Texture &texture);
    void SwitchAnimation(Animation* animation);
    bool IsAnimationPlaying();
    
    private :
    // Return with the passed name
    // return nullptr if no animation is found
    Animation* Findanimation(std::string const& Name);
    
    // references to the sprite
    sf::Sprite& m_Sprite;
    sf::Time m_CurrentTime;
    std::list<Animation> m_Animations;
    Animation* m_CurrentAnimation;
};
#endif /* Utilities_hpp */
