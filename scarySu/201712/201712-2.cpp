#include <iostream>

using namespace std;

int main() {
    int n, k, N[1005] = {0};
    cin >> n >> k;
    int count = 0, num = 0;
    for (int i = 1; count != n-1; i++) {
        if (i == n+1) i = 1;
        if (N[i] == -1) continue;
        else num++;
        if (num % k == 0 || num % 10 == k) {
            N[i] = -1;
            count++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (N[i] == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
