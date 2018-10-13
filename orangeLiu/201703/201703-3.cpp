#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> strs;

void output(string str)
{
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '_')
        {
            int r = str.find('_', i + 1);
            string tmp = "<em>" + str.substr(i + 1, r - i - 1) + "</em>";
            output(tmp);
            i = r;
        }
        else if (str[i] == '[')
        {
            int r = str.find(']', i + 1);
            string text = str.substr(i + 1, r - i - 1);
            int linkl = str.find('(', r + 1);
            int linkr = str.find(')', r + 1);
            string link = str.substr(linkl + 1, linkr - linkl - 1);
            string tmp = "<a href=\"" + link + "\">" + text + "</a>";
            output(tmp);
            i = linkr;
        }
        else
        {
            cout << str[i];
        }
    }
}

void fun_h()
{
    int len = strs[0].length();
    int pos, count = 0;
    for (int i = 0; i < len; i++)
    {
        if (strs[0][i] == '#')
        {
            count++;
        }
        if (strs[0][i] != '#' && strs[0][i] != ' ')
        {
            pos = i;
            break;
        }
    }
    cout << "<h" << count << ">";
    output(strs[0].substr(pos));
    cout << "</h" << count << ">" << endl;
}

void fun_p(int count)
{
    cout << "<p>";
    for (int i = 0; i < count; i++)
    {
        output(strs[i]);
        if (i == count - 1)
        {
            cout << "</p>";
        }
        cout << endl;
    }
}

void fun_l(int count)
{
    cout << "<ul>" << endl;
    for (int i = 0; i < count; i++)
    {
        int len = strs[i].length();
        int pos, count = 0;
        for (int j = 1; j < len; j++)
        {
            if (strs[i][j] != ' ')
            {
                pos = j;
                break;
            }
        }
        cout << "<li>";
        output(strs[i].substr(pos));
        cout << "</li>" << endl;
    }
    cout << "</ul>" << endl;
}

int main()
{
    string line;
    int count = 0;
    while (getline(cin, line))
    {
        if (line == "")
        {
            if (count == 0)
            {
                continue;
            }
            if (strs[0][0] == '#')
            {
                fun_h();
                strs.clear();
            }
            else if (strs[0][0] == '*')
            {
                fun_l(count);
                strs.clear();
            }
            else
            {
                fun_p(count);
                strs.clear();
            }
            count = 0;
            continue;
        }
        strs.push_back(line);
        count++;
    }
    if (count)
    {
        if (strs[0][0] == '#')
        {
            fun_h();
            strs.clear();
        }
        else if (strs[0][0] == '*')
        {
            fun_l(count);
            strs.clear();
        }
        else
        {
            fun_p(count);
            strs.clear();
        }
    }
    return 0;
}
