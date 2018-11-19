#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    int num = 1;
    while(q.size() != 1)
    {
        int top = q.front();
        q.pop();
        if (num % 10 == k || num % k == 0)
        {
        }
        else
        {
            q.push(top);
        }
        num++;
    }
    cout << q.front() << endl;
    return 0;
}
