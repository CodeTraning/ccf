#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Permission
{
    string name;
    int level;
};

struct Role
{
    string name;
    struct Permission per[11];
    int number;
};

struct User
{
    string name;
    struct Role userRole[11];
    int number;
};

struct Permission per[101];
struct Role role[101];
struct User user[101];

int findPermission(string str)
{
    for (int i = 0; i < 101; i++)
    {
        if (per[i].name == str)
        {
            return i;
        }
    }
    return -1;
}

int findRole(string str)
{
    for (int i = 0; i < 101; i++)
    {
        if (role[i].name == str)
        {
            return i;
        }
    }
    return -1;
}

int findUser(string str)
{
    for (int i = 0; i < 101; i++)
    {
        if (user[i].name == str)
        {
            return i;
        }
    }
    return -1;
}

struct Permission solvePermission(string str)
{
    struct Permission p;
    if (str.find(":", 0) != string::npos)
    {
        int pos = str.find(":", 0);
        p.name = str.substr(0, pos);
        p.level = str[str.length() - 1] - '0';
    }
    else
    {
        p.name = str;
        p.level = -1;
    }
    return p;
}

int main()
{
    int p, r, u, q;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        string str;
        cin >> str;
        per[i] = solvePermission(str);
    }
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        cin >> role[i].name;
        cin >> role[i].number;
        for (int j = 0; j < role[i].number; j++)
        {
            string str;
            cin >> str;
            role[i].per[j] = solvePermission(str);
        }
    }
    cin >> u;
    for (int i = 0; i < u; i++)
    {
        cin >> user[i].name;
        cin >> user[i].number;
        for (int j = 0; j < user[i].number; j++)
        {
            string str;
            cin >> str;
            user[i].userRole[j] = role[findRole(str)];
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string name;
        string str;
        cin >> name >> str;
        struct Permission p;
        p = solvePermission(str);
        int flag = 0;
        int maxLevel = -1;
        if (findUser(name) != -1)
        {
            struct User u = user[findUser(name)];
            for (int j = 0; j < u.number; j++)
            {
                for (int k = 0; k < u.userRole[j].number; k++)
                {
                    if (p.name == u.userRole[j].per[k].name)
                    {
                        if (p.level == -1 && u.userRole[j].per[k].level == -1)
                        {
                            flag = 1;  
                        }
                        else if (p.level == -1 && u.userRole[j].per[k].level != -1)
                        {
                            if (maxLevel < u.userRole[j].per[k].level)
                            {
                                flag = 1;
                                maxLevel = u.userRole[j].per[k].level;
                            }
                        }
                        else if (p.level != -1 && u.userRole[j].per[k].level != -1)
                        {
                            if (p.level <= u.userRole[j].per[k].level)
                            {
                                flag = 1;
                            }
                        }
                    }
                }
            }
        }
        if (flag == 1 && maxLevel != -1)
        {
            cout << maxLevel << endl;
        }
        else if (flag == 1 && maxLevel == -1)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    return 0;
}
