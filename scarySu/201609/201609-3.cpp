#include <iostream>

using namespace std;

struct summon {
    int position;
    int attack;
    int health;
};

summon part1[8], part2[8];

void increase(int position, bool flag) {
    int a = 0, b = 0;
    for (int i = position; i < 7; i++) {
        if (flag && part1[i].health == 0)
            a = i;
        else if (!flag && part2[i].health == 0)
            b = i;
    }
    for (int i = a; i > position; i--) {
        part1[i].attack = part1[i-1].attack;
        part1[i].health = part1[i-1].health;
    }
    for (int i = b; i > position; i--) {
        part2[i].attack = part2[i-1].attack;
        part2[i].health = part2[i-1].health;
    }
}

void reduce(int position, bool flag) {
    if(!position)
        return;
    for (int i = position; i < 7; i++) {
        if (flag) {
            part1[i].attack = part1[i+1].attack;
            part1[i].health = part1[i+1].health;
        } else {
            part2[i].attack = part2[i+1].attack;
            part2[i].health = part2[i+1].health;
        }
    }
}

int main() {
    char action[6];
    int n, sum;
    cin >> n;
    bool flag = true;
    int pos, att, hea, attacker, defender;
    part1[0].position = 0; part1[0].attack = 0; part1[0].health = 30;
    part2[0].position = 0; part2[0].attack = 0; part2[0].health = 30;
    for (int i = 1; i < 8; i++) {
        part1[i].position = i; part1[i].attack = 0; part1[i].health = 0;
        part2[i].position = i; part2[i].attack = 0; part2[i].health = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> action;
        if (action[0] == 's') {
            cin >> pos >> att >> hea;
            if (flag) {
                if (part1[pos].health > 0) {
                    increase(pos, flag);
                }
                part1[pos].position = pos; part1[pos].attack = att; part1[pos].health = hea;
            } else {
                if (part2[pos].health > 0) {
                    increase(pos, flag);
                }
                part2[pos].position = pos; part2[pos].attack = att; part2[pos].health = hea;
            }
        } else if (action[0] == 'a') {
            cin >> attacker >> defender;
            if (flag) {
                part1[attacker].health -= part2[defender].attack;
                part2[defender].health -= part1[attacker].attack;
                if (part1[attacker].health <= 0) {
                    reduce(attacker, 1);
                    part1[7].health = 0;
                }
                if (part2[defender].health <= 0) {
                    reduce(defender, 0);
                    part2[7].health = 0;
                }
            } else {
                part2[attacker].health -= part1[defender].attack;
                part1[defender].health -= part2[attacker].attack;
                if (part1[defender].health <= 0) {
                    reduce(defender, 1);
                    part1[7].health = 0;
                }
                if (part2[attacker].health <= 0) {
                    reduce(attacker, 0);
                    part2[7].health = 0;
                }
            }
        } else if (action[0] == 'e') {
            if (flag)
                flag = false;
            else
                flag = true;
        }
    }
    // output
    if (part1[0].health > 0 && part2[0].health > 0)
        puts("0");
    else if (part1[0].health <= 0)
        puts("-1");
    else if (part2[0].health <= 0)
        puts("1");
    cout << part1[0].health << endl;
    sum = 0;
    for (int i = 1; i < 8; i++) {
        if (part1[i].health > 0) sum++;
    }
    cout << sum;
    for (int i = 1; i < 8; i++) {
        if (part1[i].health > 0)
            cout << " " << part1[i].health;
    }
    cout << endl;
    sum = 0;
    cout << part2[0].health << endl;
    for (int i = 1; i < 8; i++) {
        if (part2[i].health > 0) sum++;
    }
    cout << sum;
    for (int i = 1; i < 8; i++) {
        if (part2[i].health > 0)
            cout << " " << part2[i].health;
    }
    cout << endl;
    return 0;
}
