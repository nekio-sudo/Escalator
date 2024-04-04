#include <iostream>
#include <vector>
#include <windows.h> // For Sleep function
#include <conio.h>   // For kbhit and getch functions
#include <cstdlib>   // For rand and srand functions
#include <ctime>     // For time function
#include <limits>    // For numeric_limits
#include <string>    // For std::to_string

using namespace std;

// ANSI color codes
const int ANSI_COLOR_RESET = 0;
const int ANSI_COLOR_GREEN = 32;
const int ANSI_COLOR_RED = 31;

// Function prototypes
vector<string> generateEscalator(int numSteps);
void printEscalator(const vector<string>& escalator);
void clearScreen();
void displayMenu();

int main() {
    char choice;
    bool escalatorOn = false; // Flag to track the escalator state
    const int maxSteps = 30;  // Maximum number of steps allowed

    // Seed the random number generator
    srand(time(nullptr));

    while (true) {
        clearScreen(); // Clear the screen before displaying content

        cout << R"(
         .-"""-.
        /       \
        \       /
 .-"""-.-`.-.-.<  _
/      _,-\ ()()_/:)
\     / ,  `     `|
 '-..-| \-.,___,  /
       \ `-.__/  /
        `-.__.-'`"
    )" << endl;

        displayMenu();
        cout << "\n\033[1mEnter your choice:\033[0m ";
        cin >> choice;

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case '1': {
                if (!escalatorOn) {
                    cout << "\nPlease turn on the escalator first.\n";
                    break;
                }

                int numSteps;
                cout << "\nEnter the number of steps (1-" << maxSteps << "): ";
                cin >> numSteps;

                if (numSteps <= 0 || numSteps > maxSteps) {
                    cout << "\nInvalid number of steps. Please enter a number between 1 and " << maxSteps << ".\n";
                    break;
                }

                vector<string> escalator = generateEscalator(numSteps);

                bool isRunning = true;

                while (isRunning) {
                    clearScreen(); // Clear the screen before displaying content

                    printEscalator(escalator);

                    escalator.insert(escalator.begin(), escalator.back());
                    escalator.pop_back();

                    // Adjust the animation speed based on the user's choice
                    Sleep(1000); // Default speed: 1000 milliseconds (1 second)

                    if (_kbhit()) {
                        char keyPressed = _getch();
                        if (keyPressed == '0') {
                            isRunning = false;
                        } else if (keyPressed == '2') {
                            // Increase animation speed
                            Sleep(500); // 500 milliseconds (0.5 second)
                        } else if (keyPressed == '3') {
                            // Decrease animation speed
                            Sleep(1500); // 1500 milliseconds (1.5 seconds)
                        }
                    }
                }
                break;
            }
            case '2':
                cout << "\nIncreasing animation speed.\n";
                break;
            case '3':
                cout << "\nDecreasing animation speed.\n";
                break;
            case '4':
                escalatorOn = true;
                cout << "\nEscalator turned ON.\n";
                break;
            case '5':
                escalatorOn = false;
                cout << "\nEscalator turned OFF.\n";
                break;
            case '0':
                clearScreen();
                // Display exit message with ASCII art
                cout << R"(
 ________________________________________ 
/     .       | \  |                       \
\    /_\   .  |  \ |\      Thank you for    |
 |`\       /_\ |   \| \      using our      |
 |           ------,     escalator simulator!|
  |  _       ______/                       |
  | (_      /   \  \                       |
  |        /  ___\_ \                      |
  |        \      / /                      |
__|_________\______/_______________________|
\______________\./__\                      |
 /     .       | \  |                       |
 \    /_\   .  |  \ |\                      |
)" << "\nExiting the program. Goodbye!\n";
                system("pause"); // Pause before exiting
                return 0;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

vector<string> generateEscalator(int numSteps) {
    vector<string> escalator;
    for (int i = 0; i < numSteps; ++i) {
        string step = "/";
        for (int j = 1; j < numSteps - 1; ++j) {
            if (i == 0 || i == numSteps - 1) {
                step += "_";
            } else {
                int color = rand() % 7 + ANSI_COLOR_RED; // Random color between 31 and 37 (ANSI color codes)
                step += "\033[" + to_string(color) + "m.\033[" + to_string(ANSI_COLOR_RESET) + "m"; // Colored dot for variety
            }
        }
        step += "/";
        escalator.push_back(step);
    }
    return escalator;
}

void printEscalator(const vector<string>& escalator) {
    for (const string& step : escalator) {
        cout << step << endl; // No need to add an extra newline after printing each step
    }
    cout << endl; // Add a newline after printing the escalator for spacing
}

void clearScreen() {
    system("cls"); // For Windows
    // system("clear"); // For Unix/Linux
}

void displayMenu() {
    cout << "\n\033[1mMain Menu:\033[0m\n";
    cout << "1. Start Escalator Animation\n";
    cout << "2. Increase Animation Speed\n";
    cout << "3. Decrease Animation Speed\n";
    cout << "4. Turn On Escalator\n";
    cout << "5. Turn Off Escalator\n";
    cout << "\n\033[1mCredits:\033[0m Raven for the awesome escalator simulation!\n";
}
