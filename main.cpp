#include <iostream>
#include <Windows.h>

// Function to play a piano note
void playNote(int frequency, int duration) {
    Beep(frequency, duration);
}

int main() {
    // Define piano key frequencies
    const int C4 = 261;
    const int D4 = 293;
    const int E4 = 329;
    const int F4 = 349;
    const int G4 = 392;
    const int A4 = 440;
    const int B4 = 466;
    const int C5 = 523;

    // Map keyboard keys to piano keys
    const char keyMapping[] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};

    std::cout << "Virtual Piano (Press Q to quit)\n";

    while (true) {
        // Check if a key is pressed
        if (_kbhit()) {
            char key = _getch();

            // Check if the pressed key is a piano key
            for (int i = 0; i < 9; ++i) {
                if (key == keyMapping[i]) {
                    // Play the corresponding note
                    playNote(C4 * pow(2, i), 500); // Adjust duration as needed
                }
            }

            // Check if the user wants to quit
            if (key == 'q' || key == 'Q') {
                break;
            }
        }

        // Add a delay to reduce CPU usage
        Sleep(10);
    }

    return 0;
}
