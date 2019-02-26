//
//  main.cpp
//  201812-1
//
//  Created by Liangxiao Su on 2019/2/25.
//  Copyright © 2019 Liangxiao Su. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int r, y, g, n, k, t;
    cin >> r >> y >> g >> n;
    int sumTime = 0;
    for (int i = 0; i < n; i++) {
        cin >> k >> t;
        if (k == 0) {
            sumTime += t;
        } else if (k == 1) {
            sumTime += t;
        } else if (k == 2) {
            sumTime += (t + r);
        } else {
            continue;
        }
    }
    cout << sumTime << endl;
}

