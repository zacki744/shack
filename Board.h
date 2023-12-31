#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class Board
{
public:
	Board();
	~Board();
    std::vector<std::vector<char>> Get_board();
    void draw(sf::RenderWindow& window, sf::Font font);
    void move_pice(int startRow, int startCol, int destRow, int destCol);
    void Set_Leagal_moves(std::vector<std::pair<int, int>> res);
    void empty_moves();
    std::vector<std::pair<int, int>> Get_Leagal_moves();
    void findKing(char kingSymbol, int& kingRow, int& kingCol) const;
    Board& operator=(const Board& other);


private:

    // Create an 8x8 chessboard using a 2D vector
    std::vector<std::vector<char>> chessboard;
    const int windowSize = 800;
    const int tileSize = windowSize / 8;
    std::vector<std::pair<int, int>> Leagal_moves;
};

Board::Board()
{
    this->chessboard = {
    { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' },
    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
    { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' }
    };
}

Board::~Board()
{
}
// Assignment operator
Board& Board::operator=(const Board& other) {
    if (this != &other) { // Check for self-assignment
        // Assign each member variable
        this->chessboard = other.chessboard;
        this->Leagal_moves = other.Leagal_moves;
    }
    return *this;
}

inline std::vector<std::vector<char>> Board::Get_board()
{
    return this->chessboard;
}

inline void Board::draw(sf::RenderWindow& window, sf::Font font)
{
    // Draw the chessboard and piece values
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            sf::RectangleShape square(sf::Vector2f(tileSize, tileSize));
            square.setPosition(col * tileSize, row * tileSize);
            if ((row + col) % 2 == 0) {
                square.setFillColor(sf::Color(255, 206, 158));  // Light square
            }
            else {
                square.setFillColor(sf::Color(209, 139, 71));   // Dark square
            }
            window.draw(square);
        }
    }
    if (this->Leagal_moves.size() != 0) {
        sf::RectangleShape square(sf::Vector2f(tileSize, tileSize));
        for (int i = 0; i < this->Leagal_moves.size(); i++) {
            square.setPosition(this->Leagal_moves[i].second * tileSize, this->Leagal_moves[i].first * tileSize);
            if ((this->Leagal_moves[i].first + this->Leagal_moves[i].second) % 2 == 0) {
                square.setFillColor(sf::Color(55, 106, 158));  // Light square
            }
            else {
                square.setFillColor(sf::Color(9, 39, 71));   // Dark square
            }
            window.draw(square);
        }
    }
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            char piece = this->chessboard[row][col];
            if (piece != ' ')
            {
                sf::Text pieceText(piece, font, 24);
                pieceText.setPosition(col * tileSize + 10, row * tileSize + 10);
                pieceText.setFillColor(piece >= 'a' && piece <= 'z' ? sf::Color::White : sf::Color::Black);
                window.draw(pieceText);
            }
        }
    }
}

inline void Board::move_pice(int startRow, int startCol, int destRow, int destCol)
{
    std::cout << startRow << " " << startCol << std::endl;
    std::cout << destRow << " " << destCol << std::endl;


    this->chessboard[destRow][destCol] = this->chessboard[startRow][startCol];
    this->chessboard[startRow][startCol] = ' ';
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            std::cout << this->chessboard[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

inline void Board::Set_Leagal_moves(std::vector<std::pair<int, int>> res)
{
    this->Leagal_moves = res;
}

inline std::vector<std::pair<int, int>> Board::Get_Leagal_moves()
{
    return this->Leagal_moves;
}

inline void Board::empty_moves()
{
    this->Leagal_moves.clear();
}

void Board::findKing(char kingSymbol, int& kingRow, int& kingCol) const {
    kingRow = -1;
    kingCol = -1;

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (chessboard[row][col] == kingSymbol) {
                kingRow = row;
                kingCol = col;
                return;  // Exit the loop when the king is found
            }
        }
    }
}


