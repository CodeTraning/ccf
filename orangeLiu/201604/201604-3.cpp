#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string cur;
    cin >> n;
    getchar();
    cin >> cur;
    getchar();
    for (int i = 0; i < n; i++)
    {
        string line;
        int pos, pos1;
        getline(cin, line);
        if (line.empty())
        {
            line = cur;
        }
        else if (line[0] != '/')
        {
            line = cur + "/" + line;
        }
        while ((pos = line.find("/../")) != -1)
        {
            if (!pos)
            {
                line.erase(0, 3);
            }
            else
            {
                pos1 = line.rfind("/", pos - 1);
                line.erase(pos1, pos - pos1 + 3);
            }
        }
        while ((pos = line.find("/./")) != -1)
        {
            line.erase(pos, 2);
        }
        while ((pos = line.find("//")) != -1)
        {
            line.erase(pos, 1);
        }
        if (line.size() > 1 && line[line.size() - 1] == '/')
        {
            line.erase(line.size() - 1, 1);
        }
        cout << line << endl;
    }
    return 0;
}
