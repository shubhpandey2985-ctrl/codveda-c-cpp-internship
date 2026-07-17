# Tic-Tac-Toe Console Game

A two-player C++17 console game with robust input validation, win/draw detection, replay support, and a session scoreboard.

## Build and run

```powershell
cmake -S . -B build
cmake --build build --config Release
.\build\Release\tic_tac_toe.exe
```

For a single-config CMake generator, run `./build/tic_tac_toe`.

## Design

The program uses modular `Game`, `Board`, `Player`, and `Scoreboard` classes. `Game` runs the menu and turns, `Board` owns the 3×3 state and rule checks, `Player` represents a named symbol, and `Scoreboard` records results for the current session.