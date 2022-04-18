#include "Game.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <array>

const int boundary_width = 10;

void PixelGameEngine::StartGame() {
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "", sf::Style::Default, settings);
    
    window.setVerticalSyncEnabled(true);
    
    while(window.isOpen()) {
        PixelGameEngine::DrawMap(window);
        PixelGameEngine::DrawHero(window);
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

        
        window.display();
        window.clear();
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
    
}

void PixelGameEngine::DrawRectangles(sf::RenderWindow& window, sf::RectangleShape& rectangle) {
    //window.clear();
    window.draw(rectangle);
    
}

void PixelGameEngine::DrawHero(sf::RenderWindow& window) {
    sf::Texture texture;
     if(!texture.loadFromFile("./Images/light.png")) {
        window.close();
        return;
    }

    texture.setSmooth(true);
    sf::CircleShape circle(50.f);
    circle.setTexture(&texture);

    sf::Vector2i local_position = sf::Mouse::getPosition(window);
    circle.setPosition(local_position.x - 50.f, local_position.y - 50.f);
    
    window.draw(circle);
    
}