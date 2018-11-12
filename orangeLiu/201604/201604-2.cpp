#include <iostream>

using namespace std;

int vvi[19][10];
int sup[4][4];

int main()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int num;
            cin >> num;
            vvi[i][j] = num;
        }
    }
    for (int i = 15; i < 19; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            vvi[i][j] = 1;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int num;
            cin >> num;
            sup[i][j] = num;
        }
    }
    int n;
    cin >> n;
    int i = 0;
    bool flag = true;
    for (; i < 15 && flag ; i++)
    {
        for (int j = 0; j < 4 && flag; j++)
        {
            for (int k = 0; k < 4 && flag; k++)
            {
                if (sup[j][k] == 1 && vvi[i + j][k + n - 1] == 1)
                {
                    flag = false;
                }
            }
        }
    }
    if (!flag)
    {
        i -= 2;
    }
    else
    {
        i--;
    }
    for (int j = 0; j < 4; j++)
    {
        for (int k = 0; k < 4; k++)
        {
            if (sup[j][k] == 1)
            {
                vvi[i + j][k + n - 1] = 1;
            }
        }
    }
    for (int j = 0; j < 15; j++)
    {
        for (int k = 0; k < 10; k++)
        {
            if (k == 9)
            {
                cout << vvi[j][k];
            }
            else
            {
                cout << vvi[j][k] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
