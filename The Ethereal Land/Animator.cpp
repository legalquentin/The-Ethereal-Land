//
//  Utilities.cpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 19/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#include "Animator.hpp"
#include "ResourcePath.hpp"

Animator::Animator(sf::Sprite &sprite):m_Sprite(sprite), m_CurrentTime(), m_CurrentAnimation(nullptr)
{
}

Animator::Animation& Animator::CreateAnimation(const std::string &name,sf::Texture &texture, const sf::Time &duration, bool loop) {
    
    m_Animations.push_back(Animator::Animation(name, texture, duration, loop));
    //If we don't have any other animation, use that as current animation
    if (m_CurrentAnimation == nullptr)
        SwitchAnimation(&m_Animations.back());
    return m_Animations.back();
}

void Animator::SwitchAnimation(Animator::Animation *animation) {
    if (animation != nullptr) {
        m_Sprite.setTexture(animation->m_Texture);
        animation->m_playing = true;
    }
    m_CurrentAnimation = animation;
    m_CurrentTime=sf::Time::Zero; // reset the time
}

bool Animator::SwitchAnimation(const std::string &name) {
    auto animation = Findanimation(name);
    if (animation != nullptr) {
        SwitchAnimation(animation);
        return true;
    }
    return false;
}

Animator::Animation* Animator::Findanimation(const std::string &Name) {
    for (auto it = m_Animations.begin(); it != m_Animations.end(); ++it) {
        if (it->m_Name == Name) {
            return &*it;
        }
    }
    return nullptr;
}

std::string Animator::GetCurrentAnimationName() {
    if (m_CurrentAnimation != nullptr) {
        return m_CurrentAnimation->m_Name;
    }
    return "";
}


bool Animator::IsAnimationPlaying() {
    return m_CurrentAnimation->m_playing;
}


void Animator::update(const sf::Time &dt) {
    if (m_CurrentAnimation == nullptr)
        return;
    m_CurrentTime+=dt;

    float scaledtime = (m_CurrentTime.asSeconds() / m_CurrentAnimation->m_Duration.asSeconds());
    int numframes = m_CurrentAnimation->m_Frames.size();
    int currentFrame = static_cast<int>(scaledtime * numframes);
    
    if (m_CurrentAnimation->m_Looping) {
        currentFrame %= numframes;
    }
    else if(currentFrame >= numframes) {// if the current frame is greater than the number of frames
        currentFrame = numframes-1; // show the last frame
        m_CurrentAnimation->m_playing = false;
    }
    
    //set the texture retangle, depending on the frame
    m_Sprite.setTextureRect(m_CurrentAnimation->m_Frames[currentFrame]);
}

void bakeAnimation(Animator &animator, int count, int dimX, sf::Vector2i spriteSize, sf::Texture &texture) {
    auto& backgroundAnimation = animator.CreateAnimation("background", texture, sf::seconds(0.9), true);
    for (int i = 0; i != count; i++) {
        backgroundAnimation.AddFrames(sf::Vector2i(dimX*i,0), spriteSize, 1);
    }
}

