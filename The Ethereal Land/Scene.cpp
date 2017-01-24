//
//  Scene.cpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 22/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

// - Purpose of the class -
// Each time the player leave the scene, change the background, the animation, boundaries,
// Player position and scale..
// - Include player.cpp and work on it inside the scene -

#include "Scene.hpp"

Scene::Scene() {
    
}

void Scene::AddScene(Animator &animator,sf::Sprite &backgroundSprite ,std::string background, int num,int frames, sf::Vector2i backgroundSize, int playerSize, sf::Vector2i PlayerPosition, int LeftBoundaries, int RightBoundaries, sf::Sprite &player, int rows) {
    S_Scene scene;
    m_index = num-1;
    scene.Name = background;
    scene.PlayerPosition = PlayerPosition;
    scene.PlayerScale = playerSize;
    scene.Background = backgroundSprite;
    scene.BackgroundTexture.loadFromFile(resourcePath() + background +".png");
    scene.BackgroundSize = backgroundSize;
    m_Scene.push_back(scene);
    auto& backgroundAnimation = animator.CreateAnimation("background-"+std::to_string(num-1), m_Scene[num-1].BackgroundTexture, sf::seconds(1.2), true);
    for (int i = 0; i != rows; i++) {
        backgroundAnimation.AddFrames(sf::Vector2i(0,0), backgroundSize, frames);
    }
}

void Scene::Play(Player &Hero, sf::Sprite &sprite, sf::Sprite &PlayerSprite) {
    m_index = 2;
    sprite.setScale(1500./m_Scene[m_index].BackgroundSize.x, 700./m_Scene[m_index].BackgroundSize.y);
    PlayerSprite.setPosition(60, 700./m_Scene[m_index].BackgroundSize.y*m_Scene[m_index].BackgroundSize.y-145);
}

void Scene::Update(sf::Sprite &PlayerSprite, Animator &animator, sf::Sprite &Sprite, Animator &PlayerAnimator) {
    
    if (PlayerSprite.getPosition().x >= (m_Scene[m_index].BackgroundSize.x*1500./m_Scene[m_index].BackgroundSize.x)-140) {
        if (m_index == m_Scene.size()-1) {
            PlayerAnimator.SwitchAnimation("IdleRight");
            PlayerSprite.setPosition((m_Scene[m_index].BackgroundSize.x*1500./m_Scene[m_index].BackgroundSize.x)-141, PlayerSprite.getPosition().y);
        } else {
            SwitchScene(PlayerSprite, animator, m_index+1, Sprite);
        }
    }
    if (PlayerSprite.getPosition().x <= 10) {
        if (m_index == 0) {
            PlayerAnimator.SwitchAnimation("IdleLeft");
            PlayerSprite.setPosition(11, PlayerSprite.getPosition().y);
        } else {
            SwitchScene(PlayerSprite, animator, m_index-1, Sprite);
        }
    }
}

void Scene::SwitchScene(sf::Sprite &PlayerSprite, Animator &animator, int sceneNumber, sf::Sprite &Sprite) {
    
    if (m_index < sceneNumber)
        PlayerSprite.setPosition(m_Scene[sceneNumber].PlayerPosition.x, m_Scene[sceneNumber].PlayerPosition.y);
    else
        PlayerSprite.setPosition(m_Scene[sceneNumber].BackgroundSize.x*1500./m_Scene[sceneNumber].BackgroundSize.x-160, m_Scene[sceneNumber].PlayerPosition.y);

    m_index = sceneNumber;
    printf("Current scene number : %i\n",sceneNumber);
    animator.SwitchAnimation("background-"+std::to_string(sceneNumber));
    Sprite.setScale(1500./m_Scene[sceneNumber].BackgroundSize.x, 700./m_Scene[sceneNumber].BackgroundSize.y);
    PlayerSprite.setScale(m_Scene[m_index].PlayerScale,m_Scene[m_index].PlayerScale);
}

void Scene::AddEffect(sf::Sprite &PlayerSprite, sf::Sprite &EffectSprite, Animator &animator, std::string effectName, int size) {
    animator.SwitchAnimation(effectName.c_str());
    sf::Vector2i value;
    if (size == 1) {
        value.x = m_Scene[m_index].PlayerScale;
        value.y = m_Scene[m_index].PlayerScale;
    } else {
        value.x = m_Scene[m_index].PlayerScale+2.5;
        value.y = m_Scene[m_index].PlayerScale+0.5;
    }
    
    EffectSprite.setScale(value.x,value.y);
    EffectSprite.setPosition((PlayerSprite.getPosition().x-(EffectSprite.getLocalBounds().width*value.x-PlayerSprite.getLocalBounds().width)/3), PlayerSprite.getPosition().y-(EffectSprite.getLocalBounds().height*value.y-PlayerSprite.getLocalBounds().height)/2);
}
