#include <iostream>

using namespace std;

int beg[105]; // begin
int dir[105]; // direction
int n, l, t;

int main()
{
    cin >> n >> l >> t;
    for (int i = 0; i < 105; i++)
    {
        dir[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> beg[i];
    }
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((beg[j] == l && dir[j] == 1) || beg[j] == 0 && dir[j] == -1)
            {
                dir[j] *= -1;
            }
            else
            {
                for (int k = 0; k < n; k++)
                {
                    if ((beg[k] == beg[j]) && k != j)
                    {
                        dir[k] *= -1;
                        dir[j] *= -1;
                    }
                }
            }
            beg[j] += dir[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            cout << beg[i] << " ";
        }
        else
        {
            cout << beg[i];
        }
    }
    cout << endl;
    return 0;
}
