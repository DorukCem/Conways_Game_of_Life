#include "Grid.hpp"

void handle_mouse(Grid &grid, sf::RenderWindow &window )
{
    sf::Vector2i position = sf::Mouse::getPosition(window);
    int x = position.x;
    int y = position.y;

    int i = int(y/TILE_SIZE);
    int j = int(x/TILE_SIZE);
    grid.change_tile(i,j);
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


void draw(Grid &grid, sf::RenderWindow &window)
{
   for (int i=0; i<NUM_VERTICAL_TILES; i++)
      {
         for (int j=0; j<NUM_HORIZONTAL_TILES; j++)
         {    
            bool filled = grid.array[i][j];
            sf::RectangleShape rectangle = get_rectangle(i, j, filled);
            window.draw(rectangle);   
         }
      }
}


Grid grid;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    grid.reset();
    bool draw_mode = true; 

    window.setFramerateLimit(NORMAL_FPS);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (draw_mode)
            {
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    handle_mouse(grid, window);
                }
                if (event.key.code == sf::Keyboard::Space)
                {
                    draw_mode = false;
                    window.setFramerateLimit(ANIMATION_FPS);
                }
            }
            if (not draw_mode and event.key.code == sf::Keyboard::LControl)
            {
                grid.reset();
                draw_mode = true;
                window.setFramerateLimit(NORMAL_FPS);
            }
        }

        window.clear();
        draw(grid, window);
        window.display();
        if (not draw_mode) {grid.update();}
    }

    return 0;
}

//make
//.\main