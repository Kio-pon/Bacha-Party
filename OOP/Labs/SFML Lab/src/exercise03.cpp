#include <SFML/Graphics.hpp>
#include <vector>

// Exercise 3: Paddle Ball game. The paddle moves left/right with the
// keyboard; balls bounce off the walls and paddle, and a new ball spawns
// periodically while everything speeds up over time. If a ball passes the
// paddle, the game pauses with a "Press Space to restart / Press C to close"
// message and a running score is shown.
class Player
{
public:
    sf::RectangleShape paddle;
    float speed;

    Player()
    {
        paddle.setSize(sf::Vector2f(80.f, 15.f));
        paddle.setFillColor(sf::Color::Green);
        paddle.setPosition({160.f, 270.f});
        speed = 6.f;
    }

    void clear()
    {
        paddle.setPosition({1000.f, 270.f});
    }
    void move()
    {
        // TODO: move the paddle left/right on arrow-key input, clamped to
        // the window bounds (window width is 400)
    }
};

int main()
{
    int width = 400;
    int height = 300;

    sf::RenderWindow window(sf::VideoMode({width, height}), "Paddle Ball Game");
    window.setFramerateLimit(60);

    std::vector<sf::CircleShape> balls;
    std::vector<sf::Vector2f> velocities;

    sf::CircleShape firstBall(20.f);
    firstBall.setFillColor(sf::Color(255, 255, 255));
    firstBall.setPosition({200.f, 150.f});
    balls.push_back(firstBall);
    velocities.push_back(sf::Vector2f(3.f, 3.f));

    sf::Clock speedClock;
    sf::Clock ballSpawnClock;
    Player player;

    bool paused = false;
    int score = 0;
    sf::Font font;
    font.openFromFile("arial.ttf");

    sf::Text message(font);
    message.setString("Press Space to restart\n      Press C to close");
    message.setCharacterSize(18);
    message.setFillColor(sf::Color::Red);
    message.setPosition({100.f, 130.f});

    sf::Text scoreText(font);
    scoreText.setString("Score: 0");
    scoreText.setCharacterSize(18);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({30.f, 30.f});

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (!paused)
        {
            // TODO: every 1 second, speed up the paddle and all ball velocities

            // TODO: every 5 seconds, spawn a new ball at the center

            player.move();

            // TODO: for each ball: move it, bounce off the left/right/top
            // walls, bounce off the paddle (and increment score on a paddle
            // hit), and set `paused = true` if a ball passes the paddle
        }
        else
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            {
                paused = false;

                balls.clear();
                velocities.clear();

                sf::CircleShape newBall(20.f);
                newBall.setFillColor(sf::Color(255, 255, 255));
                newBall.setPosition({200.f, 150.f});
                balls.push_back(newBall);
                velocities.push_back(sf::Vector2f(3.f, 3.f));

                player.speed = 6.f;
                player.paddle.setPosition({160.f, 270.f});
                score = 0;
                speedClock.restart();
                ballSpawnClock.restart();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C))
            {
                break;
            }
        }

        window.clear();

        for (const auto &ball : balls)
        {
            window.draw(ball);
        }

        window.draw(player.paddle);
        if (paused)
        {
            balls.clear();
            velocities.clear();
            player.clear();
            window.draw(message);
        }
        scoreText.setString("Score: " + std::to_string(score));

        window.draw(scoreText);
        window.display();
    }

    return 0;
}
