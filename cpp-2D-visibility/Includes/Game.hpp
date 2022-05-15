#pragma once
#include "SFML/Graphics.hpp"

class PixelGameEngine {
 public:
 
  void StartGame();

 private:
  void DrawMap(sf::RenderWindow& window);
  void DrawHero(sf::RenderWindow& window);
};


