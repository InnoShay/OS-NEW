#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], ct[n], tat[n], wt[n];

    // Input Arrival Time and Burst Time
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> at[i] >> bt[i];
    }

    // First process completion time
    ct[0] = at[0] + bt[0];

    // Calculate Completion Time for remaining processes
    for (int i = 1; i < n; i++) {
        // If CPU is idle
        if (ct[i - 1] < at[i]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    // Calculate TAT and WT
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];   // Turnaround Time
        wt[i] = tat[i] - bt[i];   // Waiting Time
    }

    // Display output
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