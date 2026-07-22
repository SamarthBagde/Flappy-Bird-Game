# Flappy Bird Game — OpenGL & C++ 🎮



A 2D arcade Flappy Bird game clone implemented in **C++** using **OpenGL** and **GLUT (OpenGL Utility Toolkit)**. Features custom 2D vector graphics rendering, bird physics, collision detection, score tracking, animated wing flapping, and multiple difficulty levels.

---

## ✨ Features

- 🎮 **Realistic Game Physics**: Implements gravity, jump impulses, and smooth bird rotation during flight.
- 🧱 **Dynamic Pipe Spawner**: Infinite procedural pipe obstacle generation with custom gap heights and movement algorithms.
- 🐤 **Multiple Skins & Difficulty Levels**: 3 selectable difficulty modes featuring unique bird rendering graphics (`drawBird1`, `drawBird2`, `drawBird3`).
- 💥 **Collision Detection**: Precise collision checking against top/bottom boundaries and moving pipe obstacles.
- 🎯 **Score System & HUD**: Real-time score counter rendered dynamically on screen.
- 🖥️ **Interactive Menus**: Includes an intro screen, difficulty selection menu, and game-over restart screen.

---

## 🚀 How to Run & Build

### Option 1: Using Visual Studio (Recommended)

1. Clone the repository:
   ```bash
   git clone https://github.com/SamarthBagde/Flappy-Bird-Game.git
   cd Flappy-Bird-Game
   ```
2. Open `CGAVR_CP.sln` in **Visual Studio**.
3. Ensure **FreeGLUT** / **GLUT** header and library paths are linked:
   - Header: `<GL/glut.h>`
   - Linker: `freeglut.lib` or `glut32.lib`
4. Build and run the project (`Ctrl + F5`).
