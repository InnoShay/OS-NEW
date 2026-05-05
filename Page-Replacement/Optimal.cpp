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
    int pageFaults = 0;

    // Initialize frames
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        bool found = false;

        // Check if page is already in frame (HIT)
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }

        // If page fault
        if (!found) {
            int index = -1;
            int farthest = i;

            // Find page to replace
            for (int j = 0; j < frames; j++) {
                int k;

                // Check future use
                for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) {
                        if (k > farthest) {
                            farthest = k;
                            index = j;
                        }
                        break;
                    }
                }

                // If page not used again
                if (k == n) {
                    index = j;
                    break;
                }
            }

            // If all frames are empty initially
            if (index == -1) {
                for (int j = 0; j < frames; j++) {
                    if (frame[j] == -1) {
                        index = j;
                        break;
                    }
                }
            }

            frame[index] = pages[i];
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