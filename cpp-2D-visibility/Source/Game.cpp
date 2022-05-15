#include "Game.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <array>

const int boundary_width = 20;
const int wall_width = 1;

const int screen_resolution_x = 1920;
const int screen_resolution_y = 1080;

void PixelGameEngine::StartGame() {
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(screen_resolution_x, screen_resolution_y), "", 
                            sf::Style::Fullscreen, settings);
    
    window.setVerticalSyncEnabled(true);
    
    while(window.isOpen()) {
        
        sf::Event event;

        while (window.pollEvent(event)) {
            
            switch (event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;

                case sf::Event::KeyPressed :
                    if(event.key.code == sf::Keyboard::Escape) window.close();
                    break;
                default:  
                    break;
            }

        }

        window.display();
        window.clear();
    }

}

void PixelGameEngine::DrawMap(sf::RenderWindow& window) {
    
}

void PixelGameEngine::DrawHero(sf::RenderWindow& window) {
    
    
}