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
    int time[frames];   // To track last used time
    int counter = 0;
    int pageFaults = 0;

    // Initialize
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        bool found = false;

        // Check if page is already present (HIT)
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                counter++;
                time[j] = counter;  // Update last used time
                found = true;
                break;
            }
        }

        // If page fault
        if (!found) {
            int lruIndex = 0;

            // Find least recently used page
            for (int j = 1; j < frames; j++) {
                if (time[j] < time[lruIndex]) {
                    lruIndex = j;
                }
            }

            frame[lruIndex] = pages[i];
            counter++;
            time[lruIndex] = counter;
            pageFaults++;
        }

        // Print frames
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