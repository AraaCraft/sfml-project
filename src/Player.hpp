#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Racket.hpp"

class Player
{
    private:
        short unsigned int numeroPlayer;
        int scorePlayer;
        Racket racketPlayer;
    public:
        Player();
        ~Player();
};

#endif // PLAYER_HPP