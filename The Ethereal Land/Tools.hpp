//
//  Tools.hpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 21/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#ifndef Tools_hpp
#define Tools_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "ResourcePath.hpp"

class Tools {
    public :
        Tools();
    std::vector<sf::Sprite> DisplayHud(sf::RenderWindow &window, sf::Texture &guiTexture, sf::Vector2i spriteSize, sf::Texture &mapTexture, sf::Texture &guiTextTexture, sf::Texture &leatherTexture);
    private :
};
#endif /* Tools_hpp */

