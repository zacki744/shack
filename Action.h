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
    void setDestinationSquare(int row, int col, Board& b);

    // Check if an action is ready to be executed.
    bool isReady() const;

    // Execute the action (move the piece to the destination square).
    void execute(Board& b);

    // return the sorse
    char Get_src();

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

inline void Action::setDestinationSquare(int row, int col, Board& b)
{
    if (this->startRow == this->destRow && this->startCol == this->destCol) {
        this->pieceToMove = ' ';
        this->startRow = -1;
        this->startCol = -1;
        this->destRow = -1;
        this->destCol = -1;
        this->ready = false;
        b.empty_moves();
        return;
    }
    std::vector<std::pair<int, int>> moves = b.Get_Leagal_moves();
    for (const auto& move : moves) {
        if (move.first == row && move.second == col) {
            this->destRow = row;
            this->destCol = col;
            this->ready = true;
            return; // Exit the loop and function when a valid move is found
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
        pieceToMove = ' ';
        startRow = -1;
        startCol = -1;
        destRow = -1;
        destCol = -1;
        ready = false;
        b.empty_moves();
    }
}

inline char Action::Get_src()
{
    return this->pieceToMove;
}

