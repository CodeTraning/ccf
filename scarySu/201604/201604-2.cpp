#include <iostream>

using namespace std;

int main() {
    int squ[20][20] = {0}, pla[4][4], pos, pos1 = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++)
            cin >> squ[i][j];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> pla[i][j];
            if (pla[i][j] == 1)
                pos1 = i;
        }
    }
    cin >> pos;
    bool flag = true;
    for (int i = 0; i < 15; i++) {
        int q = 4;
        if (i > 11)
            q = 15 - i;
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < 4; k++) {
                if (squ[i+j][pos+k-1] == 1 && pla[j][k] == 1) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag)
            continue;
        else {
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++)
                    if (squ[i+x-1][pos+y-1] == 0)
                        squ[i+x-1][pos+y-1] = pla[x][y];
            }
            break;
        }
    }
    if (flag) {
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++)
                if (squ[14-pos1+x][pos+y-1] == 0)
                    squ[14-pos1+x][pos+y-1] = pla[x][y];
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0)
                cout << squ[i][j];
            else
                cout << " " << squ[i][j];
        }
        cout << endl;
    }
    return 0;
}

