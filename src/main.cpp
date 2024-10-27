// Tutoriel : https://www.sfml-dev.org/tutorials/2.6/start-linux.php > Compiling a SFML Program

#include <SFML/Graphics.hpp>

int main()
{
    int screenWidth=1500;
    int screenHeight=1000;

    int widthRectangle=600;
    int heightRectangle=20;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML works!");

    //Balle
    sf::CircleShape circle;
    circle.setRadius(15);
    circle.setFillColor(sf::Color::Cyan);
    circle.setPosition(screenWidth/2, screenHeight/2);

    //Raquette joueur 1
    sf::RectangleShape rectangle1;
    rectangle1.setSize (sf::Vector2f (widthRectangle, heightRectangle));
    rectangle1.setFillColor(sf::Color::White);
    rectangle1.setPosition(screenWidth/2-(widthRectangle/2),0);

    //Raquette joueur 2
    sf::RectangleShape rectangle2;
    rectangle2.setSize (sf::Vector2f (widthRectangle, heightRectangle));
    rectangle2.setFillColor(sf::Color::White);
    rectangle2.setPosition(screenWidth/2-(widthRectangle/2),screenHeight-heightRectangle);

    //Horloge
    sf::Clock clock;

    //Vitesse raquette
    float speedRacket = 400;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //deltaTime
        float deltaTime = clock.restart().asSeconds();

        // Logic loop
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (rectangle1.getPosition().x >= 0)
            {
            rectangle1.move(-speedRacket * deltaTime,0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (rectangle1.getPosition().x <= screenWidth-widthRectangle)
            {
            rectangle1.move(+speedRacket * deltaTime,0); 
            }
        }

        // Draw loop
        window.clear();
        window.draw(circle);    //Affiche la balle
        window.draw(rectangle1);    //Affiche la raquette 1
        window.draw(rectangle2);    //Affiche la raquette 2
        window.display();
    }

    return 0;
}