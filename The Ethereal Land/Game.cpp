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

int Game::play(sf::RenderWindow &window, Player &Hero) {
    
    // Declare stuff
    
    sf::Sprite sprite,PlayerSprite, EffectSprite;
    sf::Vector2i spriteSize(624,224), guiSize(624*2.4f,0), framesize(-65,65);
    sf::Clock clock;
    sf::Music Forest, Waterfalls;
    bool lock,go;
    
    // Create the objects
    
    Tools toolbox;
    Animator animator(sprite);
    Animator EffectAnimator(EffectSprite);
    Animator PlayerAnimator(PlayerSprite);
    Scene GameScene;
    
    // Load the textures
    
    m_Textures.font.loadFromFile(resourcePath() + "Plain_Black.ttf");
    m_Textures.GUI.loadFromFile(resourcePath() + "interface.png");
    m_Textures.woodTexture.loadFromFile(resourcePath() + "oldWood.jpg");
    m_Textures.guiTextTexture.loadFromFile(resourcePath() + "TextHUD.jpg");
    m_Textures.Map.loadFromFile(resourcePath() + "Map.jpg");
    lock = true;
    go = false;
    
    Forest.openFromFile(resourcePath()+"Ambient.ogg");
    
    // init the player class
    Hero.Init("Arthur","Pandragon","Warrior",PlayerAnimator);
    
    // Generate The HUD
    std::vector<sf::Sprite> HUD = toolbox.DisplayHud(window, m_Textures.GUI, spriteSize, m_Textures.Map,m_Textures.guiTextTexture, m_Textures.woodTexture);

    sf::Time deltaTime = clock.restart();
    PlayerAnimator.update(deltaTime);
    
    // Write stuff
    
    sf::Text opt1("- press space to awake", m_Textures.font, 25);
    sf::Text opt2(Hero.recoverPlayer().name, m_Textures.font, 35);
    opt1.setFillColor(sf::Color::Black);
    opt2.setFillColor(sf::Color::White);
    
    GameScene.AddScene(animator,sprite,"MysticCave",1,10,sf::Vector2i(800,336),4,sf::Vector2i(40,spriteSize.y*700./spriteSize.y-215),30,30,PlayerSprite, 2);
    GameScene.AddScene(animator,sprite,"ForestCave",2,8,sf::Vector2i(768,368),4,sf::Vector2i(40,spriteSize.y*700./spriteSize.y-215),30,30,PlayerSprite, 1);
    GameScene.AddScene(animator,sprite,"WaterFall",3,8,spriteSize,2,sf::Vector2i(40, spriteSize.y*3.1f-145),30, 30,PlayerSprite, 1);
    GameScene.AddScene(animator,sprite,"GreatWaterFalls", 4, 12, sf::Vector2i(624,384),4.2,sf::Vector2i(40,spriteSize.y*700./spriteSize.y-215),1,30,PlayerSprite,1);
    
    GameScene.SwitchScene(PlayerSprite, animator, 2, sprite);
    
    // Game loop
    GameScene.Play(Hero, sprite, PlayerSprite);
    
    opt1.setPosition(25, sprite.getGlobalBounds().height+25);
    opt2.setPosition(1165-opt2.getLocalBounds().width/2, 700);
    Hero.Effects(EffectAnimator, EffectSprite);
    EffectSprite.setScale(2,2);
    
    Forest.play();
    int velocity = 0;
    
    while (window.isOpen())
    {
        sf::Event event;
        
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
                PlayerAnimator.SwitchAnimation("IdleFront");
                velocity = 0;
            }
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) && (lock == false)) {
                PlayerAnimator.SwitchAnimation("IdleBack");
                velocity = 0;
            }
            if (event.type == sf::Event::KeyReleased) {
                velocity = 0;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
                Hero.Attack("Simple", PlayerAnimator, velocity);
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::G) {
                velocity = 0;
                PlayerAnimator.SwitchAnimation("MagicFront");
                GameScene.AddEffect(PlayerSprite, EffectSprite, EffectAnimator,"MagicFireAura",1);
                lock = true;
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::H) {
                velocity = 0;
                PlayerAnimator.SwitchAnimation("MagicFront");
                GameScene.AddEffect(PlayerSprite, EffectSprite, EffectAnimator,"MagicFireAura",2);
                lock = true;
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                velocity = 0;
                go = true;
            }
            
            if (event.type == sf::Event::MouseMoved) { }
           
            if (event.type == sf::Event::MouseButtonPressed) { }
        }
        
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

        PlayerSprite.move(velocity * clock.getElapsedTime().asSeconds(), 0);
        
        deltaTime = clock.restart();
        animator.update(deltaTime);
        EffectAnimator.update(deltaTime);
        if (go)
            PlayerAnimator.update(deltaTime);
        if (go == true && PlayerAnimator.IsAnimationPlaying() == false)
            lock = false;
        window.clear(sf::Color::Black);
        
        GameScene.Update(PlayerSprite, animator, sprite, PlayerAnimator);
        // Draw the sprite
        window.draw(sprite);
        window.draw(PlayerSprite);
        window.draw(EffectSprite);
        for (int i = 0; i != HUD.size(); i++) {
            window.draw(HUD[i]);
        }
        window.draw(opt1);
        window.draw(opt2);
        window.display();
    }
}
