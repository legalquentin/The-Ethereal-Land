//
//  Game.cpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 20/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#include "Game.hpp"

Game::Game() {
    
}

int Game::play(sf::RenderWindow &window) {
    
    // Declare stuff
    
    sf::Font font;
    sf::Texture guiTexture,leatherTexture,guiTextTexture,mapTexture,PlayerTexture;
    sf::Sprite sprite,PlayerSprite;
    sf::Vector2i spriteSize(624,224), guiSize(624*2.4f,0), framesize(-65,65);
    sf::Clock clock;
    bool lock,go;
    
    // Create the objects
    
    Tools toolbox;
    Animator animator(sprite);
    Animator PlayerAnimator(PlayerSprite);
    Player Hero;
    Scene GameScene;
    
    // Load the textures
    
    font.loadFromFile(resourcePath() + "Plain_Black.ttf");
    guiTexture.loadFromFile(resourcePath() + "interface.png");
    leatherTexture.loadFromFile(resourcePath() + "oldWood.jpg");
    guiTextTexture.loadFromFile(resourcePath() + "TextHUD.jpg");
    mapTexture.loadFromFile(resourcePath() + "Map.jpg");
    PlayerTexture.loadFromFile(resourcePath() + "PlayerDefault.png");
    lock = true;
    go = false;
    
    // init the player class
    Hero.Init("Arthur","Pandragon","Warrior",PlayerAnimator, PlayerTexture);
    
    // Generate The HUD
    std::vector<sf::Sprite> HUD = toolbox.DisplayHud(window, guiTexture, spriteSize, mapTexture, guiTextTexture, leatherTexture);

    sf::Time deltaTime = clock.restart();
    PlayerAnimator.update(deltaTime);
    
    // Write stuff
    
    sf::Text opt1("- press space to awake", font, 25);
    sf::Text opt2(Hero.recoverPlayer().name, font, 35);
    opt1.setFillColor(sf::Color::Black);
    opt2.setFillColor(sf::Color::White);
    
    GameScene.addScene(animator,sprite,"forest",1,8,sf::Vector2i(768,368),4,sf::Vector2i(40,spriteSize.y*700./spriteSize.y-215),30,30,PlayerSprite);
    
    GameScene.addScene(animator,sprite,"WaterFall",2,8,spriteSize,2,sf::Vector2i(40, spriteSize.y*3.1f-145),30, 30,PlayerSprite);
    GameScene.addScene(animator,sprite,"GreatWaterFalls", 3, 12, sf::Vector2i(624,384),4.2,sf::Vector2i(40,spriteSize.y*700./spriteSize.y-215),1,30,PlayerSprite);
    
    GameScene.SwitchScene(PlayerSprite, animator, 1, sprite);
    
    // Game loop
    GameScene.Play(Hero, sprite, PlayerSprite);
    
    opt1.setPosition(25, sprite.getGlobalBounds().height+25);
    opt2.setPosition(1165-opt2.getLocalBounds().width/2, 700);
    
    int velocity = 0;
    
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        
        // If Player attack is over switch to idle
        if (lock == false && PlayerAnimator.IsAnimationPlaying() == false) {
            if (PlayerAnimator.GetCurrentAnimationName() == "SimpleAttackLeft")
                PlayerAnimator.SwitchAnimation("IdleLeft");
            if (PlayerAnimator.GetCurrentAnimationName() == "SimpleAttackRight")
                PlayerAnimator.SwitchAnimation("IdleRight");
            if (PlayerAnimator.GetCurrentAnimationName() == "SimpleAttackBack")
                PlayerAnimator.SwitchAnimation("IdleBack");
            if (PlayerAnimator.GetCurrentAnimationName() == "SimpleAttackFront")
                PlayerAnimator.SwitchAnimation("IdleFront");
        }
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return 1;
            
            if (lock == false && event.type != sf::Event::KeyPressed) {
                if (PlayerAnimator.GetCurrentAnimationName() == "MoveLeft")
                    PlayerAnimator.SwitchAnimation("IdleLeft");
                if (PlayerAnimator.GetCurrentAnimationName() == "MoveRight")                    PlayerAnimator.SwitchAnimation("IdleRight");
            }
            
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) && (lock == false)) {
                if (PlayerAnimator.IsAnimationPlaying() == false || PlayerAnimator.GetCurrentAnimationName() != "MoveRight") {
                    PlayerAnimator.SwitchAnimation("MoveRight");
                }
                velocity = 200;
            }
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) && (lock == false)) {
                 if (PlayerAnimator.IsAnimationPlaying() == false || PlayerAnimator.GetCurrentAnimationName() != "MoveLeft")
                     PlayerAnimator.SwitchAnimation("MoveLeft");
                velocity = -200;
            }
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) && (lock == false)) {
//                if (PlayerAnimator.IsAnimationPlaying() == false || PlayerAnimator.GetCurrentAnimationName() == "MoveRight" ||  PlayerAnimator.GetCurrentAnimationName() == "MoveLeft" ) {
                    PlayerAnimator.SwitchAnimation("IdleFront");
//                }
                velocity = 0;
            }
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) && (lock == false)) {
//                if (PlayerAnimator.IsAnimationPlaying() == false || PlayerAnimator.GetCurrentAnimationName() == "MoveRight" ||  PlayerAnimator.GetCurrentAnimationName() == "MoveLeft" ) {
                    PlayerAnimator.SwitchAnimation("IdleBack");
//                }
                velocity = 0;
            }
            if (event.type == sf::Event::KeyReleased) {
                velocity = 0;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
                Hero.Attack("Simple", PlayerAnimator, velocity);
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                velocity = 0;
                go = true;
            }
            
            if (event.type == sf::Event::MouseMoved) { }
           
            if (event.type == sf::Event::MouseButtonPressed) { }
        }
      
        PlayerSprite.move(velocity * clock.getElapsedTime().asSeconds(), 0);
        
        deltaTime = clock.restart();
        animator.update(deltaTime);
        if (go)
            PlayerAnimator.update(deltaTime);
        if (go == true && PlayerAnimator.IsAnimationPlaying() == false)
            lock = false;
        window.clear(sf::Color::Black);
        
        GameScene.Update(PlayerSprite, animator, sprite, PlayerAnimator);
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
