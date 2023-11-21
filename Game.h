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
    int currentPlayer = 1;  // 1 for white, -1 for black
    bool RedyToMove = false;


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
                if (userAction.Get_src() != ' ' && RedyToMove)
                {
                    if (RedyToMove) {
                        // Check if the king is in check before allowing the move
                        int kingRow, kingCol;
                        char kingColor;
                        if (currentPlayer == 1) {
                            chessboard.findKing('k', kingRow, kingCol);
                            kingColor = 'k';
                        }
                        else {
                            chessboard.findKing('K', kingRow, kingCol);
                            kingColor = 'K';
                        }

                        if (!userAction.isKingInCheck(kingRow, kingCol, kingColor, chessboard)) {
                            // The king is not in check, allow the move
                            userAction.setDestinationSquare(row, col, chessboard);
                            userAction.execute(chessboard);  // Execute the move
                            userAction = Action(); // Reset the user action for the next turn.
                            currentPlayer = currentPlayer * -1;
                            RedyToMove = false;
                        }
                        else {
                            //simulate the action of the move
                            if (!userAction.NextMoveInCheck(kingRow, kingCol, kingColor, chessboard, row, col))
                            {
                                userAction.setDestinationSquare(row, col, chessboard);
                                userAction.execute(chessboard);  // Execute the move
                                userAction = Action(); // Reset the user action for the next turn.
                                currentPlayer = currentPlayer * -1;
                                RedyToMove = false;
                            }
                            else 
                            {
                                // The king is in check, inform the player and ask them to make another move
                                std::cout << "Illegal move! The king is in check." << std::endl;

                            }

                        }
                    }
                    window.clear();
                    userAction.reset(); // Reset the user action for the next turn.
                    chessboard.empty_moves();
                    chessboard.draw(window, font);
                    window.display();

                }
                else if (currentPlayer == 1 && !(std::isupper(chessboard.Get_board()[row][col])))
                {
                    chessboard.empty_moves();
                    char selectedPiece = chessboard.Get_board()[row][col];
                    userAction.setPieceToMove(selectedPiece, row, col, chessboard);
                    std::cout << "src set";
                    RedyToMove = true;
                }
                else if (currentPlayer == -1 && std::isupper(chessboard.Get_board()[row][col]))
                {
                    chessboard.empty_moves();
                    char selectedPiece = chessboard.Get_board()[row][col];
                    userAction.setPieceToMove(selectedPiece, row, col, chessboard);
                    RedyToMove = true;
                    std::cout << "src set";
                }
                else 
                {
                    userAction.reset(); // Reset the user action for the next turn.
                    RedyToMove = false;
                    chessboard.empty_moves();
                    window.clear();
                    chessboard.draw(window, font);
                    window.display();
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


