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

class ModuleFront {

    public:
        ModuleFront();
        int play(sf::RenderWindow &window);
    private:
        void mouseEvent(sf::Text &opt, sf::RenderWindow &window, float posX, float posY, int police, sf::Event &event);
};

#endif /* Game_hpp */
