#include <iostream>

using namespace std;

int exchange(int num) {
    if (num == 1) return -1;
    else return 1;
}

int main() {
    int n, L, t;
    int pos[105] = {0}, speed[105] = {0};
    cin >> n >> L >> t;
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
        speed[i] = 1;
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) {
            int place = j;
            for (int k = 0; k < n; k++) {
                if (pos[k] == pos[j] && k != j) {
                    place = k;
                    break;
                }
            }
            if (place != j) {
                speed[j] = exchange(speed[j]);
                speed[place] = exchange(speed[place]);
            }
            if (pos[j] == L || pos[j] == 0)
                speed[j] = exchange(speed[j]);
            if (speed[j] == 1) pos[j]++;
            else pos[j]--;
        }
    }
    cout << pos[0];
    for (int i = 1; i < n; i++)
        cout << " " << pos[i];
    putchar('\n');
    return 0;
}

