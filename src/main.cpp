// Tutoriel : https://www.sfml-dev.org/tutorials/2.6/start-linux.php > Compiling a SFML Program

#include <SFML/Graphics.hpp>

int main()
{
    int screenWidth=1500;
    int screenHeight=1000;

    int widthRectangle=600;
    int heightRectangle=20;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML works!");

    sf::CircleShape circle;
    circle.setRadius(15);
    circle.setFillColor(sf::Color::Cyan);
    circle.setPosition(screenWidth/2, screenHeight/2);

    sf::RectangleShape rectangle1;
    rectangle1.setSize (sf::Vector2f (widthRectangle, heightRectangle));
    rectangle1.setFillColor(sf::Color::White);
    rectangle1.setPosition(750-(widthRectangle/2),0);

    sf::RectangleShape rectangle2;
    rectangle2.setSize (sf::Vector2f (widthRectangle, heightRectangle));
    rectangle2.setFillColor(sf::Color::White);
    rectangle2.setPosition(750-(widthRectangle/2),screenHeight-heightRectangle);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.display();
    }

    return 0;
}