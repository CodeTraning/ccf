#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> vi;
    for (int i = 1; i <= n; i++)
    {
        vi.push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        int num,change;
        cin >> num >> change;
        vector<int>::iterator it = find(vi.begin(),vi.end(),num);
        vi.erase(it);
        vi.insert(it + change, num);
    }
    for (int i = 0; i < vi.size(); i++)
    {
        cout << vi[i] << " ";
    }
    cout << endl;
    return 0;
}
