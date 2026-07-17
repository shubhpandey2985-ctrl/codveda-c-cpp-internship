# 🎮 Tic-Tac-Toe Console Game

A console-based **Tic-Tac-Toe** game developed using **Modern C++17** that allows two players to compete in a classic 3×3 board game. The project demonstrates fundamental game development concepts including game loops, board management, input validation, winner detection, and modular object-oriented design.

This project was developed as part of the **Codveda Technology C++ Internship (Level 3 – Task 3)**.

---

## 📖 Overview

Tic-Tac-Toe is one of the most popular beginner-friendly games for learning programming logic. This application recreates the game in a console environment while focusing on clean code architecture, reusable components, and efficient game state management.

Players take turns placing their symbols (`X` and `O`) on the board until one player wins or the game ends in a draw.

---

## ✨ Features

- 🎮 Two-player gameplay
- 🧩 Interactive 3×3 game board
- ✔️ Input validation
- 🏆 Automatic winner detection
- 🤝 Draw detection
- 🔄 Replay game without restarting
- 📊 Scoreboard tracking
- 🧱 Modular object-oriented architecture
- ⚠️ Error handling for invalid moves

---

## 🛠️ Tech Stack

| Category | Technology |
|----------|------------|
| Language | C++17 |
| Compiler | GCC / Clang / MSVC |
| Build System | CMake |
| Programming Paradigm | Object-Oriented Programming |
| Interface | Console |

---

## 📂 Project Structure

```text
Task-3-TicTacToe/

├── README.md
├── CMakeLists.txt
│
├── include/
│   ├── Board.hpp
│   ├── Player.hpp
│   ├── Game.hpp
│   ├── Scoreboard.hpp
│   └── Utils.hpp
│
├── src/
│   ├── main.cpp
│   ├── Board.cpp
│   ├── Player.cpp
│   ├── Game.cpp
│   ├── Scoreboard.cpp
│   └── Utils.cpp
│
├── docs/
│   ├── PRD.md
│   └── Architecture.md
│
└── screenshots/
```

---

## 🚀 Getting Started

### Clone the Repository

```bash
git clone https://github.com/<your-username>/codveda-cpp-internship.git
```

Navigate to the project directory:

```bash
cd Level-3/Task-3-TicTacToe
```

---

## ⚙️ Build

Using CMake:

```bash
mkdir build
cd build

cmake ..

cmake --build .
```

Or compile directly using g++:

```bash
g++ src/*.cpp -Iinclude -std=c++17 -o TicTacToe
```

Run the application:

```bash
./TicTacToe
```

---

## 📋 Main Menu

```text
============================
      Tic-Tac-Toe
============================

1. New Game
2. View Scoreboard
3. Reset Scoreboard
4. Exit
```

---

## 🎮 Gameplay

### Board Layout

```text
     1   2   3

1    X | O | X
    ---+---+---

2      | X |
    ---+---+---

3    O |   | O
```

### Player Turn

```text
Player X (Alice)

Enter Row:
2

Enter Column:
3
```

### Winner

```text
Congratulations!

Alice wins!
```

### Draw

```text
Game Over!

It's a Draw!
```

---

## 📊 Scoreboard

```text
========================

Scoreboard

========================

Games Played : 10

Player X Wins : 5

Player O Wins : 3

Draws : 2
```

---

## 📸 Screenshots

Add screenshots after implementation.

```text
screenshots/

├── menu.png
├── gameplay.png
├── winner.png
├── draw.png
└── scoreboard.png
```

---

## 🏗️ Architecture

```text
                User
                  │
                  ▼
             Main Menu
                  │
                  ▼
            Game Manager
                  │
        ┌─────────┴─────────┐
        ▼                   ▼
     Player X           Player O
        │                   │
        └─────────┬─────────┘
                  ▼
             Game Board
                  │
                  ▼
        Winner Detection Engine
                  │
                  ▼
             Scoreboard
```

---

## 📚 Concepts Demonstrated

- Object-Oriented Programming
- Arrays (2D Arrays)
- Functions
- Loops
- Conditional Statements
- Input Validation
- Game State Management
- Modular Programming
- Error Handling

---

## 🎯 Learning Outcomes

This project demonstrates practical knowledge of:

- Designing interactive console applications
- Managing game state and player turns
- Detecting winning conditions
- Implementing reusable classes
- Writing modular and maintainable C++ code
- Applying object-oriented programming principles

---

## 🚧 Future Improvements

- 🤖 Single-player mode with AI (Minimax Algorithm)
- 🎨 Colored console interface
- 💾 Save and load game progress
- ↩️ Undo/Redo moves
- 🌐 Online multiplayer
- 🖥️ GUI version using Qt or SFML
- 🎵 Sound effects
- 🏆 Tournament mode
- 📈 Player statistics and rankings

---

## 📄 Documentation

- Product Requirements Document (PRD)
- System Architecture
- Source Code Documentation
- Gameplay Screenshots
- Sample Outputs

---

## 👨‍💻 Author

**Your Name**

Codveda Technology C++ Internship

GitHub: https://github.com/<your-username>

LinkedIn: https://linkedin.com/in/<your-profile>

---

## 📜 License

This project is developed for educational purposes as part of the **Codveda Technology C++ Internship**.
