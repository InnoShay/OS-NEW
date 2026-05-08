#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], pr[n], ct[n], tat[n], wt[n];
    bool completed[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter AT, BT and Priority for Process " << i + 1 << ": ";
        cin >> at[i] >> bt[i] >> pr[i];
        completed[i] = false;
    }

    int currentTime = 0, completedCount = 0;

    while (completedCount < n) {
        int idx = -1;
        int highestPriority = 1e9; 

        // Find highest priority process (smallest number)
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && !completed[i]) {
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