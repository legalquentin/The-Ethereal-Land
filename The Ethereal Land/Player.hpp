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
#include "ResourcePath.hpp"
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
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::Sprite Effect;
    std::vector<sf::Texture> EffectTexture;
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
    void Setup_Animations(Animator &Animator);
public:
    Player();
    void Init(std::string PlayerName,std::string PlayerSurname,std::string PlayerClass,Animator&PlayerAnimator);
    S_Player recoverPlayer();
    void LevelUp();
    void Animate(std::string action, int speed);
    void Effects(Animator &Animator, sf::Sprite &EffectSprite);
    void Attack(std::string AttackType, Animator &PlayerAnimator, int &velocity);
};

#endif /* Player_hpp */
