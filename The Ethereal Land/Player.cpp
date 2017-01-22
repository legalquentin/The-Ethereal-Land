//
//  Player.cpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 22/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//

#include "Player.hpp"

Player::Player() {
}

S_Player Player::recoverPlayer() {
    return m_player;
}

void Player::Init() {
    int rc,cl;
    m_player.xp = 0;
    m_player.lvl = 0;
    m_player.status = 0;
    m_player.name = "Pandragon";
    m_player.surname = "";
    m_player.title = "test";
//    std::vector<std::string> Races = {"Human", "Dwarf", "Elf", "Hobbit"};
//    std::vector<std::string> Display_Races = {"\e[1m\e[94mHuman\e[0m\e[39m\e[21m", "\e[1m\e[33mDwarf\e[0m\e[39m\e[21m", "\e[1m\e[32mElf\e[0m\e[39m\e[21m", "Hobbit"};
    std::vector<std::string> Classes = {"Ranger", "Warrior", "Priest"};
    
    m_player.playerClass.name = "Warrior";
    
//    Levelup();
//    Set_Name();
}

//void Player::Setup_race(int str, int dext, int wis, int intel, int constit, int age){
//    m_player.Race.stats.str = str;
//    m_player.Race.stats.dext = dext;
//    m_player.Race.stats.wis = wis;
//    m_player.Race.stats.intel = intel;
//    m_player.Race.stats.constit = constit;
//    m_player.age = age;
//}

void Player::Setup_class(std::string playerClass) {
    if (playerClass == "Warrior")
        std::vector<int> stats = {5,5,1,1,5};
    if (playerClass == "Ranger")
        std::vector<int> stats = {2,5,4,3,3};
    if (playerClass == "Priest")
        std::vector<int> stats = {1,2,6,6,2};
    }
    m_player.playerClass.stats.str = stats[0];
    m_player.playerClass.stats.dext = stats[1];
    m_player.playerClass.stats.wis = stats[2];
    m_player.playerClass.stats.intel = stats[3];
    m_player.playerClass.stats.constit = stats[4];
}

void Player::Levelup() {
    m_player.Stats.str += m_player.Classe.stats.str + m_player.Race.stats.str;
    m_player.Stats.dext += m_player.Classe.stats.dext + m_player.Race.stats.dext;
    m_player.Stats.wis += m_player.Classe.stats.wis + m_player.Race.stats.wis;
    m_player.Stats.intel += m_player.Classe.stats.intel + m_player.Race.stats.intel;
    m_player.Stats.constit += m_player.Classe.stats.constit + m_player.Race.stats.constit;
    m_player.Stats.speed += 1;
    
    m_player.Stats.max_health += m_player.Stats.constit;
    m_player.Stats.max_mana += m_player.Stats.intel;
    m_player.Stats.max_stamina += m_player.Stats.dext;
    
    m_player.Stats.current_health = m_player.Stats.max_health;
    m_player.Stats.current_mana = m_player.Stats.max_mana;
    m_player.Stats.current_stamina = m_player.Stats.max_stamina;
    
    if (m_player.Classe.name == "Warrior") m_player.Stats.dmg += m_player.Stats.str;
    if (m_player.Classe.name == "Ranger") m_player.Stats.dmg += m_player.Stats.dext;
    if (m_player.Classe.name == "Sorcerer") m_player.Stats.dmg += m_player.Stats.intel;
    m_player.lvl++;
}

void Player::Set_Name() {
    std::string name, validate, surname;
    
    system("clear");
    printf("Name : ");
    std::getline (std::cin,name);
    m_player.name = name;
    printf("Surname : ");
    std::getline (std::cin,surname);
    m_player.surname = surname;
    printf("\n is that you true self ? (n/y)\n");
    std::getline(std::cin,validate);
    while ((std::strcmp(validate.c_str(),"n") != 0) && (std::strcmp(validate.c_str(),"y") != 0)) {
        printf("%c[2K", 27);
        std::getline(std::cin,validate);
    }
    if (std::strcmp(validate.c_str(),"n") == 0)
        Set_Name();
}
