#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vi;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vi.push_back(num);
        if (i != 0)
        {
            if (abs(vi[i] - vi[i - 1]) > ans)
            {
                ans = abs(vi[i] - vi[i - 1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
