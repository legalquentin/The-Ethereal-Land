//
//  Scene.hpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 22/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>

#include "Animator.hpp"
#include "Player.hpp"
#include "ResourcePath.hpp"

struct S_Scene {
    sf::Sprite Background;
    sf::Texture BackgroundTexture;
    Animator Animation;
};

class Scene {
private:
    S_Scene m_Scene;
public:
    Scene(sf::Sprite &backgroundSprite ,std::string &background, int frames, sf::Vector2i backgroundSize, int playerSize, sf::Vector2i PlayerPosition, int playerScale, int LeftBoundaries, int RightBoundaries);
    
};
#endif /* Scene_hpp */
