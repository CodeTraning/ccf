#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int mod = 1000000007;
	int n;
	cin >> n;
	vector<vector<long long> > vvi(n + 1, vector<long long>(6,0));
	for (long long i = 1; i < n + 1; i++)
	{
		long long j = i - 1;
		vvi[i][0] = 1;
		vvi[i][1] = (vvi[j][0] + vvi[j][1] * 2) % mod;
		vvi[i][2] = (vvi[j][0] + vvi[j][2]) % mod;
		vvi[i][3] = (vvi[j][1] + vvi[j][3] * 2) % mod;
		vvi[i][4] = (vvi[j][1] + vvi[j][2] + vvi[j][4] * 2) % mod;
		vvi[i][5] = (vvi[j][3] + vvi[j][4] + vvi[j][5] * 2) % mod;
	}
	cout << vvi[n][5] << endl;
	return 0;
}
