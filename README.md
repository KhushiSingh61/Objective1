# Objective1
README – Simple Lane Avoidance Game (C Project)


Overview
This project is a simple console-based lane avoidance game written in C.
The player moves left or right to avoid falling obstacles. You have 3 lives and earn score by avoiding
obstacles.


Gameplay
- 3-lane game area.
- Arrow keys to move.
- Avoid obstacles falling from the top.
- Collision reduces 1 life.
- Game over after 3 lives.


Features
1. Score System
2. Lives System
3. Start Menu (Start, Instructions, Exit)
4. Background & Collision Sounds (bg.wav, impact.wav)
5. Smooth Screen Rendering (no flicker)

   
Files Required
- bg.wav
- impact.wav
Compilation Instructions (Windows)
Using GCC (MinGW):
gcc game.c -o game.exe -lwinmm
Using MSVC:
cl game.c /link Winmm.lib


How to Run
./game.exe
Use arrow keys to move.
Press Q to quit.
Code Structure
- clear_screen_fast(): refreshes screen
- read_key(): handles input
- draw_border_and_hud(): shows HUD
- play_game(): main game
- show_instructions(): instructions
- - main(): menu system
 
    
About
Demonstrates basic C game logic, sound, input handling, and console animation.
- main(): menu system
About
Demonstrates basic C game logic, sound, input handling, and console
