//
//  main.cpp
//  201812-2
//
//  Created by Liangxiao Su on 2019/2/28.
//  Copyright © 2019 Liangxiao Su. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int light[3];
    ll n, k, t, sum = 0;
    cin >> light[0] >> light[2] >> light[1] >> n;
    ll cycle = light[0] + light[1] + light[2];
    while (n--) {
        cin >> k >> t;
        if (k == 0) {
            sum += t;
        } else {
            if (k == 1) k = 0;
            if (k == 3) k = 1;
            
            t = (light[k] - t + sum) % cycle;
            while (t > light[k]) {
                t -= light[k];
                k = (k+1) % 3;
            }
            
            if (k == 0) {
                sum += light[k] - t;
            } else if (k == 2) {
                sum += light[k] - t + light[0];
            }
        }
    }
    cout << sum << endl;
}

