#pragma once

#include <array>

class Board {
public:
    Board();
    void reset();
    void display() const;
    bool placeMark(int row, int column, char symbol);
    bool hasWinner(char symbol) const;
    bool isFull() const;

private:
    std::array<std::array<char, 3>, 3> grid_{};
};
