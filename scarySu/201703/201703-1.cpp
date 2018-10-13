#include <iostream>

using namespace std;

int main() {
    int n, k, a[1005] = {0};
    int sum = 0, count = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (sum >= k) {
            sum = 0;
            count++;
        }
    }
    if (sum < k && sum != 0)
        count++;
    cout << count << endl;
    return 0;
}
