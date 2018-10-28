#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Summon
{
    int position;
    int attack;
    int health;
};

struct Character
{
    int health;
    vector<Summon> summons;
};

bool cmp(Summon& a, Summon& b)
{
    if (a.health > 0 && b.health > 0)
    {
        return a.position < b.position;
    }
    return a.health > b.health;
}

Character characters[2];

void change(int turn, int pos, int flag)
{
    if (flag == 0)
    {
        int find = 0;
        for (int i = 0; i < characters[turn].summons.size(); i++)
        {
            if (characters[turn].summons[i].position == pos)
            {
                find = 1;
                break;
            }
        }
        if (find)
        {
            for (int i = 0; i < characters[turn].summons.size(); i++)
            {
                if (characters[turn].summons[i].position >= pos)
                {
                    characters[turn].summons[i].position++;
                }
            }
        }
    }
    else
    {
        int k = characters[turn].summons.size() - 1;
        if (characters[turn].summons[k].health <= 0)
        {
            for (int i = 0; i < characters[turn].summons.size(); i++)
            {
                if (characters[turn].summons[i].position >= pos)
                {
                    characters[turn].summons[i].position--;
                }
            }
            characters[turn].summons.pop_back();
        }
    }
}

void doAttack(int turn, int attacker, int defender)
{
    for (int i = 0; i < characters[turn].summons.size(); i++)
    {
        if (characters[turn].summons[i].position == attacker)
        {
            if (defender == 0)
            {
                characters[(turn + 1) % 2].health -=
                    characters[turn].summons[i].attack;
            }
            else
            {
                for (int j = 0; 
                        j < characters[(turn + 1) % 2].summons.size(); j++)
                {
                    if (characters[(turn + 1) % 2].summons[j].position == defender)
                    {
                        characters[turn].summons[i].health -= characters[(turn + 1) % 2].summons[j].attack;
                        characters[(turn + 1) % 2].summons[j].health -= characters[turn].summons[i].attack;
                        break;
                    }
                }
            }
            break;
        }
    }
}

int main()
{
    characters[0].health = 30;
    characters[1].health = 30;
    int turn = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str == "summon")
        {
            Summon s;
            int pos, attack, health;
            cin >> pos >> attack >> health;
            s.position = pos;
            s.attack = attack;
            s.health = health;
            change(turn, pos, 0);
            characters[turn].summons.push_back(s);
            sort(characters[turn].summons.begin(),
                    characters[turn].summons.end(), cmp);
        }
        else if (str == "attack")
        {
            int attacker;
            int defender;
            cin >> attacker >> defender;
            doAttack(turn, attacker, defender);
            if (characters[0].health <=0 || characters[1].health <= 0)
            {
                break;
            }
            sort(characters[turn].summons.begin(), characters[turn].summons.end(), cmp);
            sort(characters[(turn + 1) % 2].summons.begin(), characters[(turn + 1) % 2].summons.end(), cmp);
            change(turn, attacker, 1);
            change((turn + 1) % 2, defender, 1);
            sort(characters[turn].summons.begin(), characters[turn].summons.end(), cmp);
            sort(characters[(turn + 1) % 2].summons.begin(), characters[(turn + 1) % 2].summons.end(), cmp);
        }
        else if (str == "end")
        {
            turn = (turn + 1) % 2;
        }
    }
    if (characters[0].health <= 0 && characters[1].health > 0)
    {
        cout << -1 << endl;
    }
    else if (characters[0].health >0 && characters[1].health <= 0)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    cout << characters[0].health << endl;
    cout << characters[0].summons.size();
    for (int i = 0; i < characters[0].summons.size(); i++)
    {
        cout << " " << characters[0].summons[i].health;
    }
    cout << endl;
    cout << characters[1].health << endl;
    cout << characters[1].summons.size();
    for (int i = 0; i < characters[1].summons.size(); i++)
    {
        cout << " " << characters[1].summons[i].health;
    }
    cout << endl;
    return 0;
}
