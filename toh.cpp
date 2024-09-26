#include <iostream>
using namespace std;

void TOH(int n, char a, char b, char c) {
    if (n == 1) {
        cout << "Move Disk " << n << " from " << a << " to " << c << endl;
        return;
    }

    TOH(n - 1, a, c, b);
    cout << "Move Disk " << n << " from " << a << " to " << c << endl;
    TOH(n - 1, b, a, c);
}

int main() {
    int n;

    cout << "Enter no. of disks:";
    cin >> n;
    TOH(n, 'A', 'B', 'C');

    return 0;
}
