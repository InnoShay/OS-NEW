#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];  // Remaining time
    }

    int currentTime = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int minRT = 1e9;

        // Find process with smallest remaining time
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && rt[i] > 0) {
                if (rt[i] < minRT) {
                    minRT = rt[i];
                    idx = i;
                }
            }
        }

        // If no process is available
        if (idx == -1) {
            currentTime++;
        } else {
            // Execute for 1 unit time
            rt[idx]--;
            currentTime++;

            // If process completes
            if (rt[idx] == 0) {
                ct[idx] = currentTime;

                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];

                completed++;
            }
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