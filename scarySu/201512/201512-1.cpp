//
//  main.cpp
//  201512-1
//
//  Created by Liangxiao Su on 2019/3/2.
//  Copyright © 2019 Liangxiao Su. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char num;
    int sumNum = 0;
    while ((num = getchar()) && num != '\n') {
        sumNum += (num - '0');
    }
    cout << sumNum << endl;
    return 0;
}

