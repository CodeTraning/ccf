#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vi(n, 0);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		vi[i] = num;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int width = vi[i];
		for (int j = i + 1; j < n; j++)
		{
			if (vi[j] < width)
			{
				width = vi[j];
			}
			if ((j - i + 1) * width > ans)
			{
				ans = (j - i + 1) * width;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
