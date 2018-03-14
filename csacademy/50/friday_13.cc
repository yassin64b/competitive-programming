#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int day = -1;
    string d;
    cin >> d;
    for (int i = 0; i < 7; ++i) {
        if (d == days[i]) {
            day = i;
        }
    }
    assert(day >= 0);
    
    int res = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < months[i]; ++j) {
            if (day == 4 && j == 12) {
                ++res;
            }
            day = (day + 1) % 7;
        }
    }
    cout << res << "\n";
    return 0;
}