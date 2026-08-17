#include <SFML/Graphics.hpp>
#include <iostream>

// Exercise 2: [Stop Sign] On a 400x300 window, draw a stop sign: a red-ringed
// white circle with a black post behind it and "STOP" text centered on top.
int main()
{
    sf::RenderWindow window(sf::VideoMode({300, 400}), "Stop Sign");
    window.setFramerateLimit(60);

    // TODO: construct the circle (white fill, red outline) at the top of the sign

    // TODO: construct the post (black rectangle) behind/below the circle

    // TODO: load a font and set up the "STOP" text, centered on the circle

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Cyan);
        // TODO: draw post, circle, text (in that order)
        window.display();
    }

    return 0;
}
