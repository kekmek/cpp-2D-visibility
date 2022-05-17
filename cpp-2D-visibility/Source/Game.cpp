#include "Game.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <array>

#include "Heroes.hpp"

const int screen_resolution_x = 800;
const int screen_resolution_y = 600;

PixelGameEngine::PixelGameEngine() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    window_ = new sf::RenderWindow (sf::VideoMode(screen_resolution_x, screen_resolution_y), "", 
                            sf::Style::Default, settings);

    window_->setVerticalSyncEnabled(true);

    if(!texture_tank_right_.loadFromFile("Images/tankRight.png")) {
        exit(-1);
    }
    texture_tank_right_.setSmooth(true);

    if(!texture_tank_left_.loadFromFile("Images/tankLeft.png")) {
        exit(-1);
    }
    texture_tank_left_.setSmooth(true);

    if(!texture_tank_up_.loadFromFile("Images/tankDown.png")) {
        exit(-1);
    }
    texture_tank_up_.setSmooth(true);

    if(!texture_tank_down_.loadFromFile("Images/tankUp.png")) {
        exit(-1);
    }
    texture_tank_down_.setSmooth(true);
}

void PixelGameEngine::StartGame(NetWorkClient& Client) {
    Hero tank_me{};
    Hero tank_friend{};
    bool update = false;

    while(window_->isOpen()) {
        
        sf::Event event;

        while (window_->pollEvent(event)) {
            
            switch (event.type) {
                case sf::Event::Closed :
                    window_->close();
                    break;

                case sf::Event::KeyPressed :
                    switch (event.key.code) {
                        case sf::Keyboard::Escape :
                            window_->close();
                            break;
                    
                        case sf::Keyboard::W :
                            tank_me.ChangeDirection(Direction::DOWN);
                            tank_me.Move();
                            update = true;
                            break;

                        case sf::Keyboard::D :
                            tank_me.ChangeDirection(Direction::RIGHT);
                            tank_me.Move();
                            update = true;
                            break;

                        case sf::Keyboard::S :
                            tank_me.ChangeDirection(Direction::UP);
                            tank_me.Move();
                            update = true;
                            break;
                        
                        case sf::Keyboard::A :
                            tank_me.ChangeDirection(Direction::LEFT);
                            tank_me.Move();
                            update = true;
                            break;

                        default:
                            break;
                    }


                default:  
                    break;
            }

        }

        //if(update) {
            Client.SendDataToOpponent(tank_me);
            //update = false;
        //}

        Client.ReceiveDataFromOpponent(tank_friend);

        DrawHero(tank_me);
        DrawHero(tank_friend);
        window_->display();
        window_->clear();
    }

}

void PixelGameEngine::DrawMap() {
    
}

void PixelGameEngine::DrawHero(const Hero& tank) {
    sf::RectangleShape rectangle(sf::Vector2f(70, 70));

    switch (tank.GetDirection()) {
            case Direction::UP :
                rectangle.setTexture(&texture_tank_up_);
                break;

            case Direction::DOWN :
                rectangle.setTexture(&texture_tank_down_);
                break;

            case Direction::LEFT :
                rectangle.setTexture(&texture_tank_left_);
                break;

            case Direction::RIGHT :
                rectangle.setTexture(&texture_tank_right_);
                break;
            
            default:
                break;
    }
    auto coord = tank.GetCoord();
    rectangle.setPosition(sf::Vector2f(coord.first * 70, coord.second * 70));
    window_->draw(rectangle);
    
}

PixelGameEngine::~PixelGameEngine() {
    delete window_;
}