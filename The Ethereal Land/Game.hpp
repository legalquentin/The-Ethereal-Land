//
//  Game.hpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 20/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Animator.hpp"
#include "Tools.hpp"
#include "Scene.hpp"
#include "Player.hpp"

struct S_Textures {
    sf::Font font;
    sf::Texture GUI;
    sf::Texture Map;
    sf::Texture woodTexture;
    sf::Texture guiTextTexture;
};

struct S_Game {
    
};
class Game {

private:
    S_Game m_Game;
    S_Textures m_Textures;
    void mouseEvent(sf::Text &opt, sf::RenderWindow &window, float posX, float posY, int police, sf::Event &event);
    
public:
    Game();
    int play(sf::RenderWindow &window, Player &Hero);
};

#endif /* Game_hpp */
