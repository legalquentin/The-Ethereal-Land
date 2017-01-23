//
//  Tools.cpp
//  The Ethereal Land
//
//  Created by Quentin Le Gal on 21/01/2017.
//  Copyright © 2017 Quentin Le Gal. All rights reserved.
//
// textures coordinates list (sf::IntRect)
// (25, 238, 92, 92) - corner decoration
// (94, 373, 122, 61) - plain background
// (21, 373, 61, 122) - side background
// (96, 443, 122, 61) - bottom background
// (21, 506, 61, 61) - corner background
// (15, 52, 168, 29) - framed button
// (15, 22, 218, 22) - long text field
// (15, 123, 113, 106) - item bubble
// (189, 63, 22, 127) - long Frame
// (137, 194, 127, 30) - tab frame
//
// (spriteSize.x*1500./spriteSize.x)+((window.sf::Window::getSize().x-spriteSize.x*1500./spriteSize.x)/2)-Tbubble.getLocalBounds().width/2



#include "Tools.hpp"

Tools::Tools() {
}

std::vector<sf::Sprite> Tools::DisplayHud(sf::RenderWindow &window, sf::Texture &guiTexture, sf::Vector2i spriteSize, sf::Texture &mapTexture, sf::Texture &guiTextTexture, sf::Texture &leatherTexture) {

    sf::IntRect CornerDecoration(25, 238, 92, 92);
    sf::IntRect SideBackground(21, 373, 61, 122);
    sf::IntRect PlainBackground(94, 373, 122, 61);
    sf::IntRect CornerBackground(21, 506, 61, 61);
    sf::IntRect BottomBackground(96, 443, 122, 61);
    sf::IntRect VerticalFrame(189, 63, 22, 127);
    sf::IntRect TabFrame(137, 194, 127, 30);
    

    // Bot left HUD

    sf::Sprite BLTextZone(guiTextTexture);
    BLTextZone.setTextureRect(sf::IntRect(0, 0, 564, 859));
    BLTextZone.setRotation(-90);
    BLTextZone.setPosition(sf::Vector2f(0, spriteSize.y*700./spriteSize.y+BLTextZone.getLocalBounds().width));
    
    sf::Sprite BLtopLeft(guiTexture);
    BLtopLeft.setTextureRect(CornerDecoration);
    BLtopLeft.setPosition(sf::Vector2f(0, spriteSize.y*700./spriteSize.y));

    sf::Sprite BLtopRight(guiTexture);
    BLtopRight.setTextureRect(CornerDecoration);
    BLtopRight.setRotation(90);
    BLtopRight.setPosition(sf::Vector2f(BLTextZone.getLocalBounds().height, spriteSize.y*700./spriteSize.y));

    sf::Sprite BLbotRight(guiTexture);
    BLbotRight.setTextureRect(CornerDecoration);
    BLbotRight.setRotation(180);
    BLbotRight.setPosition(sf::Vector2f(BLTextZone.getLocalBounds().height, window.sf::Window::getSize().y));

    sf::Sprite BLbotLeft(guiTexture);
    BLbotLeft.setTextureRect(CornerDecoration);
    BLbotLeft.setRotation(270);
    BLbotLeft.setPosition(sf::Vector2f(0, window.sf::Window::getSize().y));
    
    // Bot right HUD

    sf::Sprite BRtopLeft(guiTexture);
    BRtopLeft.setTextureRect(CornerDecoration);
    BRtopLeft.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x, spriteSize.y*700./spriteSize.y));

    sf::Sprite BRtopRight(guiTexture);
    BRtopRight.setTextureRect(CornerDecoration);
    BRtopRight.setRotation(90);
    BRtopRight.setPosition(sf::Vector2f( window.sf::Window::getSize().x, spriteSize.y*700./spriteSize.y));

    sf::Sprite BRbotRight(guiTexture);
    BRbotRight.setTextureRect(CornerDecoration);
    BRbotRight.setRotation(180);
    BRbotRight.setPosition(sf::Vector2f(window.sf::Window::getSize().x, window.sf::Window::getSize().y));

    sf::Sprite BRbotLeft(guiTexture);
    BRbotLeft.setTextureRect(CornerDecoration);
    BRbotLeft.setRotation(270);
    BRbotLeft.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x, window.sf::Window::getSize().y));

    sf::Sprite BRmapImage(mapTexture);
    BRmapImage.setTextureRect(sf::IntRect(0, 0, 1024, 1024));
    BRmapImage.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x,spriteSize.y*700./spriteSize.y));
    BRmapImage.setScale((window.sf::Window::getSize().x-spriteSize.x*1500./spriteSize.x)/1024., (window.sf::Window::getSize().y-spriteSize.y*700./spriteSize.y)/1024.);

    // Top right HUD

    sf::Sprite TtopLeft(guiTexture);
    TtopLeft.setTextureRect(CornerDecoration);
    TtopLeft.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x, 0));

    sf::Sprite TtopRight(guiTexture);
    TtopRight.setTextureRect(CornerDecoration);
    TtopRight.setRotation(90);
    TtopRight.setPosition(sf::Vector2f(window.sf::Window::getSize().x, 0));

    sf::Sprite TbotRight(guiTexture);
    TbotRight.setTextureRect(CornerDecoration);
    TbotRight.setRotation(180);
    TbotRight.setPosition(sf::Vector2f(window.sf::Window::getSize().x, spriteSize.y*700./spriteSize.y));

    sf::Sprite TbotLeft(guiTexture);
    TbotLeft.setTextureRect(CornerDecoration);
    TbotLeft.setRotation(270);
    TbotLeft.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x, spriteSize.y*700./spriteSize.y));

    sf::Sprite TsideLeft1(guiTexture);
    TsideLeft1.setTextureRect(SideBackground);
    TsideLeft1.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x, 0));
    TsideLeft1.setScale((window.sf::Window::getSize().x-spriteSize.x*1500./spriteSize.x)/122, ((spriteSize.y*700./spriteSize.y)/244));
    
    sf::Sprite TsidebarLeft1(guiTexture);
    TsidebarLeft1.setTextureRect(VerticalFrame);
    TsidebarLeft1.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x, 0));
    TsidebarLeft1.setScale(1.6, (spriteSize.y*700./spriteSize.y)/127);

    sf::Sprite TsideLeft2(guiTexture);
    TsideLeft2.setTextureRect(SideBackground);
    TsideLeft2.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x, (spriteSize.y*700./spriteSize.y)/2));
    TsideLeft2.setScale((window.sf::Window::getSize().x-spriteSize.x*1500./spriteSize.x)/122, ((spriteSize.y*700./spriteSize.y)/244));
    
    sf::Sprite TsidebarLeft2(guiTexture);
    TsidebarLeft2.setTextureRect(VerticalFrame);
    TsidebarLeft2.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x, (spriteSize.y*700./spriteSize.y)/2));
    TsidebarLeft2.setScale(1.6,(spriteSize.y*700./spriteSize.y)/127);

    sf::Sprite TsideRight1(guiTexture);
    TsideRight1.setTextureRect(SideBackground);
    TsideRight1.setPosition(sf::Vector2f(window.sf::Window::getSize().x, 0));
    TsideRight1.setScale((window.sf::Window::getSize().x-spriteSize.x*1500./spriteSize.x)/122*-1, ((spriteSize.y*700./spriteSize.y)/244));
    
    sf::Sprite TsidebarRight1(guiTexture);
    TsidebarRight1.setTextureRect(VerticalFrame);
    TsidebarRight1.setPosition(sf::Vector2f(window.sf::Window::getSize().x, 0));
    TsidebarRight1.setScale(-1.6, (spriteSize.y*700./spriteSize.y)/127);

    sf::Sprite TsideRight2(guiTexture);
    TsideRight2.setTextureRect(SideBackground);
    TsideRight2.setPosition(sf::Vector2f(window.sf::Window::getSize().x, (spriteSize.y*700./spriteSize.y)/2));
    TsideRight2.setScale((window.sf::Window::getSize().x-spriteSize.x*1500./spriteSize.x)/122*-1, ((spriteSize.y*700./spriteSize.y)/244));
    
    sf::Sprite TsidebarRight2(guiTexture);
    TsidebarRight2.setTextureRect(VerticalFrame);
    TsidebarRight2.setPosition(sf::Vector2f(window.sf::Window::getSize().x, (spriteSize.y*700./spriteSize.y)/2));
    TsidebarRight2.setScale(-1.6, (spriteSize.y*700./spriteSize.y)/127);

    sf::Sprite Tbubble(guiTexture);
    Tbubble.setTextureRect(sf::IntRect(15, 123, 113, 106));
    Tbubble.setScale(1.5, 1.5);
    Tbubble.setPosition(sf::Vector2f((spriteSize.x*1500./spriteSize.x)+((window.sf::Window::getSize().x-spriteSize.x*1500./spriteSize.x)/2)-(Tbubble.getLocalBounds().width/2)*1.5,10));
    
    sf::Sprite Ttab1(guiTexture);
    Ttab1.setTextureRect(TabFrame);
    Ttab1.setScale(1.2, 2.4);
    Ttab1.setPosition(sf::Vector2f((spriteSize.x*1500./spriteSize.x)+((window.sf::Window::getSize().x-spriteSize.x*1500./spriteSize.x)/2)-(Ttab1.getLocalBounds().width)*1.2,70));

    sf::Sprite Ttab2(guiTexture);
    Ttab2.setTextureRect(TabFrame);
    Ttab2.setScale(1.2, 2.4);
    Ttab2.setPosition(sf::Vector2f((spriteSize.x*1500./spriteSize.x)+((window.sf::Window::getSize().x-spriteSize.x*1500./spriteSize.x)/2),70));
    
    sf::Sprite Tbackground(leatherTexture);
    //    BMbackground.setTextureRect();
    Tbackground.setTexture(leatherTexture);
    Tbackground.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x, 0));
    Tbackground.setScale(1,1);


    // Bot mid HUD
    
    sf::Sprite BMtopLeft(guiTexture);
    BMtopLeft.setTextureRect(CornerDecoration);
    BMtopLeft.setPosition(sf::Vector2f(BLTextZone.getLocalBounds().height, spriteSize.y*700./spriteSize.y));
    
    sf::Sprite BMtopRight(guiTexture);
    BMtopRight.setTextureRect(CornerDecoration);
    BMtopRight.setRotation(90);
    BMtopRight.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x, spriteSize.y*700./spriteSize.y));
    
    sf::Sprite BMbotRight(guiTexture);
    BMbotRight.setTextureRect(CornerDecoration);
    BMbotRight.setRotation(180);
    BMbotRight.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x, window.sf::Window::getSize().y));
    
    sf::Sprite BMbotLeft(guiTexture);
    BMbotLeft.setTextureRect(CornerDecoration);
    BMbotLeft.setRotation(270);
    BMbotLeft.setPosition(sf::Vector2f(BLTextZone.getLocalBounds().height, window.sf::Window::getSize().y));
    
    sf::Sprite BMbackground(leatherTexture);
//    BMbackground.setTextureRect();
    BMbackground.setTexture(leatherTexture);
    BMbackground.setRotation(90);
    BMbackground.setPosition(sf::Vector2f(spriteSize.x*1500./spriteSize.x, spriteSize.y*700./spriteSize.y));
    BMbackground.setScale(BLTextZone.getLocalBounds().width/leatherTexture.getSize().y, (spriteSize.x*1500./spriteSize.x-BLTextZone.getLocalBounds().height)/leatherTexture.getSize().x);
    // Send back all of the sprites as an array

    return {Tbackground,BLTextZone,TsidebarLeft1,TsidebarLeft2,TsidebarRight1,TsidebarRight2,BRmapImage,BMbackground,TtopLeft,TtopRight,TbotRight,TbotLeft,BLtopLeft,BLtopRight,BLbotRight,BLbotLeft,BRtopLeft,BRtopRight,BRbotRight,BRbotLeft,BMbotLeft,BMbotRight,BMtopLeft,BMtopRight,Ttab1,Ttab2, Tbubble};
}
