#include <iostream>

using namespace std;

int main() {
    int num, sum = 0, count = 0;
    while (cin >> num && num != 0) {
        if (num == 1) {
            sum += 1;
            count = 0;
        } else if (num == 2) {
            count += 2;
            sum += count;
        }
    }
    cout << sum << endl;
    return 0;
}
