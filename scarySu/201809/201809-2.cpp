//
//  main.cpp
//  201809-2
//
//  Created by Liangxiao Su on 2018/12/15.
//  Copyright © 2018 Liangxiao Su. All rights reserved.
//

#include <iostream>

using namespace std;

const int N = 1000005;
int res[N] = {0};

int main() {
    int n;
    cin >> n;
    int a, b, maxN = 0;
    for (int i = 0; i < 2*n; i++) {
        cin >> a >> b;
        if (b > maxN) maxN = b;
        for (int j = a; j < b; j++) res[j]++;
    }
    int sum = 0;
    for (int i = 1; i <= maxN; i++) {
        if (res[i] == 2) sum++;
    }
    cout << sum << endl;
    return 0;
}

