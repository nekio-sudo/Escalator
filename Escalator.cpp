#include <iostream>
#include <vector>
#include <windows.h> // For Sleep function
#include <conio.h> // For kbhit and getch functions

using namespace std;

// Function to print the escalator
void printEscalator(const vector<string>& escalator) {
    for (const string& step : escalator) {
        cout << step << endl;
    }
    cout << endl; // Add a newline after printing the escalator for spacing
}

int main() {
    char choice;

    while (true) {
        system("cls");
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

    // Menu
    cout << "Main Menu:\n";
    cout << "1. Start the Escalator Animation\n";
    cout << "0. Turn off the Escalator\n\n";
    cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                // Define the initial state of the escalator
                vector<string> escalator = {
                    "/____/",
                    "/    /",
                    "/    /",
                    "/    /",
                    "/    /",
                    "/____/"
                };

                // Flag to indicate whether the escalator is running
                bool isRunning = true;

                while (isRunning) {
                    // Clear the screen for a smoother animation effect (Windows)
                    system("cls");

                    // Print the escalator
                    printEscalator(escalator);

                    // Move the steps downwards
                    escalator.insert(escalator.begin(), escalator.back());
                    escalator.pop_back();

                    // Sleep for a short duration to control the speed of the animation
                    Sleep(1000); // 1000 milliseconds (1 second)

                    // Check if a key has been pressed
                    if (_kbhit()) {
                        // Get the pressed key
                        char keyPressed = _getch();
                        // Check if the pressed key is '0'
                        if (keyPressed == '0') {
                            isRunning = false; // Stop the escalator animation
                        }
                    }
                }
                break;
            }
            case '0':
                cout << "\nTurning off the escalator.\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
        }

        if (choice == '0') {
            break; // Exit the program if the user chooses to turn off the escalator
        }
    }

    cout << "Exiting the program. Goodbye!\n";

    return 0;
}
