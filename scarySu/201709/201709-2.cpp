#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int a[1005], b[1005], c[1005], d[1005], key[1005] = {0};
    for (int i = 0; i < N; i++)
        key[i] = i + 1;
    for (int i = 0; i < K; i++) {
        cin >> a[i] >> b[i] >> c[i];
        c[i] += b[i]; d[i] = a[i];
    }
    int n1, n2;
    for (int i = 0; i < K; i++) {
        for (int j = i + 1; j < K; j++) {
            n1 = b[i]; n2 = a[i];
            if (b[i] > b[j]) {
                n1 = b[i]; n2 = a[i];
                b[i] = b[j]; b[j] = n1;
                a[i] = a[j]; a[j] = n2;
            } else if (b[i] == b[j]) {
                if (a[i] > a[j]) {
                    a[i] = a[j]; a[j] = n2;
                }
            }
        }
    }
    for (int i = 0; i < K; i++) {
        for (int j = i + 1; j < K; j++) {
            n1 = c[i]; n2 = d[i];
            if (c[i] > c[j]) {
                c[i] = c[j]; c[j] = n1;
                d[i] = d[j]; d[j] = n2;
            } else if (c[i] == c[j]) {
                if (d[i] > d[j]) {
                    d[i] = d[j]; d[j] = n2;
                }
            }
        }
    }
    int minc = c[0], q = 0;
    for (int i = 0; i < K; i++) {
        if (minc <= b[i]) {
            for (int j = q; j < K; j++) {
                minc = c[j];
                q = j;
                if (minc > b[i]) break;
                for (int k = 0; k < N; k++) {
                    if (key[k] == 0) {
                        key[k] = d[j]; break;
                    }
                }
            }
        }
        if (minc > b[i]) {
            for (int k = 0; k < N; k++) {
                if (key[k] == a[i]) {
                    key[k] = 0; break;
                }
            }
        }
    }
    for (int j = q; j < K; j++) {
        for (int k = 0; k < N; k++) {
            if (key[k] == 0) {
                key[k] = d[j]; break;
            }
        }
    }
    cout << key[0];
    for (int i = 1; i < N; i++) {
        cout << " " << key[i];
    }
    putchar('\n');
    return 0;
}

