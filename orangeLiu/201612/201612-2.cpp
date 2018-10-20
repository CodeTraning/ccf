#include <iostream>

using namespace std;

int money[7] = {3500, 3500 + 1500, 3500 + 4500, 3500 + 9000, 3500 + 35000,
    3500 + 55000, 3500 + 80000};

int rate[7] = {3, 10, 20, 25, 30, 35, 45};

int range[7];

int main()
{
    int s;
    cin >> s;
    range[0] = money[0];
    for (int i = 1; i < 7; i++)
    {
        range[i] = range[i - 1] + (money[i] - money[i - 1])
            * (100 - rate[i - 1]) / 100;
    }
    int i = 0;
    for (; i < 7; i++)
    {
        if (s < range[i])
        {
            break;
        }
    }
    if (i == 0)
    {
        cout << s << endl;
    }
    else
    {
        cout << money[i - 1] +
            (s - range[i - 1]) * 100 / (100 - rate[i - 1]) << endl;
    }
    return 0;
}
