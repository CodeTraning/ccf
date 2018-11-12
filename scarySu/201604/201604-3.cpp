#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>

using namespace std;

int main() {
    int P;
    char s[1005] = {0}, test[1005] = {0}, Q[2005];
    cin >> P >> s;
    getchar();
    for (int i = 0; i < P; i++) {
        char c;
        int len;
        memset(Q, 0, sizeof(Q));
        memset(test, 0, sizeof(test));
        for (len = 0; (c = getchar()) != '\n'; len++) {
            test[len] = c;
        }
        for (len = 0; len < strlen(s); len++) {
            Q[len] = s[len];
        }
        int q[1005] = {0}, rank = 0;
        if (test[0] != '/') {
            Q[len] = '/';
            strcat(Q, test);
        } else {
            memset(Q, 0, sizeof(Q));
            strcat(Q, test);
        }
        for (int j = 0; j < strlen(Q); j++) {
            if (j == strlen(Q) - 1) break;
            if (j == strlen(Q) - 2 && Q[j] == '/' && Q[j+1] == '.') {
                Q[j+1] = '/';
                break;
            }
            if (j == strlen(Q) - 3 && Q[j] == '/' && Q[j+1] == '.' && Q[j+2] == '.') {
                for (int k = q[rank--]; k <= j + 2; k++)
                    Q[k] = '/';
                break;
            }
            if (Q[j] == '/') {
                if (Q[j+1] == '/') continue;
                else if (Q[j+1] == '.' && Q[j+2] == '/') {
                    Q[j+1] = '/';
                    j += 1;
                    continue;
                }
                else if (Q[j+1] == '.' && Q[j+2] == '.' && Q[j+3] == '/') {
                    if (rank == 0) {
                        for (int k = 0; k <= j + 2; k++)
                            Q[k] = '/';
                    } else {
                        for (int k = q[rank--]; k <= j + 2; k++)
                            Q[k] = '/';
                    }
                    j += 2;
                }
                else q[++rank] = j;
            }
        }
        bool flag = true;
        for (int j = 0; j < strlen(Q); j++) {
            if (j == strlen(Q) - 1 && Q[j] == '/' && flag) {
                cout << "/";
                break;
            } else if (j == strlen(Q) - 1 && Q[j] == '/' && !flag)
                break;
            if (Q[j] == '/' && Q[j+1] == '/') continue;
            else {
                cout << Q[j];
                flag = false;
            }
        }
        putchar('\n');
    }
    return 0;
}
