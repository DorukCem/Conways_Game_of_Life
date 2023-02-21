#include "Grid.hpp"
#include <iostream>


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
            new_array[i][j] = (num_adjacent_cells == 3);  
         }
      }
   }
   for (int i=0; i<NUM_VERTICAL_TILES; i++)
   {
      for (int j=0; j<NUM_HORIZONTAL_TILES; j++)
      {
         Grid::array[i][j] = new_array[i][j];
      }
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
    return count;
}







