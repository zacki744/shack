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
    void setDestinationSquare(int row, int col);

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
    std::vector<std::pair<int, int>> res;
    L.getPossibleMoves(b, col, row, res);
    if (res.size() != 0)
        b.Set_Leagal_moves(res);
    //std::cout << res[0].first << std::endl;
    pieceToMove = piece;
    startRow = row;
    startCol = col;
    return res;
}

inline void Action::setDestinationSquare(int row, int col)
{
    destRow = row;
    destCol = col;
    ready = true;
}

inline bool Action::isReady() const
{
    return ready;
}

inline void Action::execute(Board& b)
{
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

