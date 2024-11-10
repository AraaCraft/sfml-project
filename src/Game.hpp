#ifndef GAME_HPP
#define GAME_HPP

#include "Ball.hpp"
#include "Player.hpp"

class Game
{
    private:
        bool gamePlaying;
        Ball ball;
        Player players[2];

        int screenWidth=1500;       //Largeur fenêtre
        int screenHeight=1000;      //Hauteur fenêtre
        sf::RenderWindow window;
    public:
        Game();
        ~Game();
        void loop();
        void logicLoop();
        void drawLoop();
        void gameStart();
        void gamePause();
};

#endif // GAME_HPP