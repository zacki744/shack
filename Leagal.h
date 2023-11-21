#pragma once
#include "Game.h";
class Legal {
private:
    static void Pawn_moves(std::vector<std::pair<int, int>>& res, Board& b, int col, int row) {
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

        // Define the direction of pawn movement based on color
        int direction = (board[row][col] >= 'a' && board[row][col] <= 'z') ? -1 : 1;

        // Normal pawn move (one square forward)
        if (b.Get_board()[row + direction][col] == ' ') {
            res.push_back(std::make_pair(row + direction, col));

            // En passant (two squares forward from the starting position)
            if ((row == 1 && direction == 1) || (row == 6 && direction == -1)) {
                if (b.Get_board()[row + 2 * direction][col] == ' ') {
                    res.push_back(std::make_pair(row + 2 * direction, col));
                }
            }
        }
        // Check left diagonal
        if (col > 0 && b.Get_board()[row + direction][col - 1] >= lower && b.Get_board()[row + direction][col - 1] <= upper) {
            res.push_back(std::make_pair(row + direction, col - 1));
        }

        // Check right diagonal
        if (col < 7 && b.Get_board()[row + direction][col + 1] >= lower && b.Get_board()[row + direction][col + 1] <= upper) {
            res.push_back(std::make_pair(row + direction, col + 1));
        }
        //// En passant capture (opponent's pawn is next to the moving pawn)
        //if (col + 1 <= 7 && (board[row][col + 1] > lower && board[row][col + 1] < upper)) {
        //    // Check if there's an opponent's pawn next to the moving pawn
        //    if (board[row][col + 1] == 'P' || board[row][col + 1] == 'p') {
        //        // Check if the opponent's pawn moved two squares forward
        //        if ((row == 3 && direction == -1) || (row == 4 && direction == 1)) {
        //            res.push_back(std::make_pair(row + direction, col + 1));
        //        }
        //    }
        //}

        //if (col - 1 >= 0 && (board[row][col - 1] > lower && board[row][col - 1] < upper)) {
        //    // Check if there's an opponent's pawn next to the moving pawn
        //    if (board[row][col - 1] == 'P' || board[row][col - 1] == 'p') {
        //        // Check if the opponent's pawn moved two squares forward
        //        if ((row == 3 && direction == -1) || (row == 4 && direction == 1)) {
        //            res.push_back(std::make_pair(row + direction, col - 1));
        //        }
        //    }
        //}
    }


    static void King_moves(std::vector<std::pair<int, int>>& res, Board& b, int col, int row) {
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
        // Define possible king moves (relative to the current position)
        int moves[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };

        for (int i = 0; i < 8; i++) {
            int newRow = row + moves[i][0];
            int newCol = col + moves[i][1];

            if (newRow >= 0 && newRow <= 7 && newCol >= 0 && newCol <= 7) {
                if (board[newRow][newCol] == ' ' || (board[newRow][newCol] > lower && board[newRow][newCol] < upper)) {
                    res.push_back(std::make_pair(newRow, newCol));
                }
            }
        }
    }
    static void Knight_moves(std::vector<std::pair<int, int>>& res, Board& b, int col, int row) {
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

        // Define possible knight moves (relative to the current position)
        int moves[8][2] = {
            {-2, -1}, {-2, 1},
            {-1, -2}, {-1, 2},
            {1, -2}, {1, 2},
            {2, -1}, {2, 1}
        };

        for (int i = 0; i < 8; i++) {
            int newRow = row + moves[i][0];
            int newCol = col + moves[i][1];

            if (newRow >= 0 && newRow <= 7 && newCol >= 0 && newCol <= 7) {
                if (board[newRow][newCol] == ' ' || (board[newRow][newCol] > lower && board[newRow][newCol] < upper)) {
                    res.push_back(std::make_pair(newRow, newCol));
                }
            }
        }
    }
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
        int c_row = row;
        // right down diagonal
        for (int i = col + 1; i < 8; i++) {
            if (c_row >= 1)
                c_row--;
            else
                break;
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
        }

        // Check to the left up diagonal
        c_row = row;
        for (int i = col - 1; i >= 0; i--) {
            if (c_row >= 1)
                c_row--;
            else
                break;
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
        }
        // Check to the left up diagonal
        c_row = row;
        for (int i = col - 1; i >= 0; i--) {
            if (c_row < 7)
                c_row++;
            else
                break;
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
        }
        c_row = row;
        // right down diagonal
        for (int i = col + 1; i < 8; i++) {
            if (c_row < 7)
                c_row++;
            else
                break;
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
        }
    }

public:
    static void getPossibleMoves(Board& b, int col, int row, std::vector<std::pair<int, int>> &res) {

        std::vector<std::vector<char>> board = b.Get_board();
        char piece = board[row][col];
        // Implement your logic to find all possible moves for the selected piece
        // You need to consider the rules for each chess piece here


        std::cout << piece;
        std::cout << row << " " << col << std::endl;

        switch (piece) {
        case 'P':
            Pawn_moves(res, b, col, row);
            break;
        case 'p':
            Pawn_moves(res, b, col, row);
            break;
        case 'R':
            Rook_moves(res, b, col, row);
            break;
        case 'r':
            Rook_moves(res, b, col, row);
            break;
        case 'B':
            Bishop_moves(res, b, col, row);
            break;
        case 'b':
            Bishop_moves(res, b, col, row);
            break;
        case 'N':
            Knight_moves(res, b, col, row);
            break;
        case 'n':
            Knight_moves(res, b, col, row);
            break;
        case 'Q':
            Bishop_moves(res, b, col, row);
            Rook_moves(res, b, col, row);
            break;
        case 'q':
            Bishop_moves(res, b, col, row);
            Rook_moves(res, b, col, row);
            break;
        case 'k':
            King_moves(res, b, col, row);
            break;
        case 'K':
            King_moves(res, b, col, row);
            break;

        }
    }
};

