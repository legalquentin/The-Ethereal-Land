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

void Player::Init(std::string PlayerName,std::string PlayerSurname,std::string PlayerClass, Animator &PlayerAnimator, sf::Texture &PlayerTexture) {
    int rc,cl;
    m_player.xp = 0;
    m_player.lvl = 0;
    m_player.status = 0;
    m_player.name = PlayerSurname;
    m_player.surname = PlayerName;
    m_player.title = "";
    m_player.playerClass.name = PlayerClass;
    
    Setup_class();
    Setup_Animations(PlayerAnimator,PlayerTexture);
    LevelUp();
}

void Player::Setup_class() {
    std::vector<int> stats;
    if (m_player.playerClass.name == "Warrior")
        stats = {5,5,1,1,5};
    if (m_player.playerClass.name == "Ranger")
        stats = {2,5,4,3,3};
    if (m_player.playerClass.name == "Priest")
        stats = {1,2,6,6,2};
    m_player.playerClass.BaseStats.str = stats[0];
    m_player.playerClass.BaseStats.dext = stats[1];
    m_player.playerClass.BaseStats.wis = stats[2];
    m_player.playerClass.BaseStats.intel = stats[3];
    m_player.playerClass.BaseStats.constit = stats[4];
}

void Player::LevelUp() {
    
    // Uncomment if races become avaibles
    m_player.Stats.BaseStats.str += m_player.playerClass.BaseStats.str;// + m_player.Race.stats.str;
    m_player.Stats.BaseStats.dext += m_player.playerClass.BaseStats.dext;// + m_player.Race.stats.dext;
    m_player.Stats.BaseStats.wis += m_player.playerClass.BaseStats.wis;// + m_player.Race.stats.wis;
    m_player.Stats.BaseStats.intel += m_player.playerClass.BaseStats.intel;// + m_player.Race.stats.intel;
    m_player.Stats.BaseStats.constit += m_player.playerClass.BaseStats.constit;
    // + m_player.Race.stats.constit;
    m_player.Stats.BaseStats.speed += 1;
    
    m_player.Stats.base_health += m_player.Stats.BaseStats.constit;
    m_player.Stats.base_mana += m_player.Stats.BaseStats.intel;
    m_player.Stats.base_stamina += m_player.Stats.BaseStats.dext;
    
    // Restore full life, mana, stamina
    m_player.Stats.current_health = m_player.Stats.base_health;
    m_player.Stats.current_mana = m_player.Stats.base_mana;
    m_player.Stats.current_stamina = m_player.Stats.base_stamina;
    
    if (m_player.playerClass.name == "Warrior") m_player.Stats.dmg += m_player.Stats.BaseStats.str;
    if (m_player.playerClass.name == "Ranger") m_player.Stats.dmg += m_player.Stats.BaseStats.dext;
    if (m_player.playerClass.name == "Sorcerer") m_player.Stats.dmg += m_player.Stats.BaseStats.intel;
    m_player.lvl+=1;
}

