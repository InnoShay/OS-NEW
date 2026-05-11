#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], ct[n], tat[n], wt[n];
    bool completed[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> at[i] >> bt[i];
        completed[i] = false;  // Initially all are not completed
    }

    int currentTime = 0, completedCount = 0;

    while (completedCount < n) {
        int idx = -1;
        int minBT = 1e9;

        // Find process with minimum BT among arrived ones
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && !completed[i]) {
                if (bt[i] < minBT) {
                    minBT = bt[i];
                    idx = i;
                }
            }
        }

        // If no process is found (CPU idle)
        if (idx == -1) {
            currentTime++;
        } else {
            // Execute process
            ct[idx] = currentTime + bt[idx];
            currentTime = ct[idx];

            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            completed[idx] = true;
            completedCount++;
        }
    }

    // Output
    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    return 0;
}