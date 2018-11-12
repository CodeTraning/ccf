#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, num[1005] = {0};
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    int minnum = 10005;
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (abs(num[j] - num[i]) < minnum)
                minnum = abs(num[j] - num[i]);
        }
    }
    cout << minnum << endl;
    return 0;
}
