#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct op
{
    // type, 0: get, 1: put back
    int type;
    int time;
    int keyNo;
    
    op():type(0), time(0), keyNo(0) {}
    op(int type_, int time_, int keyNo_)
        :type(type_), time(time_), keyNo(keyNo_){}

};

bool cmp(const op& a, const op& b)
{
    if (a.time == b.time)
    {
        if (a.type == b.type)
            return a.keyNo < b.keyNo;
        else
            return a.type == 1;
    }
    return a.time < b.time;
}

op ops[2010];
int mark[1010];

int main()
{
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
        mark[i] = i;
    
    int w, s, c;
    int allops = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> w >> s >> c;
        ops[allops++] = op(0, s, w);
        ops[allops++] = op(1, s+c, w);
    }
    sort(ops, ops+allops, cmp);
    for (int i = 0; i < allops; i++)
    {
        if (ops[i].type == 0)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mark[j] == ops[i].keyNo)
                {
                    mark[j] = -1;
                    break;
                }
            }
        }
        else {
            for (int j = 1; j <=n; j++)
            {
                if (mark[j] == -1)
                {
                    mark[j] = ops[i].keyNo;
                    break;
                }
            }
        }
    }
    
    for (int i = 1; i < n; i++)
    {
        cout << mark[i] << " ";
    }
    cout << mark[n] << endl;
    
    return 0;
}
