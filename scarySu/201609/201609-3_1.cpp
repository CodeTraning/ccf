#include <iostream>

using namespace std;

struct role {
    int att;
    int hea;
};
role part1[9], part2[9];

void summon(int p, int a, int h, bool flag) {
    if (flag) {
        if (part1[p].hea != 0) {
            for (int i = 7; i > p; i--) {
                part1[i].hea = part1[i-1].hea;
                part1[i].att = part1[i-1].att;
            }
        }
        part1[p].hea = h; part1[p].att = a;
    } else {
        if (part2[p].hea != 0) {
            for (int i = 7; i > p; i--) {
                part2[i].hea = part2[i-1].hea;
                part2[i].att = part2[i-1].att;
            }
        }
        part2[p].hea = h; part2[p].att = a;
    }
}

void attack(int x, int y, bool flag) {
    
    if (flag) {
        part1[x].hea -= part2[y].att;
        part2[y].hea -= part1[x].att;
        if (part1[x].hea <= 0 && x != 0) {
            for (int i = x; i <= 7; i++) {
                part1[i].hea = part1[i+1].hea;
                part1[i].att = part1[i+1].att;
            }
        }
        if (part2[y].hea <= 0 && y != 0) {
            for (int i = y; i <= 7; i++) {
                part2[i].hea = part2[i+1].hea;
                part2[i].att = part2[i+1].att;
            }
        }
    } else {
        part1[y].hea -= part2[x].att;
        part2[x].hea -= part1[y].att;
        if (part1[y].hea <= 0 && y != 0) {
            for (int i = y; i <= 7; i++) {
                part1[i].hea = part1[i+1].hea;
                part1[i].att = part1[i+1].att;
            }
        }
        if (part2[x].hea <= 0 && x != 0) {
            for (int i = x; i <= 7; i++) {
                part2[i].hea = part2[i+1].hea;
                part2[i].att = part2[i+1].att;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    part1[0].hea = 30;
    part2[0].hea = 30;
    for (int i = 1; i <= 8; i++) {
        part1[i].hea = 0; part1[i].att = 0;
        part2[i].hea = 0; part2[i].att = 0;
    }
    char c[10];
    int p, a, h, x, y;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c[0] == 's') {
            cin >> p >> a >> h;
            summon(p, a, h, flag);
        } else if (c[0] == 'a') {
            cin >> x >> y;
            attack(x, y, flag);
        } else if (c[0] == 'e') {
            if (flag)
                flag = false;
            else
                flag = true;
        }
    }
    // Output
    if (part1[0].hea > 0 && part2[0].hea >0)
        cout << 0 << endl;
    else if (part1[0].hea > 0)
        cout << 1 << endl;
    else if (part2[0].hea > 0)
        cout << -1 << endl;
    int count = 0;
    cout << part1[0].hea << endl;
    for (int i = 1; i <= 7; i++) {
        if (part1[i].hea > 0)
            count++;
    }
    cout << count;
    for (int i = 1; i <= 7; i++) {
        if (part1[i].hea > 0)
            cout << " " << part1[i].hea;
    }
    cout << endl;
    count = 0;
    cout << part2[0].hea << endl;
    for (int i = 1; i <= 7; i++) {
        if (part2[i].hea > 0)
            count++;
    }
    cout << count;
    for (int i = 1; i <= 7; i++) {
        if (part2[i].hea > 0)
            cout << " " << part2[i].hea;
    }
    cout << endl;
    return 0;
}

