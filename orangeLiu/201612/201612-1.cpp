#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vi;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vi.push_back(num);
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        int left = 0;
        int right = 0;
        for (int j = 0; j < n; j++)
        {
            if (vi[j] < vi[i])
            {
                left++;
            }
            if (vi[j] > vi[i])
            {
                right++;
            }
        }
        if (left == right)
        {
            ans = vi[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
