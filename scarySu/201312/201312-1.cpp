#include <iostream>

using namespace std;

int main() {
    int n, p = 0;
    int num[1005], count[1005] = {0}, N[1005] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = i; j < n; j++) {
            if (num[i] > num[j]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    count[p] = 1;
    N[p] = num[0];
    for (int i = 1; i < n; i++) {
        if (num[i - 1] != num[i]) {
            count[++p]++;
            N[p] = num[i];
        } else {
            count[p]++;
        }
    }
    int maxn = count[0], maxa = N[0];
    for (int i = 1; i <= p; i++) {
        if (maxn < count[i]) {
            maxn = count[i];
            maxa = N[i];
        } else if (maxn == count[i] && maxa > N[i]) {
            maxa = N[i];
        }
    }
    cout << maxa << endl;
    return 0;
}

