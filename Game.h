#pragma once
const int windowSize = 800;
#include "Board.h"
#include "Action.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
class Game
{
private:
    // Create a font for text
    sf::Font font;

public:
    void showMenu();
    int Game_2v2();
    Game();
};

inline int Game::Game_2v2() {
    Board chessboard;
    Action userAction;


    // ... (Previous code for loading textures)
    sf::Font font;
    if (!font.loadFromFile("Roboto-Black.ttf")) {
        // Handle font loading error.
        std::cout << "skdfngsk";
    }
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Static Chessboard");



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Handle mouse click events
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;

                // Determine the row and column based on mouse coordinates
                int row = mouseY / (windowSize / 8);
                int col = mouseX / (windowSize / 8);

                // If the user clicks on an empty square and has already selected a piece, set the destination square.
                if (userAction.Get_src() != ' ')
                {
                    userAction.setDestinationSquare(row, col, chessboard);
                    userAction.execute(chessboard);  // Execute the move
                    userAction = Action(); // Reset the user action for the next turn.
                }
                else
                {
                    chessboard.empty_moves();
                    char selectedPiece = chessboard.Get_board()[row][col];
                    userAction.setPieceToMove(selectedPiece, row, col, chessboard);
                    std::cout << "src set";
                }
            }
        }

        window.clear();
        chessboard.draw(window, font);
        window.display();
    }
    return 1;
}
inline Game::Game()
{
    if (!this->font.loadFromFile("Roboto-Black.ttf")) {
        // Handle font loading error.
        std::cout << "skdfngsk";
    }
}
inline void Game::showMenu() {
        sf::RenderWindow menuWindow(sf::VideoMode(windowSize, windowSize), "Game Menu");

        // Create and configure the "2v2" button
        sf::Text button2v2("2v2", font, 24);
        button2v2.setPosition(100, 100);
        button2v2.setFillColor(sf::Color::White);

        while (menuWindow.isOpen()) {
            sf::Event event;
            while (menuWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    menuWindow.close();
                }
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    int mouseX = event.mouseButton.x;
                    int mouseY = event.mouseButton.y;

                    // Check if the user clicked on the "2v2" button
                    if (button2v2.getGlobalBounds().contains(mouseX, mouseY)) {
                        // Open the 2v2 game mode
                        menuWindow.close();
                        Game_2v2();
                    }

                    // You can add more options/buttons here...
                }
            }

            menuWindow.clear();

            menuWindow.draw(button2v2);

            // You can add more text fields, buttons, and background shapes here...

            menuWindow.display();
        }
    }


