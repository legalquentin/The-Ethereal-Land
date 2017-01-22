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

Scene::Scene(sf::Sprite &backgroundSprite ,std::string &background, int frames, sf::Vector2i backgroundSize, int playerSize, sf::Vector2i PlayerPosition, int playerScale, int LeftBoundaries, int RightBoundaries) {
    m_Scene.Background = backgroundSprite;
    m_Scene.BackgroundTexture.loadFromFile(resourcePath() + background +".png");
}
