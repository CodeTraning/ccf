#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char c[13] = {0};
    int sum = 0, n = 1, num = 0;
    cin >> c;
    for (int i = 0; i < strlen(c); i++) {
        if (i < 12 && c[i] != '-') {
            sum += (c[i] - '0') * n;
            n++;
        } else if (i == 12 && c[i] >= '0' && c[i] <= '9') {
            num = c[i] - '0';
        }
    }
    if (sum % 11 == 10) {
        if (c[12] != 'X') {
            c[12] = 'X';
            cout << c << endl;
        } else {
            cout << "Right" << endl;
        }
    } else {
        if (sum % 11 == num)
            cout << "Right" << endl;
        else {
            c[12] = '0' + (sum % 11);
            cout << c << endl;
        }
    }
    return 0;
}

