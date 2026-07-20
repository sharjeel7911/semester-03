<div align="center">

# ♟️ Chess

A fully functional console-based Chess game built in **C++** using **Object-Oriented Programming** — Semester 03 OOP Final Project.

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![OOP](https://img.shields.io/badge/OOP-Design-purple?style=for-the-badge)
![Console](https://img.shields.io/badge/Console-App-black?style=for-the-badge)
![Semester](https://img.shields.io/badge/Semester-3-orange?style=for-the-badge)

</div>

---

## 📋 About

A complete two-player chess game running in the terminal. Built from scratch using core OOP principles — inheritance, polymorphism, abstraction and encapsulation — with a custom stack implementation for move history and undo functionality.

> 📌 This was the **Final Project** for the subject **Object-Oriented Programming** — Semester 03.

---

## ♟️ Pieces Implemented

| Piece | Symbol | Movement |
|-------|--------|----------|
| King | `wK` / `bK` | One square any direction |
| Queen | `wQ` / `bQ` | Any direction, unlimited range |
| Rook | `wR` / `bR` | Horizontal & vertical, unlimited range |
| Bishop | `wB` / `bB` | Diagonal, unlimited range |
| Knight | `wN` / `bN` | L-shaped jumps |
| Pawn | `wP` / `bP` | Forward move, diagonal capture |

---

## ⚙️ Features

**🎮 Gameplay**
- Full two-player turn-based chess in the console
- Coordinate-based input (e.g., `e2` → `e4`)
- Move cancellation with `cancel` command
- Resign anytime with `quit`

**♟️ Chess Rules Fully Implemented**
- Legal move validation for all 6 piece types
- Check & Checkmate detection
- Stalemate detection
- En Passant
- Castling (Kingside & Queenside)
- Pawn Promotion
- 50-Move Rule draw
- Threefold Repetition draw
- Insufficient Material draw
- Draw by Agreement (offer & accept)

**↩️ Undo System**
- Undo the last move after every turn
- Powered by a custom-built `MyStack<T>` template class

---

## 🏗️ Architecture

The project is built across **13 classes** following clean OOP design:
```
Piece (abstract base)
├── Pawn
├── Rook
├── Knight
├── Bishop
├── Queen
└── King

Square         — represents one cell on the board
Board          — manages the 8×8 grid and all game logic
Move           — stores move metadata (from, to, flags)
MyStack<T>     — custom generic stack for move history
GameFlow       — handles the game loop and user input
```

---

## 🕹️ How to Play
```
e2          → select the piece at e2
e4          → move it to e4
cancel      → deselect the current piece
draw        → offer a draw to opponent
quit        → resign and exit
```

After each move you'll be asked if you want to undo it. Enter `y` to undo or `n` to continue.

---

## 🚀 How to Run

### Option 1 — Any C++ Compiler
```bash
g++ *.cpp -o chess && ./chess

```

### Option 2 — Visual Studio

1. Create a new **Empty C++ Project**
2. Add all `.cpp` and `.h` files to the project
3. Set platform to **x64**
4. Press **`Ctrl+F5`** to build and run

> No external libraries required — standard C++ only.

---

## 🗂️ Project Structure
```

chess/
├── src/
│   ├── main.cpp/h         # Entry point
│   ├── gameflow.cpp/h     # Game loop & input handling
│   ├── board.cpp/h        # Board state & move logic
│   ├── move.cpp/h         # Move metadata
│   ├── square.cpp/h       # Board square
│   ├── piece.cpp/h        # Abstract base class
│   ├── pawn.cpp/h
│   ├── rook.cpp/h
│   ├── knight.cpp/h
│   ├── bishop.cpp/h
│   ├── queen.cpp/h
│   ├── king.cpp/h
│   └── mystack.h          # Custom generic stack (template)
├── LICENSE
└── README.md
```

---

## 📄 License

This project is open source and available under the [MIT License](https://github.com/Sharjeel7911/chess-game/blob/main/LICENSE).

---

<div align="center">
Made with ❤️ and C++ <br>
</div>
