#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], pr[n], rt[n], ct[n], tat[n], wt[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter AT, BT and Priority for Process " << i + 1 << ": ";
        cin >> at[i] >> bt[i] >> pr[i];
        rt[i] = bt[i];  // Remaining Time
    }

    int currentTime = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int highestPriority = 1e9;

        // Find highest priority process
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && rt[i] > 0) {
                if (pr[i] < highestPriority) {
                    highestPriority = pr[i];
                    idx = i;
                }
            }
        }

        // If no process available → CPU idle
        if (idx == -1) {
            currentTime++;
        } else {
            // Execute for 1 unit time (PREEMPTIVE)
            rt[idx]--;
            currentTime++;

            // If process finishes
            if (rt[idx] == 0) {
                ct[idx] = currentTime;

                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];

                completed++;
            }
        }
    }

    // Output
    cout << "\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << pr[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    return 0;
}