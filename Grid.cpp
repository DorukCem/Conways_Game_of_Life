#include "Grid.hpp"
#include <iostream>

sf::RectangleShape get_rectangle(int i, int j, bool filled);


void Grid::reset()
{
   for (int i=0; i<NUM_VERTICAL_TILES; i++)
   {
      for (int j=0; j<NUM_HORIZONTAL_TILES; j++)
      {
         Grid::array[i][j] = false;
      }

   }
}

void Grid::print()
{

   for (int i=0; i<NUM_VERTICAL_TILES; i++)
   {
      for (int j=0; j<NUM_HORIZONTAL_TILES; j++)
      {
         std::cout << std::boolalpha << array[i][j] << " ";
      }
      std::cout << std::endl;
   }
}

void Grid::draw(sf::RenderWindow &window)
{
   for (int i=0; i<NUM_VERTICAL_TILES; i++)
      {
         for (int j=0; j<NUM_HORIZONTAL_TILES; j++)
         {
            
            bool filled = Grid::array[i][j];
            sf::RectangleShape rectangle = get_rectangle(i, j, filled);
            window.draw(rectangle);
            
         }
      }
}

void Grid::update()
{
   bool new_array[NUM_VERTICAL_TILES][NUM_HORIZONTAL_TILES];
   for (int i=0; i<NUM_VERTICAL_TILES; i++)
   {
      for (int j=0; j<NUM_HORIZONTAL_TILES; j++)
      {
         int num_adjacent_cells = check_nearby_cells(i, j);
         
         
         if (Grid::array[i][j])
         {
            if (num_adjacent_cells <2 or num_adjacent_cells>3) {new_array[i][j] = false;}
            else {new_array[i][j] = true;}
         }
         else
         {
            if (num_adjacent_cells == 3) {new_array[i][j] = true;}
            else {new_array[i][j] = false;}
         }
         //std::cout << i << ", " << j ;
         //std::cout <<" " <<std::boolalpha << new_array[i][j] << " " << std::endl;
      }
      
   }
   for (int i=0; i<NUM_VERTICAL_TILES; i++)
   {
      for (int j=0; j<NUM_HORIZONTAL_TILES; j++)
      {
         Grid::array[i][j] = new_array[i][j];
         //std::cout << std::boolalpha << new_array[i][j] << " ";
      }
      //std::cout << std::endl;
   }

}

bool is_valid(int i, int j)
{
   return (i>=0 and j>=0 and i < NUM_VERTICAL_TILES and j < NUM_HORIZONTAL_TILES);
}


int Grid::check_nearby_cells(int i, int j)
{
   int count = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            // Skip the (i, j) tile itself
            if (x == 0 and y == 0) {
                continue;
            }
            
            if (is_valid(i + x, j + y) and Grid::array[i + x][j + y]) {
                count++;
            }
        }
    }
    //std::cout << count << std::endl;
    return count;

}



sf::RectangleShape get_rectangle(int i, int j, bool filled)
{
   sf::RectangleShape rectangle;
   rectangle.setPosition(j*TILE_SIZE, i*TILE_SIZE);
   rectangle.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
   if (filled)
   {
      rectangle.setFillColor(sf::Color::White);
   }else{
      rectangle.setFillColor(sf::Color::Black);
   }
   rectangle.setOutlineColor(sf::Color::Red);
   rectangle.setOutlineThickness(1);
   return rectangle;
}