void Player::Setup_Animations(Animator &Animator, sf::Texture &Texture) {
    auto& AnimationGetUp = Animator.CreateAnimation("GetUp", Texture, sf::seconds(1.6), false);
    AnimationGetUp.AddFrames(sf::Vector2i(452,1279), sf::Vector2i(-65,65), 6);
    
    auto& AnimationRight = Animator.CreateAnimation("MoveRight", Texture,sf::seconds(0.85),true);
    AnimationRight.AddFrames(sf::Vector2i(0,703), sf::Vector2i(64,65), 9);
    
    auto& AnimationLeft = Animator.CreateAnimation("MoveLeft", Texture, sf::seconds(0.85),true);
    AnimationLeft.AddFrames(sf::Vector2i(0,575), sf::Vector2i(64,65), 9);
    
    auto& AnimationIdleLeft = Animator.CreateAnimation("IdleLeft", Texture, sf::seconds(1), false);
    AnimationIdleLeft.AddFrames(sf::Vector2i(0,575), sf::Vector2i(65,65), 1);
    
    auto& AnimationIdleRight = Animator.CreateAnimation("IdleRight", Texture, sf::seconds(1), false);
    AnimationIdleRight.AddFrames(sf::Vector2i(0,703), sf::Vector2i(65,65), 1);
    
    auto& AnimationIdleBack = Animator.CreateAnimation("IdleBack", Texture, sf::seconds(1), false);
    AnimationIdleBack.AddFrames(sf::Vector2i(0,511), sf::Vector2i(65,65), 1);
    
    auto& AnimationIdleFront = Animator.CreateAnimation("IdleFront", Texture, sf::seconds(1), false);
    AnimationIdleFront.AddFrames(sf::Vector2i(0,640), sf::Vector2i(65,65), 1);
    
    auto& AnimationAttackRight = Animator.CreateAnimation("SimpleAttackRight", Texture, sf::seconds(0.5),false);
    AnimationAttackRight.AddFrames(sf::Vector2i(0,959), sf::Vector2i(64,65), 6);
    AnimationAttackRight.AddFrames(sf::Vector2i(320,959), sf::Vector2i(64,65), 1);
    AnimationAttackRight.AddFrames(sf::Vector2i(320,959), sf::Vector2i(64,65), 1);
    
    auto& AnimationAttackLeft = Animator.CreateAnimation("SimpleAttackLeft", Texture, sf::seconds(0.5),false);
    AnimationAttackLeft.AddFrames(sf::Vector2i(0,831), sf::Vector2i(64,65), 6);
    AnimationAttackLeft.AddFrames(sf::Vector2i(320,831), sf::Vector2i(64,65), 1);
    AnimationAttackLeft.AddFrames(sf::Vector2i(320,831), sf::Vector2i(64,65), 1);
    
    auto& AnimationAttackBack = Animator.CreateAnimation("SimpleAttackBack", Texture, sf::seconds(0.5),false);
    AnimationAttackBack.AddFrames(sf::Vector2i(0,767), sf::Vector2i(64,65), 6);
    AnimationAttackBack.AddFrames(sf::Vector2i(320,767), sf::Vector2i(64,65), 1);
    AnimationAttackBack.AddFrames(sf::Vector2i(320,767), sf::Vector2i(64,65), 1);
    
    auto& AnimationAttackFront = Animator.CreateAnimation("SimpleAttackFront", Texture, sf::seconds(0.5),false);
    AnimationAttackFront.AddFrames(sf::Vector2i(0,896), sf::Vector2i(64,65), 6);
    AnimationAttackFront.AddFrames(sf::Vector2i(320,896), sf::Vector2i(64,65), 1);
    AnimationAttackFront.AddFrames(sf::Vector2i(320,896), sf::Vector2i(64,65), 1);
    
    auto& AnimationMagicFront = Animator.CreateAnimation("MagicFront", Texture, sf::seconds(1),false);
    AnimationMagicFront.AddFrames(sf::Vector2i(0,128), sf::Vector2i(64,65), 7);
    AnimationMagicFront.AddFrames(sf::Vector2i(384,128), sf::Vector2i(64,65), 1);
    AnimationMagicFront.AddFrames(sf::Vector2i(384,128), sf::Vector2i(64,65), 1);
}

void Player::Attack(std::string AttackType, Animator &PlayerAnimator, int &velocity) {
    
    if (PlayerAnimator.GetCurrentAnimationName() == "MoveLeft" ||
        PlayerAnimator.GetCurrentAnimationName() == "IdleLeft")
        PlayerAnimator.SwitchAnimation(AttackType+"AttackLeft");
    
    if (PlayerAnimator.GetCurrentAnimationName() == "MoveRight" ||
        PlayerAnimator.GetCurrentAnimationName() == "IdleRight")
        PlayerAnimator.SwitchAnimation(AttackType+"AttackRight");
    
    if (PlayerAnimator.GetCurrentAnimationName() == "IdleBack")
        PlayerAnimator.SwitchAnimation(AttackType+"AttackBack");
    
    if (PlayerAnimator.GetCurrentAnimationName() == "IdleFront")
        PlayerAnimator.SwitchAnimation(AttackType+"AttackFront");
    
    velocity = 0;
}
