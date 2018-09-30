#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int count = 1;
	int ans = 0;
	for (unsigned int i = 0; i < 11; i++)
	{
		if (str[i] != '-')
		{
			ans += (str[i] - '0') * count;
			ans %= 11;
			count++;
		}
	}
	char c1 = str[12];
	char c2;
	if (ans == 10)
	{
		c2 = 'X';
	}
	else
	{
		c2 = ans + '0';
	}
	if (c1 == c2)
	{
		cout << "Right" << endl;
	}
	else
	{
		str[12] = c2;
		cout << str << endl;
	}
	return 0;
}
