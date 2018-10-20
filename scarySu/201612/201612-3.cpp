//
//  main.cpp
//  201612-3
//
//  Created by Liangxiao Su on 2018/10/20.
//  Copyright © 2018 Liangxiao Su. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

struct Privilege {
    string name;
    int level;
} privileges[101];
struct Role {
    string name;
    int priNum;
    struct Privilege pri[11];
} roles[105];
struct User {
    string name;
    int rolNum;
    struct Role rol[11];
} users[101];

struct Privilege setPri (string priName) {
    struct Privilege p;
    if (priName.find(":", 0) != string::npos) {
        int pos = priName.find(":", 0);
        p.name = priName.substr(0, pos);
        p.level = priName.at(priName.length() - 1) - '0';
    } else {
        p.name  = priName;
        p.level = -1;
    }
    return p;
}

int searchRol(string roleName, int allRoleNum)
{
    for (int i = 0; i < allRoleNum; i++) {
        if (roleName == roles[i].name) return i;
    }
    return -1;
}

int searchUser(string userName, int allUserNum)
{
    for (int i = 0; i < allUserNum; i++) {
        if (users[i].name == userName) return i;
    }
    return -1;
}
int main() {
    int p, allRoleNum, allUserNum, q;
    string priName, roleName, userName;
    cin >> p;
    for (int i = 0; i < p; i++) {
        cin >> priName;
        privileges[i] = setPri(priName);
    }
    cin >> allRoleNum;
    for (int i = 0; i < allRoleNum; i++) {
        cin >> roles[i].name >> roles[i].priNum;
        for (int j = 0; j < roles[i].priNum; j++) {
            cin >> priName;
            roles[i].pri[j] = setPri(priName);
        }
    }
    cin >> allUserNum;
    for (int i = 0; i < allUserNum; i++) {
        cin >> users[i].name >> users[i].rolNum;
        for (int j = 0; j < users[i].rolNum; j++) {
            cin >> roleName;
            users[i].rol[j] = roles[searchRol(roleName, allRoleNum)];
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int maxLevel = -1;
        bool flag = false;
        Privilege pri1;
        Role role1;
        User user1;
        cin >> userName >> priName;
        if (searchUser(userName, allUserNum) != -1) {
            user1 = users[searchUser(userName, allUserNum)];
            pri1 = setPri(priName);
            for (int k = 0; k < user1.rolNum; k++) {
                role1 = user1.rol[k];
                for (int j = 0; j < role1.priNum; j++) {
                    if (role1.pri[j].name == pri1.name) {
                        if (role1.pri[j].level == -1 && pri1.level == -1)
                            flag = true;
                        else if (role1.pri[j].level != -1 && pri1.level == -1) {
                            flag = true;
                            if (maxLevel < role1.pri[j].level)
                                maxLevel = role1.pri[j].level;
                        } else if (role1.pri[j].level != -1 && pri1.level != -1) {
                            if (role1.pri[j].level >= pri1.level)
                                flag = true;
                        }
                    }
                }
            }
        }
        if (!flag) cout << "false" << endl;
        else if (maxLevel != -1) cout << maxLevel << endl;
        else cout << "true" << endl;
    }
    return 0;
}

