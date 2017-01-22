//
//  Game.cpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 20/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#include "Game.hpp"

ModuleFront::ModuleFront() {
    
}

int ModuleFront::play(sf::RenderWindow &window) {
    
    // Declare stuff
    
    sf::Font font;
    sf::Texture guiTexture,leatherTexture,guiTextTexture,mapTexture,texture1,texture2,PlayerTexture;
    sf::Sprite sprite,PlayerSprite;
    sf::Vector2i spriteSize(624,224), guiSize(624*2.4f,0), framesize(-65,65);
    sf::Clock clock;
    bool lock,go;
    
    // Create the objects
    
    Tools toolbox;
    Animator animator(sprite);
    Animator PlayerAnimator(PlayerSprite);
    Player Hero;
    
    // Load the textures
    
    font.loadFromFile(resourcePath() + "Plain_Black.ttf");
    guiTexture.loadFromFile(resourcePath() + "interface.png");
    leatherTexture.loadFromFile(resourcePath() + "oldWood.jpg");
    guiTextTexture.loadFromFile(resourcePath() + "TextHUD.jpg");
    mapTexture.loadFromFile(resourcePath() + "Map.jpg");
    texture1.loadFromFile(resourcePath() + "WaterFall.png", sf::IntRect(0, 0, 4992, 224));
    texture2.loadFromFile(resourcePath() + "GreatWaterFalls.png", sf::IntRect(0, 0, 7488, 384));
    PlayerTexture.loadFromFile(resourcePath() + "PlayerDefault.png");
    lock = true;
    go = false;

    // Write stuff
    
    sf::Text opt1("- press space to awake", font, 25);
    sf::Text opt2("Knight Holyter", font, 35);
    opt1.setFillColor(sf::Color::Black);
    opt2.setFillColor(sf::Color::White);
    
    // init the player class
    Hero.Init("Arthur","Pandragon","Warrior",PlayerAnimator, PlayerTexture);
    
    // Set Background animations
//    auto& backgroundAnimation1 = animator.CreateAnimation("background1", texture1, sf::seconds(1.2), true);
//    backgroundAnimation1.AddFrames(sf::Vector2i(0,0), spriteSize, 8);
    auto& backgroundAnimation2 = animator.CreateAnimation("background2", texture2, sf::seconds(1.6), true);
    backgroundAnimation2.AddFrames(sf::Vector2i(0,0), sf::Vector2i(624,384), 12);
    
    // Generate The HUD
    std::vector<sf::Sprite> HUD = toolbox.DisplayHud(window, guiTexture, spriteSize, mapTexture, guiTextTexture, leatherTexture);

    sf::Time deltaTime = clock.restart();
    PlayerAnimator.update(deltaTime);
    
    // Rescale Stuff
    sprite.setScale(1500./spriteSize.x, 700./spriteSize.y);
    PlayerSprite.setPosition(40, spriteSize.y*3.1f-145);
    PlayerSprite.setScale(2,2);
    opt1.setPosition(25, sprite.getGlobalBounds().height+25);
    opt2.setPosition(1165-opt2.getLocalBounds().width/2, sprite.getGlobalBounds().height+15);

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        
        // If Player attack is over switch to idle
        if (lock == false && PlayerAnimator.IsAnimationPlaying() == false) {
            if (PlayerAnimator.GetCurrentAnimationName() == "AttackLeft")
                PlayerAnimator.SwitchAnimation("IdleLeft");
            if (PlayerAnimator.GetCurrentAnimationName() == "AttackRight")
                PlayerAnimator.SwitchAnimation("IdleRight");
        }
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            if (lock == false && event.type != sf::Event::KeyPressed) {
                if (PlayerAnimator.GetCurrentAnimationName() == "MoveLeft")
                    PlayerAnimator.SwitchAnimation("IdleLeft");
                if (PlayerAnimator.GetCurrentAnimationName() == "MoveRight")                    PlayerAnimator.SwitchAnimation("IdleRight");
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
                if (PlayerAnimator.GetCurrentAnimationName() == "MoveLeft" ||
                    PlayerAnimator.GetCurrentAnimationName() == "IdleLeft" ||
                    (PlayerAnimator.GetCurrentAnimationName() == "AttackLeft" && PlayerAnimator.IsAnimationPlaying() == false))
                    PlayerAnimator.SwitchAnimation("AttackLeft");
                if (PlayerAnimator.GetCurrentAnimationName() == "MoveRight" ||
                    PlayerAnimator.GetCurrentAnimationName() == "IdleRight"||
                    (PlayerAnimator.GetCurrentAnimationName() == "AttackRight" && PlayerAnimator.IsAnimationPlaying() == false))
                    PlayerAnimator.SwitchAnimation("AttackRight");
            }
            
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) && (lock == false)) {
                if (PlayerAnimator.IsAnimationPlaying() == false || PlayerAnimator.GetCurrentAnimationName() != "MoveRight") {
                    PlayerAnimator.SwitchAnimation("MoveRight");
                }
                PlayerSprite.setPosition(PlayerSprite.getPosition().x+10, PlayerSprite.getPosition().y);
            }
            
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) && (lock == false)) {
                 if (PlayerAnimator.IsAnimationPlaying() == false || PlayerAnimator.GetCurrentAnimationName() != "MoveLeft")
                     PlayerAnimator.SwitchAnimation("MoveLeft");
                PlayerSprite.setPosition(PlayerSprite.getPosition().x-10, PlayerSprite.getPosition().y);
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                go = true;
            }
            
            if (event.type == sf::Event::MouseMoved)
            {
                
            }
            
            if (event.type == sf::Event::MouseButtonPressed)
            {
        
            }
            
            if (PlayerSprite.getPosition().x >= sprite.getGlobalBounds().width - 70) {
                if (animator.GetCurrentAnimationName() != "background2") {
                    animator.SwitchAnimation("background2");
                    sprite.setScale(1500./624., 700./384.);
                    PlayerSprite.setScale(4,4);
                    PlayerSprite.setPosition(20, PlayerSprite.getPosition().y-50);
                } else if (animator.GetCurrentAnimationName() != "background1") {
                    animator.SwitchAnimation("background1");
                    sprite.setScale(1500./spriteSize.x, 700./spriteSize.y);
                    PlayerSprite.setScale(2,2);
                    PlayerSprite.setPosition(20, spriteSize.y*3.1f-145);
                }
            }
            if (PlayerSprite.getPosition().x <= 10) {
                if (animator.GetCurrentAnimationName() != "background2") {
                    animator.SwitchAnimation("background2");
                    sprite.setScale(1500./624., 700./384.);
                    PlayerSprite.setScale(4,4);
                    PlayerSprite.setPosition(spriteSize.x*1500./spriteSize.x-180, PlayerSprite.getPosition().y-50);
                } else if (animator.GetCurrentAnimationName() != "background1") {
                    animator.SwitchAnimation("background1");
                    sprite.setScale(1500./spriteSize.x, 700./spriteSize.y);
                    PlayerSprite.setScale(2,2);
                    PlayerSprite.setPosition(spriteSize.x*1500./spriteSize.x-80, spriteSize.y*3.1f-145);
                }
            }
        }
        deltaTime = clock.restart();
        animator.update(deltaTime);
        if (go)
            PlayerAnimator.update(deltaTime);
        if (go == true && PlayerAnimator.IsAnimationPlaying() == false)
            lock = false;
        window.clear(sf::Color::Black);
        
        // Draw the sprite
        window.draw(sprite);
        window.draw(PlayerSprite);
        for (int i = 0; i != HUD.size(); i++) {
            window.draw(HUD[i]);
        }
        window.draw(opt1);
        window.draw(opt2);
        window.display();
    }
}
