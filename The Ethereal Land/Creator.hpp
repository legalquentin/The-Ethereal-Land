//
//  Creator.hpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 24/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#ifndef Creator_hpp
#define Creator_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "ResourcePath.hpp"
#include "Player.hpp"

class Creator {

private:

public:
    Creator();
    void play(sf::RenderWindow &window, Player &Hero);
    void mouseEvent(sf::Text &opt, sf::RenderWindow &window, float posX, float posY, int police, sf::Event &event);
};

#endif /* Creator_hpp */
