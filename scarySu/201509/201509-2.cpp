//
//  main.cpp
//  201509-2
//
//  Created by Liangxiao Su on 2019/3/3.
//  Copyright © 2019 Liangxiao Su. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int y, d;
    int flag = 0;
    int month = 1, days = 0;
    cin >> y >> d;
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        flag = 1;
    }
    for (int i = 0; i < d; i++) {
        if (month == 2) {
            days++;
            if (flag == 0 && days == 29) {
                month++; days = 1;
            } else if (flag == 1 && days == 30) {
                month++; days = 1;
            } else {
                continue;
            }
        } else {
            days++;
            if ((month == 4 || month == 6 || month == 9 || month == 11) && days == 31) {
                month++; days = 1;
            } else if ((month == 1 || month == 3 || month == 5 || month == 7 ||
                        month == 8 || month == 10 || month == 12) && days == 32) {
                month++; days = 1;
            } else {
                continue;
            }
        }
    }
    cout << month << endl << days << endl;
    return 0;
}

