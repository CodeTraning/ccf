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
    int count = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (vi[i] > vi[i - 1] && vi[i] > vi[i + 1])
        {
            count++;
        }
        if (vi[i] < vi[i - 1] && vi[i] < vi[i + 1])
        {
            count++;
        }
    }
    cout << count << endl;;
}
