#include <iostream>
using namespace std;

int main() {
    int nb, np;

    cout << "Enter number of memory blocks: ";
    cin >> nb;

    int block[nb];
    cout << "Enter sizes of memory blocks: ";
    for (int i = 0; i < nb; i++) {
        cin >> block[i];
    }

    cout << "Enter number of processes: ";
    cin >> np;

    int process[np];
    cout << "Enter sizes of processes: ";
    for (int i = 0; i < np; i++) {
        cin >> process[i];
    }

    int choice;

    cout << "\nChoose Algorithm:\n";
    cout << "1. First Fit\n2. Best Fit\n3. Worst Fit\n";
    cin >> choice;

    int allocation[np];

    // Initialize allocation
    for (int i = 0; i < np; i++) {
        allocation[i] = -1;
    }

    // Copy block array (so original doesn't change)
    int tempBlock[nb];
    for (int i = 0; i < nb; i++) {
        tempBlock[i] = block[i];
    }

    // ================= FIRST FIT =================
    if (choice == 1) {
        for (int i = 0; i < np; i++) {
            for (int j = 0; j < nb; j++) {
                if (tempBlock[j] >= process[i]) {
                    allocation[i] = j;
                    tempBlock[j] -= process[i];
                    break;
                }
            }
        }
        cout << "\n--- First Fit Allocation ---\n";
    }

    // ================= BEST FIT =================
    else if (choice == 2) {
        for (int i = 0; i < np; i++) {
            int bestIndex = -1;

            for (int j = 0; j < nb; j++) {
                if (tempBlock[j] >= process[i]) {
                    if (bestIndex == -1 || tempBlock[j] < tempBlock[bestIndex]) {
                        bestIndex = j;
                    }
                }
            }

            if (bestIndex != -1) {
                allocation[i] = bestIndex;
                tempBlock[bestIndex] -= process[i];
            }
        }
        cout << "\n--- Best Fit Allocation ---\n";
    }

    // ================= WORST FIT =================
    else if (choice == 3) {
        for (int i = 0; i < np; i++) {
            int worstIndex = -1;

            for (int j = 0; j < nb; j++) {
                if (tempBlock[j] >= process[i]) {
                    if (worstIndex == -1 || tempBlock[j] > tempBlock[worstIndex]) {
                        worstIndex = j;
                    }
                }
            }

            if (worstIndex != -1) {
                allocation[i] = worstIndex;
                tempBlock[worstIndex] -= process[i];
            }
        }
        cout << "\n--- Worst Fit Allocation ---\n";
    }

    else {
        cout << "Invalid Choice!";
        return 0;
    }

    // Output
    cout << "\nProcess\tSize\tBlock Allocated\n";

    for (int i = 0; i < np; i++) {
        cout << "P" << i + 1 << "\t" << process[i] << "\t";

        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";

        cout << endl;
    }
    
    return 0;
}