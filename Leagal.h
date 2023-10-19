#pragma once
#include <vector>

class Legal {
private:
    static void Rook_moves(std::vector<std::pair<int, int>>& res, Board& b, int col, int row) {
        // Rook can move horizontally (left and right) and vertically (up and down)
        std::vector<std::vector<char>> board = b.Get_board();
        int upper;
        int lower;
        // Check to the right
        if (board[row][col] > 'a' && board[row][col] < 'z') {
            upper = 'Z';
            lower = 'A';
        }
        else {
            upper = 'z';
            lower = 'a';
        }
        for (int i = col + 1; i < 8; i++) {
            if (board[row][i] == ' ') {
                res.push_back(std::make_pair(row, i));
            }
            else if (board[row][i] > lower && board[row][i] < upper) {
                res.push_back(std::make_pair(row, i));
                break;
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
            else if (board[row][i] > lower && board[row][i] < upper) {
                res.push_back(std::make_pair(row, i));
                break;
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
            else if (board[i][col] > lower && board[i][col] < upper) {
                res.push_back(std::make_pair(i, col));
                break;
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
            else if (board[i][col] > lower && board[i][col] < upper) {
                res.push_back(std::make_pair(i, col));
                break;
            }
            else {
                break; // Stop if there's a piece in the way
            }
        }
    }
    static void Bishop_moves(std::vector<std::pair<int, int>>& res, Board& b, int col, int row) {
        // Rook can move horizontally (left and right) and vertically (up and down)
        std::vector<std::vector<char>> board = b.Get_board();
        int upper;
        int lower;
        if (board[row][col] > 'a' && board[row][col] < 'z') {
            upper = 'Z';
            lower = 'A';
        }
        else {
            upper = 'z';
            lower = 'a';
        }
        int c_row = row++;
        // right down diagonal
        for (int i = col + 1; i < 8; i++) {
            if (board[c_row][i] == ' ') {
                res.push_back(std::make_pair(c_row, i));
            }
            else if (board[c_row][i] > lower && board[c_row][i] < upper) {
                res.push_back(std::make_pair(c_row, i));
                break;
            }
            else {
                break; // Stop if there's a piece in the way
            }
            c_row++;
        }

        // Check to the left up diagonal
        c_row = row--;
        for (int i = col - 1; i >= 0; i--) {
            if (board[c_row][i] == ' ') {
                res.push_back(std::make_pair(c_row, i));
            }
            else if (board[c_row][i] > lower && board[c_row][i] < upper) {
                res.push_back(std::make_pair(c_row, i));
                break;
            }
            else {
                break; // Stop if there's a piece in the way
            }
            c_row--;
        }

        // Check upwards
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == ' ') {
                res.push_back(std::make_pair(i, col));
            }
            else if (board[i][col] > lower && board[i][col] < upper) {
                res.push_back(std::make_pair(i, col));
                break;
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
            else if (board[i][col] > lower && board[i][col] < upper) {
                res.push_back(std::make_pair(i, col));
                break;
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
        // You need to consider the rules for each chess piece her
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
                if (row == 1 && b.Get_board()[row + 2][col] == ' ') {
                    res.push_back(std::make_pair(row + 2, col));
                }
            }
            if (board[row + 1][col + 1] > 'a' && board[row + 1][col + 1] < 'z') {
                res.push_back(std::make_pair(row + 1, col + 1));
            }
            if (board[row + 1][col - 1] > 'a' && board[row + 1][col - 1] < 'z') {
                res.push_back(std::make_pair(row + 1, col - 1));
            }
            break;
        case 'p':
            if (b.Get_board()[row - 1][col] == ' ') {
                res.push_back(std::make_pair(row - 1, col));
                if (row == 6 && b.Get_board()[row - 2][col] == ' ') {
                    res.push_back(std::make_pair(row - 2, col));
                }
            }
            if (board[row - 1][col + 1] > 'A' && board[row - 1][col + 1] < 'Z') {
                res.push_back(std::make_pair(row - 1, col + 1));
            }
            if (board[row - 1][col - 1] > 'A' && board[row - 1][col - 1] < 'Z') {
                res.push_back(std::make_pair(row -1, col - 1));
            }
            break;
        case 'R' || 'r':
            Rook_moves(res, b, col, row);
            break;
        case 'B':
            Bishop_moves(res, b, col, row);
            break;
        case 'b':
            Bishop_moves(res, b, col, row);
            break;
        case 'N':
            break;
        case 'n':
            break;
        case 'Q':
            break;
        case 'q':
            break;
        case 'k':
            break;
        case 'K':
            break;

        }
        // horse
        // Queen
        // King
    }
};

