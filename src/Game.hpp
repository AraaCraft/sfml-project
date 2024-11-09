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
    public:
        Game();
        ~Game();
        void gameStart();
        void gamePause();
};

#endif // GAME_HPP