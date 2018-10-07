#include <iostream>

using namespace std;

int main() {
    int N, sum = 0;
    cin >> N;
    sum += (N / 50) * 7;
    sum += ((N % 50) / 30) * 4;
    sum += ((N  % 50) % 30) / 10;
    printf("%d\n", sum);
    return 0;
}
