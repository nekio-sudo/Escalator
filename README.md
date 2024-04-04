# Escalator Simulation

## Description
This program simulates an animated escalator with various interactive options. Users can start, stop, and adjust the animation speed of the escalator. The program uses ANSI color codes for visual effects and provides a menu-based interface for user interaction.

## Features
- Start and stop the escalator animation.
- Increase or decrease the animation speed.
- Turn on or off the escalator.
- Interactive menu for user convenience.
- Visual representation of the escalator using ASCII art.
- Randomized colors for variety and aesthetic appeal.

## Requirements
- C++ compiler (e.g., g++)
- Windows OS (for `cls` command) or Unix/Linux OS (for `clear` command)
- ANSI color code support in the terminal/console

## Usage
1. Compile the program using a C++ compiler.
    - For Windows: `g++ Escalator.cpp -o Escalator.exe`
    - For Unix/Linux: `g++ Escalator.cpp -o Escalator`
2. Run the compiled executable file.
    - For Windows: `Escalator.exe`
    - For Unix/Linux: `./Escalator`

## Controls
- Use numeric keys to navigate through the menu options:
    - `1`: Start Escalator Animation
    - `2`: Increase Animation Speed
    - `3`: Decrease Animation Speed
    - `4`: Turn On Escalator
    - `5`: Turn Off Escalator
    - `0`: Exit the program
- During animation, press `0` to stop, `2` to increase speed, and `3` to decrease speed.

## Credits
- The ASCII art of the escalator is credited to its original creator.
- Raven is credited for the concept and design of the escalator simulation.

## Notes
- The program uses ANSI color codes for colored output. Make sure your terminal/console supports ANSI colors for optimal visual experience.
- The program may require adjustments for compatibility with different operating systems or terminal emulators.
