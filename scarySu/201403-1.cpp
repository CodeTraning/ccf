#include <iostream>

using namespace std;

int main() {
    int N, num[500], count = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (num[i] + num[j] == 0)
                count++;
        }
    }
    cout << count << endl;
    return 0;
}
