#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

const int screenWidth = 800;
const int screenHeight = 600;
sf::CircleShape shape;
float xDirection = 1.0;
float yDirection = 1.0;
float speed = 1;
float shapeSize = 20.f;
void initSceneObjects()
{
    shape = sf::CircleShape(shapeSize);
    shape.setFillColor(sf::Color::Magenta);
}

void update()
{
    sf::Vector2f Position = shape.getPosition();
    
    if (Position.x < 0)
    {
        xDirection = 1.0;
    }
    
    if (Position.x > (screenWidth - shapeSize))
    {
        xDirection = -1.0;
    }

    if (Position.y < 0)
    {
        yDirection = 1.0;
    }
    
    if (Position.y > (screenHeight - shapeSize))
    {
        yDirection = -1.0;
    }
    shape.move(xDirection * speed, yDirection * speed);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML works!");
    
    initSceneObjects();

    sf::Music music;

    if (!music.openFromFile("resources/music.wav"))
    {
        return -1;
    }
    music.setVolume(20.0);
    music.play();

    // double t = 0.0;
    // double dt = 0.01;

    // auto currentTime = sf::Time::asMilliseconds;
    // double accumulator = 0.0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        update();
        window.clear();
        window.draw(shape);
        window.display();
    }    

    return 0;
}