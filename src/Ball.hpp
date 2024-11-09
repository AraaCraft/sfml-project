#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball
{
    private:
        sf::CircleShape ballShape;
        int sizeBall;
        sf::Color colorBall;
        sf::Vector2f positionBall;
        int speedBall;
        bool ballCanMove;
    public:
        Ball();
        ~Ball();
        void ballMove();
        void reverseBallMove();
};

#endif // BALL_HPP