#pragma once
#include "settings.hpp"
#include <SFML/Graphics.hpp>

class Grid{

public:

   void reset();
   void update();
   void print();
   void draw(sf::RenderWindow &window);
   int check_nearby_cells(int i, int j);
   void change_tile(int i, int j){Grid::array[i][j] = !Grid::array[i][j];}
   
   bool array[NUM_VERTICAL_TILES][NUM_HORIZONTAL_TILES];


};

  

