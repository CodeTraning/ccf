#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int n, a[1005];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    int left = 0, right = 0;
    if (n % 2 == 0 && a[n/2] != a[n/2-1]) {
        puts("-1");
    } else if (n % 2 == 0 && a[n/2] == a[n/2-1]) {
        for (int i = 0; i < n/2-1; i++) {
            if (a[i] < a[n/2])
                left++;
        }
        for (int i = n-1; i > n/2; i--) {
            if (a[i] > a[n/2])
                right++;
        }
        if (left == right)
            cout << a[n/2] << endl;
        else
            cout << "-1" << endl;
    } else if (n % 2 != 0) {
        for (int i = 0; i < n/2; i++) {
            if (a[i] < a[n/2])
                left++;
        }
        for (int i = n-1; i > n/2; i--) {
            if (a[i] > a[n/2])
                right++;
        }
        if (left == right)
            cout << a[n/2] << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}
