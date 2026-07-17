#include <array>
#include <iostream>
#include <limits>
#include <string>
#include <utility>

class Board {
public:
    Board() { reset(); }
    void reset() { for (auto& row : grid_) row.fill(' '); }
    void display() const {
        std::cout << "\n     1   2   3\n\n";
        for (int row = 0; row < 3; ++row) {
            std::cout << row + 1 << "    " << grid_[row][0] << " | " << grid_[row][1] << " | " << grid_[row][2] << "\n";
            if (row < 2) std::cout << "    ---+---+---\n";
            std::cout << '\n';
        }
    }
    bool placeMark(int row, int column, char mark) {
        if (grid_[row][column] != ' ') return false;
        grid_[row][column] = mark;
        return true;
    }
    bool hasWinner(char mark) const {
        for (int i = 0; i < 3; ++i) {
            if ((grid_[i][0] == mark && grid_[i][1] == mark && grid_[i][2] == mark) ||
                (grid_[0][i] == mark && grid_[1][i] == mark && grid_[2][i] == mark)) return true;
        }
        return (grid_[0][0] == mark && grid_[1][1] == mark && grid_[2][2] == mark) ||
               (grid_[0][2] == mark && grid_[1][1] == mark && grid_[2][0] == mark);
    }
    bool isFull() const { for (const auto& row : grid_) for (char cell : row) if (cell == ' ') return false; return true; }
private:
    std::array<std::array<char, 3>, 3> grid_{};
};

class Player {
public:
    Player() = default;
    Player(std::string name, char symbol) : name_(std::move(name)), symbol_(symbol) {}
    const std::string& name() const { return name_; }
    char symbol() const { return symbol_; }
private:
    std::string name_;
    char symbol_ = ' ';
};

class Scoreboard {
public:
    void recordWin(char symbol) { ++gamesPlayed_; symbol == 'X' ? ++xWins_ : ++oWins_; }
    void recordDraw() { ++gamesPlayed_; ++draws_; }
    void reset() { gamesPlayed_ = xWins_ = oWins_ = draws_ = 0; }
    void display(const Player& x, const Player& o) const {
        std::cout << "\n========== Scoreboard ==========\nGames Played : " << gamesPlayed_ << "\n\n"
                  << x.name() << " Wins : " << xWins_ << "\n\n" << o.name() << " Wins : " << oWins_
                  << "\n\nDraws : " << draws_ << "\n================================\n";
    }
private:
    int gamesPlayed_ = 0, xWins_ = 0, oWins_ = 0, draws_ = 0;
};

int readInt(const std::string& prompt, int low, int high) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= low && value <= high) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout << "Please enter a number from " << low << " to " << high << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string readName(const std::string& prompt) {
    std::string name;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, name);
        const auto first = name.find_first_not_of(" \t\r\n");
        if (first != std::string::npos) return name.substr(first, name.find_last_not_of(" \t\r\n") - first + 1);
        std::cout << "Name cannot be empty. Please try again.\n";
    }
}

class Game {
public:
    void run() {
        bool running = true;
        while (running) {
            menu();
            switch (readInt("Choose an option: ", 1, 4)) {
                case 1: do { playRound(); } while (readInt("\nPlay Again?\n1. Yes\n2. No\nChoose an option: ", 1, 2) == 1); break;
                case 2: if (configured_) scores_.display(x_, o_); else std::cout << "\nNo games have been played yet.\n"; break;
                case 3: scores_.reset(); std::cout << "\nScoreboard reset.\n"; break;
                case 4: running = false; break;
            }
        }
        std::cout << "\nThanks for playing!\n";
    }
private:
    Board board_;
    Scoreboard scores_;
    Player x_, o_;
    bool configured_ = false;
    void menu() const { std::cout << "\n============================\n        Tic-Tac-Toe\n============================\n\n1. New Game\n2. View Scoreboard\n3. Reset Scoreboard\n4. Exit\n\n"; }
    void playRound() {
        if (!configured_) { x_ = Player(readName("\nPlayer X: "), 'X'); o_ = Player(readName("Player O: "), 'O'); configured_ = true; }
        board_.reset();
        const Player* current = &x_;
        while (true) {
            board_.display();
            std::cout << current->name() << " (" << current->symbol() << ")\n";
            int row = readInt("Enter Row: ", 1, 3) - 1;
            int column = readInt("Enter Column: ", 1, 3) - 1;
            if (!board_.placeMark(row, column, current->symbol())) { std::cout << "That cell is already occupied. Choose another cell.\n"; continue; }
            if (board_.hasWinner(current->symbol())) { board_.display(); std::cout << "Winner!\n\n" << current->name() << " wins!\n"; scores_.recordWin(current->symbol()); return; }
            if (board_.isFull()) { board_.display(); std::cout << "Game Draw!\n"; scores_.recordDraw(); return; }
            current = current->symbol() == 'X' ? &o_ : &x_;
        }
    }
};

int main() { Game game; game.run(); }