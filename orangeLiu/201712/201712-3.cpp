#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string month[13] = {"","jan","feb","mar","apr","may","jun","jul","aug",
    "sep","oct","nov","dec"};
string week[7] = {"sun","mon","tue","wed","thu","fri","sat"};
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string, int> weekMap, monthMap;
int n;
map<string, vector<string> > mp;

string int_to_string(int a)
{
    ostringstream os;
    os << a;
    return os.str();
}

int string_to_int(const string& str)
{
    int num;
    istringstream is(str);
    is >> num;
    return num;
}

bool isLeap(int year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

string getweek(const string& cyyyy, const string& cmm, const string& cdd)
{
    int yyyy = string_to_int(cyyyy);
    int mm = string_to_int(cmm);
    int dd = string_to_int(cdd);
    // calculate year
    int sum = 0;
    for (int i = 1970; i < yyyy; i++)
    {
        sum += isLeap(i) ? 366 : 365;
    }
    // calculate month
    if (isLeap(yyyy)) 
    {
        day[2] = 29;
    }
    else
    {
        day[2] = 28;
    }
    for (int i = 1; i < mm; i++)
    {
        sum += day[i];
    }
    // calculate day
    sum += dd - 1;
    return int_to_string((4 + sum) % 7);
}

void initmap()
{
    for (int i = 0; i <= 6; i++)
    {
        weekMap[week[i]] = i;
    }
    for (int i = 1; i <= 12; i++)
    {
        monthMap[month[i]] = i;
    }
}

void tostandard(string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }
}

// type == 1 --> week, type == 2 --> month
vector<string> buildvector(string& str, int type = 0)
{
    vector<string> retvec;
    str += ",";
    int ix;
    while((ix = str.find(',')) != string::npos)
    {
        string temp = str.substr(0, ix);
        str = str.substr(ix + 1);
        int fx;
        if ((fx = temp.find('-')) != string::npos)
        {
            string ls = temp.substr(0, fx);
            string rs = temp.substr(fx + 1);
            int lix, rix;
            if (isalpha(ls[0]))
            {
                if (type == 1)
                {
                    lix = weekMap[ls];
                }
                else
                {
                    lix = monthMap[ls];
                }
            }
            else
            {
                lix = string_to_int(ls);
            }
            if (isalpha(rs[0]))
            {
                if (type == 1)
                {
                    rix = weekMap[rs];
                }
                else
                {
                    rix = monthMap[rs];
                }
            }
            else
            {
                rix = string_to_int(rs);
            }
            for (int i = lix; i <= rix; i++)
            {
                retvec.push_back(int_to_string(i));
            }
        }
        else
        {
            if (isalpha(temp[0]))
            {
                if (type == 1)
                {
                    retvec.push_back(int_to_string(weekMap[temp]));
                }
                else
                {
                    retvec.push_back(int_to_string(monthMap[temp]));
                }
            }
            else
            {
                retvec.push_back(temp);
            }
        }
    }
    return retvec;
}

int main()
{
    cin >> n;
    string stime, etime;
    cin >> stime >> etime;
    int syyyy = string_to_int(stime.substr(0, 4));
    int eyyyy = string_to_int(etime.substr(0, 4));
    initmap();
    while (n--)
    {
        string minutes, hours, day_of_month, month, day_of_week, command;
        cin >> minutes >> hours >> day_of_month >> month >>day_of_week >> command;
        tostandard(month);
        tostandard(day_of_week);
        if (minutes == "*")
        {
            minutes = "0-59";
        }
        vector<string> vminutes = buildvector(minutes, 0);
        if (hours == "*")
        {
            hours = "0-23";
        }
        vector<string> vhours = buildvector(hours, 0);
        if (day_of_month == "*")
        {
            day_of_month = "1-31";
        }
        vector<string> vday_of_month = buildvector(day_of_month, 0);
        if (month == "*")
        {
            month = "1-12";
        }
        vector<string> vmonth = buildvector(month, 2);
        if (day_of_week == "*")
        {
            day_of_week = "0-6";
        }
        vector<string> vday_of_week = buildvector(day_of_week, 1);
        set<string> set1(vday_of_week.begin(), vday_of_week.end());
        int tempyyyy = syyyy;
        while (tempyyyy <= eyyyy)
        {
            if (isLeap(tempyyyy))
            {
                day[2] = 29;
            }
            else
            {
                day[2] = 28;
            }
            for (int i = 0; i < vmonth.size(); i++)
            {
                for (int j = 0; j < vday_of_month.size(); j++)
                {
                    string cyyyy = int_to_string(tempyyyy);
                    string cmm = vmonth[i];
                    string cdd = vday_of_month[j];
                    if (day[string_to_int(cmm)] < string_to_int(cdd)
                            || set1.count(getweek(cyyyy, cmm, cdd)) == 0)
                    {
                        continue;
                    }
                    for (int k = 0; k < vhours.size(); k++)
                    {
                        for (int m = 0; m < vminutes.size(); m++)
                        {
                            string ss = cyyyy +
                                (cmm.size() > 1 ? cmm : "0" + cmm) +
                                (cdd.size() > 1 ? cdd : "0" + cdd) +
                                (vhours[k].size() > 1 ? vhours[k] : "0" + vhours[k]) +
                                (vminutes[m].size() > 1 ? vminutes[m] : "0" + vminutes[m]);
                            if (ss >= stime && ss < etime)
                            {
                                mp[ss].push_back(command);
                            }
                        }
                    }
                }
            }
            tempyyyy++;
        }
    }
    map<string, vector<string> >::iterator it = mp.begin();
    for (; it != mp.end(); it++)
    {
        set<string> set1;
        for (int i = 0; i < it->second.size(); i++)
        {
            if (set1.count(it->second[i]) == 0)
            {
                cout << it->first << " " << it->second[i] << endl;
                set1.insert(it->second[i]);
            }
        }
    }
    return 0;
}
