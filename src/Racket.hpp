#ifndef RACKET_HPP
#define RACKET_HPP

#include <SFML/Graphics.hpp>

class Racket
{
    private:
        sf::RectangleShape racketShape;
        sf::Vector2u sizeRacket;
        sf::Color colorRacket;
        sf::Vector2f positionRacket;
        int speedRacket;
        bool racketCanMove;
    public:
        Racket();
        ~Racket();
        void racketMove();
        sf::Vector2f getPosition();
};

#endif // RACKET_HPP