#pragma once
#include "SFML/Graphics.hpp"

class PixelGameEngine {
 public:

   void StartGame();

 private:
   void DrawMap(sf::RenderWindow& window);
   void DrawRectangles(sf::RenderWindow& window, const double pos_x, const double pos_y, 
                       const double length_x, const double length_y);
   void DrawRectangles(sf::RenderWindow& window, sf::RectangleShape& rectangle);
   void DrawBoundary(sf::RenderWindow& window);
};

class GameObject {
 public:


 private:

};

