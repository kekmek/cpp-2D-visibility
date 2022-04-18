#include "Game.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <array>

const int boundary_width = 10;

void PixelGameEngine::StartGame() {
    sf::RenderWindow window(sf::VideoMode(1024, 768), "");

    //window.setVerticalSyncEnabled(true);
    
    while(window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            
            switch (event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;

                default:  
                    break;
            }

        }
        
        PixelGameEngine::DrawMap(window);
    }

}

void PixelGameEngine::DrawMap(sf::RenderWindow& window) {
    PixelGameEngine::DrawBoundary(window);
}

void PixelGameEngine::DrawBoundary(sf::RenderWindow& window) {
    std::array<sf::RectangleShape, 2> boundary;
    boundary.at(0) = sf::RectangleShape(sf::Vector2f(window.getSize().x, boundary_width)); // horizontal
    boundary.at(1) = sf::RectangleShape(sf::Vector2f(boundary_width, window.getSize().y)); //  vertical
    
    boundary.at(0).setPosition(0, 0);
    boundary.at(1).setPosition(0, 0);
    PixelGameEngine::DrawRectangles(window, boundary.at(0));
    PixelGameEngine::DrawRectangles(window, boundary.at(1));


    boundary.at(0).setPosition(0, window.getSize().y - boundary_width);
    boundary.at(1).setPosition(window.getSize().x - boundary_width, 0);
    PixelGameEngine::DrawRectangles(window, boundary.at(0));
    PixelGameEngine::DrawRectangles(window, boundary.at(1));
}

void PixelGameEngine::DrawRectangles(sf::RenderWindow& window, const double pos_x, const double pos_y, 
                                    const double length_x, const double length_y) {
    sf::RectangleShape rectangle(sf::Vector2f(length_x, length_y));
    rectangle.setPosition(pos_x, pos_y);
    
    window.draw(rectangle);
    window.display();
}

void PixelGameEngine::DrawRectangles(sf::RenderWindow& window, sf::RectangleShape& rectangle) {
    window.draw(rectangle);
    window.display();
}