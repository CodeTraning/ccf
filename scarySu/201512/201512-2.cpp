//
//  main.cpp
//  201512-2
//
//  Created by Liangxiao Su on 2019/3/2.
//  Copyright © 2019 Liangxiao Su. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int n, m;
    int array[32][32], newarray[32][32] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> array[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-2; j++) {
            if (array[i][j] == array[i][j+1] && array[i][j] == array[i][j+2]) {
                newarray[i][j] = newarray[i][j+1] = newarray[i][j+2] = 1;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n-2; i++) {
            if (array[i][j] == array[i+1][j] && array[i][j] == array[i+2][j]) {
                newarray[i][j] = newarray[i+1][j] = newarray[i+2][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < m; j++) {
            if (newarray[i][j] == 1) {
                if (flag == 0) {
                    flag = 1;
                    printf("0");
                } else {
                    printf(" 0");
                }
            } else {
                if (flag == 0) {
                    flag = 1;
                    printf("%d", array[i][j]);
                } else {
                    printf(" %d", array[i][j]);
                }
            }
        }
        putchar('\n');
    }
    return 0;
}

