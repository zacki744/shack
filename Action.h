#pragma once
#include "Board.h"
#include "Leagal.h"
class Action
{
public:
    Action();

    // Set the piece to be moved.
    std::vector<std::pair<int, int>> setPieceToMove(int piece, int row, int col, Board& b);

    // Set the destination square for the piece.
    bool setDestinationSquare(int row, int col, Board& b);

    // Check if an action is ready to be executed.
    bool isReady() const;

    // Execute the action (move the piece to the destination square).
    void execute(Board& b);

    // return the sorse
    char Get_src();

    //reset the private vars
    void reset();

    //check if king is in check
    bool isKingInCheck(int& kingRow, int& kingCol, char kingColor, Board& b) const;
    bool NextMoveInCheck(int& kingRow, int& kingCol, char kingColor, Board& b, int row, int col) const;


private:
    char pieceToMove;
    int startRow;
    int startCol;
    int destRow;
    int destCol;
    bool ready;
    Legal L;
};

inline Action::Action()
    : pieceToMove(' '), startRow(-1), startCol(-1), destRow(-1), destCol(-1), ready(false)
{
}
void Action::reset()
{
    this->pieceToMove = ' ';
    this->startRow = -1;
    this->startCol = -1;
    this->destRow = -1;
    this->destCol = -1;
    this->ready = false;
}

inline std::vector<std::pair<int, int>> Action::setPieceToMove(int piece, int row, int col, Board& b)
{
    b.empty_moves();
    std::vector<std::pair<int, int>> res;
    L.getPossibleMoves(b, col, row, res);
    if (res.size() != 0)
        b.Set_Leagal_moves(res);
    this->pieceToMove = piece;
    this->startRow = row;
    this->startCol = col;
    return res;
}

inline bool Action::setDestinationSquare(int row, int col, Board& b)
{
    if (this->startRow == this->destRow && this->startCol == this->destCol) {
        reset();
        b.empty_moves();
        return false;
    }
    std::vector<std::pair<int, int>> moves = b.Get_Leagal_moves();
    for (const auto& move : moves) {
        if (move.first == row && move.second == col) {
            this->destRow = row;
            this->destCol = col;
            this->ready = true;
            return true; // Exit the loop and function when a valid move is found
        }
    }
}

inline bool Action::isReady() const
{
    return ready;
}

inline void Action::execute(Board& b)
{
    if (this->startRow == this->destRow && this->startCol == this->destCol) {
        b.empty_moves();
        return;
    }
    if (ready)
    {
        b.move_pice(startRow, startCol, destRow, destCol);
        b.empty_moves();
    }
}

inline char Action::Get_src()
{
    return this->pieceToMove;
}

bool Action::isKingInCheck(int& kingRow, int& kingCol, char kingColor, Board& b) const
{
    std::vector<std::pair<int, int>> opponentMoves;

    // Find all opponent pieces on the board
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if ((kingColor == 'K' && islower(b.Get_board()[row][col])) ||
                (kingColor == 'k' && isupper(b.Get_board()[row][col]))) {
                // Get possible moves for opponent's piece
                std::vector<std::pair<int, int>> moves;
                this->L.getPossibleMoves(b, col, row, moves);
                opponentMoves.insert(opponentMoves.end(), moves.begin(), moves.end());
            }
        }
    }

    // Check if any opponent's move is targeting the king's position
    for (const auto& move : opponentMoves) {
        if (move.first == kingRow && move.second == kingCol) {
            return true;  // King is in check
        }
    }

    return false;  // King is not in check
}

inline bool Action::NextMoveInCheck(int& kingRow, int& kingCol, char kingColor, Board& b, int row, int col) const
{
    Board NewBoard = b;
    NewBoard.move_pice(startRow, startCol, row, col);
    std::vector<std::pair<int, int>> opponentMoves;

    // Find all opponent pieces on the board
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if ((kingColor == 'K' && islower(NewBoard.Get_board()[row][col])) ||
                (kingColor == 'k' && isupper(NewBoard.Get_board()[row][col]))) {
                // Get possible moves for opponent's piece
                std::vector<std::pair<int, int>> moves;
                this->L.getPossibleMoves(NewBoard, col, row, moves);
                opponentMoves.insert(opponentMoves.end(), moves.begin(), moves.end());
            }
        }
    }

    // Check if any opponent's move is targeting the king's position
    for (const auto& move : opponentMoves) {
        if (move.first == kingRow && move.second == kingCol) {
            return true;  // King is in check
        }
    }
    return false;
}

