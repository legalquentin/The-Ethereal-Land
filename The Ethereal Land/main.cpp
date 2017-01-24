
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//
#include "ResourcePath.hpp"
#include "main.hpp"

int main(int, char const**)
{
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window");

    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Menu intro;
    Game front;
    Player Hero;
    Creator creation;
    
    sf::Music music;
    music.openFromFile(resourcePath() + "nice_music.ogg");
    music.setLoop(true);
    music.play();
    
    // Game loop
    while (intro.play(window) == 1) {
//        creation.play(window, Hero);
        music.stop();
        front.play(window, Hero);
    }
    
    return EXIT_SUCCESS;
}
