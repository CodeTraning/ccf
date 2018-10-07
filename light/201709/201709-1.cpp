#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    n/=10;
    cout << n/5 * (5+2) + n%5/3*(3+1) + n%5%3<<endl;
    return 0;
}
