#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int x;
    int y;
};

struct matrix
{
    int index;
    struct node left;
    struct node right;
};

bool isInMatrix(const node& no, const matrix& ma)
{
    if (no.x >= ma.left.x && no.x <= ma.right.x &&
        no.y >= ma.left.y && no.y <= ma.right.y)
    {
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    matrix mm[20];
    for (int i = 1; i <= n; i++)
    {
        cin >> mm[i].left.x >> mm[i].left.y >> mm[i].right.x >> mm[i].right.y;
        mm[i].index = i;
    }
 
    for (int i = 0; i < m; i++)
    {
        node tmpNode;;
        cin >> tmpNode.x >> tmpNode.y;
        bool in = false;
        int markLocation = 0;
        int maxIndex = -9999999;
        for (int j = n; j >= 1; j--)
        {
            if (isInMatrix(tmpNode, mm[j]))
            {
                in = true;
                if (maxIndex < mm[j].index)
                {
                    maxIndex = mm[j].index;
                    markLocation = j;
                }
            }
        }
        if (in)
        {
            for (int i = markLocation + 1; i <= n; i++)
            {
                mm[i].index --;
            }
            mm[markLocation].index = n;
            cout << markLocation << endl;
        }
        else
        {
            cout << "IGNORED" << endl;
        }
    }
    return 0;
}

