#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, num[1005];
    int maxnum = 0;
    cin >> n >> num[0];
    for (int i = 1; i < n; i++) {
        cin >> num[i];
        if (maxnum < abs(num[i] - num[i-1]))
            maxnum = abs(num[i] - num[i-1]);
    }
    cout << maxnum << endl;
    return 0;
}
