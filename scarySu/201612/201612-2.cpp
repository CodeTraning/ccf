#include <iostream>

using namespace std;

int main() {
    int T, S, A, sum;
    cin >> T;
    if (T <= 3500) {
        cout << T << endl;
    } else if (T > 3500) {
        for (S = 3500; S <= 200000; S += 100) {
            sum = 0;
            A = S - 3500;
            if (A > 0 && A <= 1500)
                sum += A * 0.03;
            else if (A > 1500 && A <= 4500)
                sum += (A-1500) * 0.1 + 45;
            else if (A > 4500 && A <= 9000)
                sum += (A-4500) * 0.2 + 345;
            else if (A > 9000 && A <= 35000)
                sum += (A-9000) * 0.25 + 1245;
            else if (A > 35000 && A <= 55000)
                sum += (A-35000) * 0.3 + 7745;
            else if (A > 55000 && A <= 80000)
                sum += (A-55000) * 0.35 + 13745;
            else if (A > 80000)
                sum += (A-80000) * 0.45 + 22495;
            if (S == T + sum) {
                cout << S << endl;
                break;
            }
        }
    }
    return 0;
}
