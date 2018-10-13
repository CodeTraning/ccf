#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int count = 0;
    int sup = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        sup += num;
        if (sup >= k)
        {
            count++;
            sup = 0;
        }
    }
    if (sup != 0)
    {
        count++;
    }
    cout << count << endl;
    return 0;
}
