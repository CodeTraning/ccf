#include <iostream>

using namespace std;

int main() {
    int n, m, p, q, a[1005] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        a[i] = i+1;
    }
    for (int i = 0; i < m; i++) {
        cin >> p >> q;
        int x;
        for (x = 0; x < n; x++) {
            if (p == a[x])
                break;
        }
        if (q > 0) {
            for (int j = x; j < x+q; j++) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        } else if (q < 0) {
            for (int k = x; k > x+q; k--) {
                int temp = a[k];
                a[k] = a[k-1];
                a[k-1] = temp;
            }
        }
    }
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << " " << a[i];
    putchar('\n');
    return 0;
}

