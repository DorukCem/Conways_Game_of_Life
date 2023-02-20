#include "Grid.hpp"
#include <iostream>

void handle_mouse(Grid &grid, sf::RenderWindow &window )
{
    sf::Vector2i position = sf::Mouse::getPosition(window);
    int x = position.x;
    int y = position.y;

    int i = int(y/TILE_SIZE);
    int j = int(x/TILE_SIZE);
    grid.change_tile(i,j);
}


Grid grid;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    grid.reset();
    bool draw_mode = true; 

    window.setFramerateLimit(60);

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
                    window.setFramerateLimit(4);
                }
            }
            if (not draw_mode and event.key.code == sf::Keyboard::LControl)
            {
                grid.reset();
                draw_mode = true;
            }
        }

        window.clear();
        grid.draw(window);
        window.display();
        if (not draw_mode) {grid.update();}
    }

    return 0;
}

//make
//.\main