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
    sort(vi.begin(), vi.end());
    int ans = vi[1] - vi[0];
    for (int i = 2; i < vi.size(); i++)
    {
        if (vi[i] - vi[i - 1] < ans)
        {
            ans = vi[i] - vi[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}
