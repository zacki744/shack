#pragma once

class Legal {
private:
    
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
        if (row + 2 <= 7 && col + 1 <= 7) {
            if (board[row + 2][col + 1] == ' ' || (board[row + 2][col + 1] > lower && board[row + 2][col + 1] < upper)) {
                res.push_back(std::make_pair(row + 2, col + 1));
            }
        }
        if (row + 2 <= 7 && col - 1 >= 0) {
            if (board[row + 2][col - 1] == ' ' || (board[row + 2][col - 1] > lower && board[row + 2][col - 1] < upper)) {
                res.push_back(std::make_pair(row + 2, col - 1));
            }
        }
        if (row - 2 >= 0 && col - 1 >= 0) {
            if (board[row - 2][col - 1] == ' ' || (board[row - 2][col - 1] > lower && board[row - 2][col - 1] < upper)) {
                res.push_back(std::make_pair(row - 2, col - 1));
            }
        }
        if (row - 2 >= 0 && col + 1 <= 7) {
            if (board[row - 2][col + 1] == ' ' || (board[row - 2][col + 1] > lower && board[row - 2][col + 1] < upper)) {
                res.push_back(std::make_pair(row - 2, col + 1));
            }
        }
        if (row - 1 >= 0 && col + 2 <= 7) {
            if (board[row - 1][col + 2] == ' ' || (board[row - 1][col + 2] > lower && board[row - 1][col + 2] < upper)) {
                res.push_back(std::make_pair(row - 1, col + 2));
            }
        }
        if (row + 1 <= 7 && col + 2 <= 7) {
            if (board[row + 1][col + 2] == ' ' || (board[row + 1][col + 2] > lower && board[row + 1][col + 2] < upper)) {
                res.push_back(std::make_pair(row + 1, col + 2));
            }
        }
        if (row - 1 >= 0 && col - 2 >= 0) {
            if (board[row - 1][col - 2] == ' ' || (board[row - 1][col - 2] > lower && board[row - 1][col - 2] < upper)) {
                res.push_back(std::make_pair(row - 1, col - 2));
            }
        }
        if (row + 1 <= 7 && col - 2 >= 0) {
            if (board[row + 1][col - 2] == ' ' || (board[row + 1][col - 2] > lower && board[row + 1][col - 2] < upper)) {
                res.push_back(std::make_pair(row + 1, col - 2));
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

