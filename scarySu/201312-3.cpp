#include <iostream>

using namespace std;

int main() {
    int n, p = 0, q = 0;
    int num1[1005] = {0}, num2[1005] = {0}, num3[1005] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num1[i];
        if (i == 0) {
            num2[p] = num1[i];
        } else {
            if (num1[i-1] < num1[i]) {
                num2[++p] = num1[i - 1] * 2;
            } else {
                num2[++p] = num1[i] * 2;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int l = i-1; l >= 0; l--) {
            if (num1[i] <= num1[l])
                num3[q] += num1[i];
            else
                break;
        }
        for (int f = i; f >= 0; f++) {
            if (num1[i] <= num1[f])
                num3[q] += num1[i];
            else
                break;
        }
        q++;
    }
    int maxn = 0;
    for (int i = 0; i <= p; i++) {
        if (maxn < num2[i])
            maxn = num2[i];
    }
    for (int i = 0; i <= q; i++) {
        if (maxn < num3[i])
            maxn = num3[i];
    }
    cout << maxn << endl;
    return 0;
}

