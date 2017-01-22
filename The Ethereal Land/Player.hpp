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

//struct S_Race {
//    std::string name;
//    S_stats stats;
//};

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
//    S_Race Race;
};

class Player {
    private:
        S_Player m_player;
        
    public:
        Player();
        void Init();
        void Player::Setup_class(std::string playerClass);
        S_Player recoverPlayer();
};
#endif /* Player_hpp */
