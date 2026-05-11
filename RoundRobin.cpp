#include <iostream>
using namespace std;

int main() {
    int n, tq;

    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];  // Remaining Time initially = Burst Time
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int currentTime = 0, completed = 0;

    while (completed < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            // Check if process has arrived and is not finished
            if (at[i] <= currentTime && rt[i] > 0) {
                found = true;

                // If remaining time > time quantum
                if (rt[i] > tq) {
                    currentTime += tq;
                    rt[i] -= tq;
                } else {
                    // Process finishes
                    currentTime += rt[i];
                    ct[i] = currentTime;

                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    rt[i] = 0;
                    completed++;
                }
            }
        }

        // If no process is ready → CPU idle
        if (!found) {
            currentTime++;
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