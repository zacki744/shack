#pragma once
#include <vector>

class Legal {
private:
    static void Rook_moves(std::vector<std::pair<int, int>>& res, Board& b, int col, int row) {
        // Rook can move horizontally (left and right) and vertically (up and down)
        std::vector<std::vector<char>> board = b.Get_board();
        // Check to the right
        for (int i = col + 1; i < 8; i++) {
            if (board[row][i] == ' ') {
                res.push_back(std::make_pair(row, i));
            }
            else {
                break; // Stop if there's a piece in the way
            }
        }

        // Check to the left
        for (int i = col - 1; i >= 0; i--) {
            if (board[row][i] == ' ') {
                res.push_back(std::make_pair(row, i));
            }
            else {
                break; // Stop if there's a piece in the way
            }
        }

        // Check upwards
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == ' ') {
                res.push_back(std::make_pair(i, col));
            }
            else {
                break; // Stop if there's a piece in the way
            }
        }

        // Check downwards
        for (int i = row + 1; i < 8; i++) {
            if (board[i][col] == ' ') {
                res.push_back(std::make_pair(i, col));
            }
            else {
                break; // Stop if there's a piece in the way
            }
        }
    }

public:
    static bool isMoveLegal(std::vector<std::vector<char>>& board, int fromX, int fromY, int toX, int toY) {
        // Check if the move is within the bounds of the board
        if (fromX < 0 || fromX >= 8 || fromY < 0 || fromY >= 8 || toX < 0 || toX >= 8 || toY < 0 || toY >= 8) {
            return false;
        }

        char piece = board[fromY][fromX];
        char target = board[toY][toX];

        // Implement your logic for checking if the move is legal
        // You need to consider the rules for each chess piece here

        // Example for a pawn:
        // if (piece == 'P' && fromX == toX && fromY - toY == 1 && target == ' ') {
        //     return true;
        // }
        // Pawn
        if (piece == 'P') 
        {
            if (fromX == toX && fromY - toY == 1 && target == ' ') {

                 return true;
            }
        }
        if (piece == 'p') 
        {
            if (fromX == toX && fromY - toY == 1 && target == ' ') {
                return true;
            }
        }
        // Rook
        if (piece == 'R') {

        }
        if (piece == 'R')

        // horse
        // Rook
        // Queen
        // King
        // Return true if the move is legal, otherwise return false
        return false;
    }

    static void getPossibleMoves(Board& b, int col, int row, std::vector<std::pair<int, int>> &res) {

        std::vector<std::vector<char>> board = b.Get_board();
        char piece = board[row][col];
        // Implement your logic to find all possible moves for the selected piece
        // You need to consider the rules for each chess piece here


        std::cout << piece;
        std::cout << row << " " << col << std::endl;

        switch (piece) {
        case 'P':
            if (b.Get_board()[row + 1][col] == ' ') {
                res.push_back(std::make_pair(row + 1, col));
            }
            break;
        case 'p':
            if (b.Get_board()[row - 1][col] == ' ') {
                res.push_back(std::make_pair(row - 1, col));
            }
            break;
        case 'R':
            Rook_moves(res, b, col, row);
            break;
        case 'r':
            Rook_moves(res, b, col, row);

            break;
        }
        // Rook
        // horse
        // Rook
        // Queen
        // King
    }
};
