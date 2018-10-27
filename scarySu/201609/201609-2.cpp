#include <iostream>

using namespace std;

int main() {
    int n, p, seat[105] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        bool flag = true, first = true;
        int count;
        for (int j = 0; j < 20 && flag; j++) {
            count = 0;
            for (int k = j*5+1; k <= j*5+5; k++) {
                if (seat[k] == 0)
                    count++;
            }
            if (p <= count && flag) {
                flag = false;
                for (int k = j*5+1; k <= j*5+5; k++) {
                    if (seat[k] == 0 && p > 0) {
                        seat[k] = 1;
                        p--;
                        if (first) {
                            first = false;
                            cout << k;
                        } else {
                            cout << " " << k;
                        }
                    }
                }
            }
        }
        if (flag) {
            for (int k = 1; k <= 100 && p > 0; k++) {
                if (seat[k] == 0) {
                    seat[k] = 1;
                    p--;
                    if (first) {
                        first = false;
                        cout << k;
                    } else {
                        cout << " " << k;
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
