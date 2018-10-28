#include <iostream>
#include <vector>

using namespace std;

vector<int> vi(20, 5);

void fun(int num)
{
    int i = 0;
    bool flag = false;
    for (; i < 20; i++)
    {
        if (vi[i] >= num)
        {
            flag = true;
            for (int j = 1; j <= num; j++)
            {
                cout << i * 5 + (5 - vi[i]) + 1;
                vi[i]--;
                if (j != num)
                {
                    cout << " ";
                }
            }
            cout << endl;
            break;
        }
    }
    if (!flag)
    {
        for (i = 0; i < 20 && num != 0; i++)
        {
            if (vi[i] != 0)
            {
                int k = vi[i];
                for (int j = 1; j <= k && num != 0; j++)
                {
                    cout << i * 5 + (5 - vi[i]) + 1;
                    vi[i]--;
                    num--;
                    if (num != 0)
                    {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        fun(num);
    }
    return 0;
}
