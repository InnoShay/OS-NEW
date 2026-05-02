#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[n][m], max[n][m], need[n][m], avail[m];

    // Input Allocation Matrix
    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    // Input Max Matrix
    cout << "Enter Max Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    // Input Available Resources
    cout << "Enter Available Resources:\n";
    for (int i = 0; i < m; i++) {
        cin >> avail[i];
    }

    // Calculate Need Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    bool finish[n];

    for (int i = 0; i < n; i++) {
        finish[i] = false;
    }
    int safeSeq[n];
    int count = 0;

    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j])
                        break;
                }

                // If all needs satisfied
                if (j == m) {
                    for (int k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        // If no process found → unsafe
        if (!found) {
            cout << "\nSystem is NOT in safe state\n";
            return 0;
        }
    }

    // Safe state
    cout << "\nSystem is in SAFE state\nSafe Sequence: ";

    for (int i = 0; i < n; i++) {
        cout << "P" << safeSeq[i] << " ";
    }

    cout << endl;

    return 0;
}