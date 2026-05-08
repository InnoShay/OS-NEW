#include <iostream>
using namespace std;

int mtx = 1;   // renamed
int wrt = 1;
int readCount = 0;

void wait(int &s) {
    while (s <= 0);
    s--;
}

void signal(int &s) {
    s++;
}

void reader(int id) {
    wait(mtx);
    readCount++;

    if (readCount == 1) {
        wait(wrt);
    }

    signal(mtx);

    cout << "Reader " << id << " is reading\n";

    wait(mtx);
    readCount--;

    if (readCount == 0) {
        signal(wrt);
    }

    signal(mtx);
}

void writer(int id) {
    wait(wrt);

    cout << "Writer " << id << " is writing\n";

    signal(wrt);
}

int main() {
    int n;
    cout << "Enter number of readers: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        reader(i);
    }

    int m;
    cout << "Enter number of writers: ";
    cin >> m;

    for (int i = 1; i <= m; i++) {
        writer(i);
    }

    return 0;
}