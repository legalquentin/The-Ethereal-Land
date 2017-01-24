//
//  Creator.cpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 24/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#include "Creator.hpp"

Creator::Creator() {}

void Creator::play(sf::RenderWindow &window, Player &Hero) {
    
    // Load font
    sf::Font font;
    font.loadFromFile(resourcePath() + "Plain_Black.ttf");
    sf::Text opt1("The Etheral Kingdom", font, 75);
    opt1.setFillColor(sf::Color::White);
    opt1.setPosition(50, 10);
    
    sf::Text opt2("New Game", font, 65);
    sf::Text opt3("Load Game", font, 65);
    opt2.setFillColor(sf::Color::White);
    opt3.setFillColor(sf::Color(180,180,180));
    opt2.setPosition(window.getSize().x/2.0f - opt2.getLocalBounds().width/2.0f, window.getSize().y/1.35f);
    opt3.setPosition(window.getSize().x/2.0f - opt3.getLocalBounds().width/2.0f, window.getSize().y/1.2f);
    
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "forest.png", sf::IntRect(0, 0, 6144, 368))) {
        return;
    }
    sf::Sprite sprite;
    sf::Vector2i spriteSize(768,368);
    Animator animator(sprite);
    
    //    animator.bakeAnimation(animator, 7, 768, spriteSize, texture);
    // create an animation and get the reference to it
    auto& backgroundAnimation = animator.CreateAnimation("background", texture, sf::seconds(0.9), true);
    //add frames to the animation
    backgroundAnimation.AddFrames(sf::Vector2i(0,0), spriteSize, 8);
    
    sf::Clock clock;
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::MouseMoved)
            {
                mouseEvent(opt2,window,2.0f, 1.35f, 65, event);
                //              mouseEvent(opt3,window,2.0f, 1.2f, 65);
                
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (opt2.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                    return 1;
                }
            }
        }
        sf::Time deltaTime = clock.restart();
        animator.update(deltaTime);
        window.clear(sf::Color::Black);
        // Draw the sprite
        sprite.setScale(2.5f, 2.948f);
        window.draw(sprite);
        window.draw(opt1);
        window.draw(opt2);
        window.draw(opt3);
        
        // Update the window
        window.display();
    }
}

void Creator::mouseEvent(sf::Text &opt, sf::RenderWindow &window, float posX, float posY, int police, sf::Event &event) {
    if (opt.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
        opt.setFillColor(sf::Color::Yellow);
        opt.setCharacterSize(police+2);
    } else {
        opt.setFillColor(sf::Color::White);
        opt.setCharacterSize(police);
    }
    opt.setPosition(window.getSize().x/posX - opt.getLocalBounds().width/2.0f, window.getSize().y/posY);
}
//sf::RenderWindow Menu::play() {
