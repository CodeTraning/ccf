// http://118.190.20.162/view.page?gpid=T10
#include <iostream>

using namespace std;

int main()
{
    int n;
    int a[510];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == -a[j])
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

