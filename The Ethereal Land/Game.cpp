//
//  Game.cpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 20/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#include "Game.hpp"
#include "Tools.hpp"

ModuleFront::ModuleFront() {
    
}

int ModuleFront::play(sf::RenderWindow &window) {
    
    Tools toolbox;

    sf::Font font;
    font.loadFromFile(resourcePath() + "Plain_Black.ttf");
    sf::Text opt1("- press space to awake", font, 25);
    opt1.setFillColor(sf::Color::Black);
    
    sf::Text opt2("Knight Holyter", font, 35);
    opt2.setFillColor(sf::Color::White);
    
    sf::Texture texture1;
    texture1.loadFromFile(resourcePath() + "WaterFall.png", sf::IntRect(0, 0, 4992, 224));
    
    sf::Texture texture2;
    texture2.loadFromFile(resourcePath() + "GreatWaterFalls.png", sf::IntRect(0, 0, 7488, 384));
    
    sf::Sprite sprite;
    sf::Vector2i spriteSize(624,224);
    Animator animator(sprite);
    
    auto& backgroundAnimation1 = animator.CreateAnimation("background1", texture1, sf::seconds(1.2), true);
    backgroundAnimation1.AddFrames(sf::Vector2i(0,0), spriteSize, 8);
    
    auto& backgroundAnimation2 = animator.CreateAnimation("background2", texture2, sf::seconds(1.6), true);
    backgroundAnimation2.AddFrames(sf::Vector2i(0,0), sf::Vector2i(624,384), 12);
    
    sprite.setScale(1500./spriteSize.x, 700./spriteSize.y);
    
    sf::RectangleShape shape(sf::Vector2f(17, 95));
    shape.setFillColor(sf::Color(150, 150, 100));
    shape.setPosition(10, spriteSize.y*3.1f-130);

    sf::Vector2f guiSize(624*2.4f,0);
    
    sf::Texture guiTexture;
    guiTexture.loadFromFile(resourcePath() + "interface.png");
    
    sf::Texture leatherTexture;
    leatherTexture.loadFromFile(resourcePath() + "oldWood.jpg");
    
    sf::Texture guiTextTexture;
    guiTextTexture.loadFromFile(resourcePath() + "TextHUD.jpg");

    
    sf::Texture mapTexture;
    mapTexture.loadFromFile(resourcePath() + "Map.jpg");
    
    sf::Sprite Player;
    sf::Texture PlayerTexture;
    if (!PlayerTexture.loadFromFile(resourcePath() + "PlayerDefault.png")) {
        printf("fuck");
    }
//    Animator playerAnimator(PlayerTexture);
    sf::Vector2i framesize(-65,65);
    Animator PlayerAnimator(Player);
    auto& PlayerAnimation = PlayerAnimator.CreateAnimation("GetUp", PlayerTexture, sf::seconds(1.6), false);
    PlayerAnimation.AddFrames(sf::Vector2i(387,1279), framesize, 6);
    Player.setPosition(40, spriteSize.y*3.1f-145);
    Player.setScale(2,2);

    auto& PlayerAnimationRight = PlayerAnimator.CreateAnimation("MoveRight", PlayerTexture,sf::seconds(0.85),true);
    PlayerAnimationRight.AddFrames(sf::Vector2i(0,703), sf::Vector2i(64,65), 9);
    
    auto& PlayerAnimationLeft = PlayerAnimator.CreateAnimation("MoveLeft", PlayerTexture, sf::seconds(0.85),true);
    PlayerAnimationLeft.AddFrames(sf::Vector2i(0,575), sf::Vector2i(64,65), 9);

    auto& PlayerAnimationIdleLeft = PlayerAnimator.CreateAnimation("IdleLeft", PlayerTexture, sf::seconds(1), false);
    PlayerAnimationIdleLeft.AddFrames(sf::Vector2i(0,575), sf::Vector2i(64,65), 1);
    
    auto& PlayerAnimationIdleRight = PlayerAnimator.CreateAnimation("IdleRight", PlayerTexture, sf::seconds(1), false);
    PlayerAnimationIdleRight.AddFrames(sf::Vector2i(0,703), sf::Vector2i(64,65), 1);
    
    auto& PlayerAnimationAttackRight = PlayerAnimator.CreateAnimation("AttackRight", PlayerTexture, sf::seconds(0.25), false);
    PlayerAnimationAttackRight.AddFrames(sf::Vector2i(0,959), sf::Vector2i(64,65), 6);
    
    auto& PlayerAnimationAttackLeft = PlayerAnimator.CreateAnimation("AttackLeft", PlayerTexture, sf::seconds(0.40), false);
    PlayerAnimationAttackLeft.AddFrames(sf::Vector2i(0,831), sf::Vector2i(64,65), 6);
    
    std::vector<sf::Sprite> HUD = toolbox.DisplayHud(window, guiTexture, spriteSize, mapTexture, guiTextTexture, leatherTexture);
    bool start = false;
    bool go = false;
    sf::Clock clock;
    sf::Time deltaTime = clock.restart();
    PlayerAnimator.update(deltaTime);
    opt1.setPosition(25, sprite.getGlobalBounds().height+25);
    opt2.setPosition(1165-opt2.getLocalBounds().width/2, sprite.getGlobalBounds().height+15);
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
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) && (start == true)) {
                if (PlayerAnimator.IsAnimationPlaying() == false || PlayerAnimator.GetCurrentAnimationName() != "MoveRight")
                    PlayerAnimator.SwitchAnimation("MoveRight");
                Player.setPosition(Player.getPosition().x+10, Player.getPosition().y);
            }
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) && (start == true)) {
                 if (PlayerAnimator.IsAnimationPlaying() == false || PlayerAnimator.GetCurrentAnimationName() != "MoveLeft")
                     PlayerAnimator.SwitchAnimation("MoveLeft");
                Player.setPosition(Player.getPosition().x-10, Player.getPosition().y);
            }
            if (event.type != sf::Event::KeyPressed && start == true) {
                if (PlayerAnimator.GetCurrentAnimationName() == "MoveLeft" ||
                    (PlayerAnimator.GetCurrentAnimationName() == "AttackLeft" &&
                     PlayerAnimator.IsAnimationPlaying() == false))
                    PlayerAnimator.SwitchAnimation("IdleLeft");
                if (PlayerAnimator.GetCurrentAnimationName() == "MoveRight"||
                    (PlayerAnimator.GetCurrentAnimationName() == "AttackRight" &&
                    PlayerAnimator.IsAnimationPlaying() == false))
                    PlayerAnimator.SwitchAnimation("IdleRight");
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
            if (Player.getPosition().x >= sprite.getGlobalBounds().width - 70) {
                if (animator.GetCurrentAnimationName() != "background2") {
                    animator.SwitchAnimation("background2");
                    sprite.setScale(1500./624., 700./384.);
                    Player.setScale(4,4);
                    Player.setPosition(20, Player.getPosition().y-50);
                } else if (animator.GetCurrentAnimationName() != "background1") {
                    animator.SwitchAnimation("background1");
                    sprite.setScale(1500./spriteSize.x, 700./spriteSize.y);
                    Player.setScale(2,2);
                    Player.setPosition(20, spriteSize.y*3.1f-145);
                }
            }
            if (Player.getPosition().x <= 10) {
                if (animator.GetCurrentAnimationName() != "background2") {
                    animator.SwitchAnimation("background2");
                    sprite.setScale(1500./624., 700./384.);
                    Player.setScale(4,4);
                    Player.setPosition(spriteSize.x*1500./spriteSize.x-180, Player.getPosition().y-50);
                } else if (animator.GetCurrentAnimationName() != "background1") {
                    animator.SwitchAnimation("background1");
                    sprite.setScale(1500./spriteSize.x, 700./spriteSize.y);
                    Player.setScale(2,2);
                    Player.setPosition(spriteSize.x*1500./spriteSize.x-80, spriteSize.y*3.1f-145);
                }
            }
        }
        deltaTime = clock.restart();
        animator.update(deltaTime);
        if (go)
            PlayerAnimator.update(deltaTime);
        if (go == true && PlayerAnimator.IsAnimationPlaying() == false)
            start = true;
        window.clear(sf::Color::Black);
        
        // Draw the sprite
        window.draw(sprite);
        window.draw(Player);
//        window.draw(shape);
        for (int i = 0; i != HUD.size(); i++) {
            window.draw(HUD[i]);
        }
        window.draw(opt1);
        window.draw(opt2);
        window.display();
    }
}

void ModuleFront::mouseEvent(sf::Text &opt, sf::RenderWindow &window, float posX, float posY, int police, sf::Event &event) {
    if (opt.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
        opt.setFillColor(sf::Color::Yellow);
        opt.setCharacterSize(police+2);
    } else {
        opt.setFillColor(sf::Color::White);
        opt.setCharacterSize(police);
    }
    opt.setPosition(window.getSize().x/posX - opt.getLocalBounds().width/2.0f, window.getSize().y/posY);
}
