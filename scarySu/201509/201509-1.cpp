//
//  main.cpp
//  201509-1
//
//  Created by Liangxiao Su on 2019/3/3.
//  Copyright © 2019 Liangxiao Su. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int n, a, num, count = 1;
    cin >> n >> a;
    num = a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (a == num) {
            continue;
        } else {
            num = a;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

