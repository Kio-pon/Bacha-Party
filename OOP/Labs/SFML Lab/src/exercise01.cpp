#include <SFML/Graphics.hpp>

// Exercise 1: [Wrapped Moving Rectangle] Rewrite Example 03 (Moving
// Rectangle) so that the rectangle wraps around to the opposite edge of the
// window instead of stopping when it reaches a border.
int main()
{
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
                             "Wrapped Moving Rectangle");
    window.setFramerateLimit(60);

    sf::RectangleShape rectangle(sf::Vector2f(100.f, 50.f));
    rectangle.setPosition({350.f, 275.f});
    rectangle.setFillColor(sf::Color::Green);

    float speed = 5.0f;

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // TODO: move the rectangle based on arrow-key input (Up/Down/Left/Right)

        // TODO: wrap the rectangle to the opposite edge when it fully
        // leaves the window on any side

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
