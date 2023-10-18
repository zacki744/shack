#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Board.h"
#include "Action.h"

int main() {
    Board chessboard;
    const int windowSize = 800;
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
                    userAction.setDestinationSquare(row, col);
                    userAction.execute(chessboard);  // Execute the move
                    userAction = Action(); // Reset the user action for the next turn.
                }
                else
                {
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
    return 0;
}
