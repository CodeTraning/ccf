#include <iostream>

using namespace std;

int main() {
    int n, a[1005] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = 0;
    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (i == 1) {
            if (a[1] - a[0] > 0)
                flag = true;
            else
                flag = false;
        } else {
            if (flag == true && a[i] < a[i-1]) {
                count++;
                flag = false;
            } else if (flag == false && a[i] > a[i-1]) {
                count++;
                flag = true;
            }
        }
    }
    cout << count << endl;
    return 0;
}
