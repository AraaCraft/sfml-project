#include "Game.hpp"

Game::Game()
{
    gamePlaying = true;
}

Game::~Game()
{

}

void Game::loop()
{
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        logicLoop();
        drawLoop();
    }
}

void Game::logicLoop()
{
    
}

void Game::drawLoop()
{
    
}

void Game::gamePause()
{

}

void Game::gameStart()
{

}