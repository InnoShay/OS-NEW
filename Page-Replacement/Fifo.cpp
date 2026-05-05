#include <iostream>
using namespace std;

int main() {
    int n, frames;

    cout << "Enter number of pages: ";
    cin >> n;

    int pages[n];

    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter number of frames: ";
    cin >> frames;

    int frame[frames];
    int index = 0;   // To track FIFO position
    int pageFaults = 0;

    // Initialize frames with -1 (empty)
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        bool found = false;

        // Check if page is already in frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }

        // If not found → Page Fault
        if (!found) {
            frame[index] = pages[i];  // Replace oldest
            index = (index + 1) % frames;
            pageFaults++;
        }

        // Print current frame status
        cout << "Frames: ";
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                cout << frame[j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;

    return 0;
}