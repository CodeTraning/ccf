#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		m[num]++;
	}
	int ans = 0;
	int count = 0;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (it->second > count)
		{
			count = it->second;
			ans = it->first;
		}
		else if (it->second == count)
		{
			if (it->first < ans)
			{
				count = it->second;
				ans = it->first;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
