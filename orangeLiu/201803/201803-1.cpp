#include <iostream>

using namespace std;

int main()
{
    int flag = 0;
    int n;
    int ans = 0;
    while(1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        if (n == 1)
        {
            ans++;
            flag = 0;
        }
        if (n == 2)
        {
            flag++;
            ans += 2 * flag;
        }
    }
    cout << ans << endl;
    return 0;
}
