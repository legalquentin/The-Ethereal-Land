//
//  Player.hpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 22/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include "Animator.hpp"

struct S_BaseStats {
    int str;
    int dext;
    int wis;
    int intel;
    int constit;
    int speed;
};

struct S_Stats {
    int dmg;
    int base_health;
    int base_mana;
    int base_stamina;
    // max and current
    int current_health;
    int current_mana;
    int current_stamina;
    S_BaseStats BaseStats;
};

struct S_Class {
    std::string name;
    S_BaseStats BaseStats;
};

struct S_Items {
    int gold;
};

struct S_Player {
    std::string name;
    std::string surname;
    std::string title;
    std::string playerTexture;
    sf::Sprite playerSprite;
    int age;
    int xp;
    int lvl;
    int status;
    S_Items Items;
    S_Stats Stats;
    S_Class playerClass;
};

class Player {

private:
    S_Player m_player;
    void Setup_class();
    void Setup_Animations(Animator &Animator, sf::Texture &Texture);
public:
    Player();
    void Init(std::string PlayerName,std::string PlayerSurname,std::string PlayerClass,Animator&PlayerAnimator, sf::Texture &PlayerTexture);
    S_Player recoverPlayer();
    void LevelUp();
    void Animate(std::string action, int speed);
};

#endif /* Player_hpp */
