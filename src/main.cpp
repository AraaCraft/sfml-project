// Tutorial : https://www.sfml-dev.org/tutorials/2.6/start-linux.php > Compiling a SFML Program

#include <SFML/Graphics.hpp>

int main()
{
    int screenWidth=1500;       //Largeur fenêtre
    int screenHeight=1000;      //Hauteur fenêtre

    int widthRacket=300;        //Largeur d'une raquette
    int heightRacket=20;        //Hauteur d'une raquette

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML works!");

    //Balle
    sf::CircleShape ball;
    int sizeBall = 15;
    ball.setRadius(sizeBall);
    ball.setFillColor(sf::Color::Cyan);
    ball.setPosition(screenWidth/2, screenHeight/2);

    //Raquette joueur 1 (haut)
    sf::RectangleShape racket1;
    racket1.setSize (sf::Vector2f (widthRacket, heightRacket));
    racket1.setFillColor(sf::Color::White);
    racket1.setPosition(screenWidth/2-(widthRacket/2),0);

    //Raquette joueur 2 (bas)
    sf::RectangleShape racket2;
    racket2.setSize (sf::Vector2f (widthRacket, heightRacket));
    racket2.setFillColor(sf::Color::White);
    racket2.setPosition(screenWidth/2-(widthRacket/2),screenHeight-heightRacket);

    //Horloge
    sf::Clock clock;

    //Vitesse raquette
    float speedRacket = 800;
    //Vitesse balle
    float speedBall = 600;

    //Détermine si la balle a le droit de bouger
    bool ballCanMove = false;

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



        // // Logic loop
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))            //Ball movement
        {
            ballCanMove = true;
        }

        if (ballCanMove == true)
        {
            ball.move(0, -speedBall * deltaTime);
        }

        

        if ((ball.getPosition().x >= racket1.getPosition().x  //Si la position x de la balle est à droite de la raquette
        && ball.getPosition().y >= racket1.getPosition().y) //ET que sa position y est en bas de la raquette

        &&               //COLLISION racket1
        
        (ball.getPosition().x <= (racket1.getPosition().x + widthRacket)) //ET que sa position x est à gauche de la raquette
        && ball.getPosition().y <= (racket1.getPosition().y + heightRacket)) //ET que sa position y est en haut de la raquette
        {
            speedBall = -speedBall;
        }

          if ((ball.getPosition().x >= racket2.getPosition().x - sizeBall 
        && ball.getPosition().y >= racket2.getPosition().y - sizeBall) 

        &&               //COLLISION racket2                                                // FIXME : Régler le soucis d'enfoncement de la balle
        
        (ball.getPosition().x <= (racket2.getPosition().x + widthRacket - sizeBall)) 
        && ball.getPosition().y <= (racket2.getPosition().y + heightRacket - sizeBall)) 
        {
            speedBall = -speedBall;
        }



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))         //Racket 1 movement
        {
            if (racket1.getPosition().x >= 0)
            {
            racket1.move(-speedRacket * deltaTime,0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))           
        {
            if (racket1.getPosition().x <= screenWidth-widthRacket)
            {
            racket1.move(+speedRacket * deltaTime,0); 
            }
        }

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))         //Racket 2 movement
        {
            if (racket2.getPosition().x >= 0)
            {
            racket2.move(-speedRacket * deltaTime,0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))           
        {
            if (racket2.getPosition().x <= screenWidth-widthRacket)
            {
            racket2.move(+speedRacket * deltaTime,0); 
            }
        }

        // Draw loop
        window.clear();
        window.draw(ball);    //Affiche la balle
        window.draw(racket1);    //Affiche la raquette 1
        window.draw(racket2);    //Affiche la raquette 2
        window.display();
    }

    return 0;
}