#include "Grid.hpp"


Grid grid;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    grid.reset();
   
    grid.array[0][1] = true;
    grid.array[1][2] = true;
    grid.array[2][0] = true;
    grid.array[2][1] = true;
    grid.array[2][2] = true;
    //grid.print();
    
   

    window.setFramerateLimit(2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        grid.draw(window);
        window.display();
        grid.update();
    }

    return 0;
}

//make
//.\main