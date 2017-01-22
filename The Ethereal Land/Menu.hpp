//
//  Menu.hpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 20/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Animator.hpp"

class Menu {
    
    private:
    
    public:
    Menu();
    int play(sf::RenderWindow &window);
    void mouseEvent(sf::Text &opt, sf::RenderWindow &window, float posX, float posY, int police, sf::Event &event);
    //    sf::RenderWindow play();
};
#endif /* Menu_hpp */
