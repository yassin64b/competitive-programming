#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int s, x1, x2;
    cin >> s >> x1 >> x2;

    int t1, t2;
    cin >> t1 >> t2;

    int p, d;
    cin >> p >> d;


    int timex = abs(x2 - x1) * t2; 
    if (t1 >= t2) {
        cout << timex << endl;
        return 0;
    }

    int timet;
    if (d == 1) {
        if (x1 < p) {
            //pickup
            timet += abs(s - p) * t1;
            timet += abs(s - x1) * t1;

            //d = -1
            if (x2 > x1) {
                timet += abs(0 - x1) * t1;
                timet += abs(0 - x2) * t1;
            } else {
                timet += abs(x1 - x2) * t1;
            }
        } else {
            //pickup
            timet += abs(x1 - p) * t1;

            if (x2 < x1) {
                timet += abs(s - x1) * t1;
                timet += abs(s - x2) * t1;
            } else {
                timet += abs(x1 - x2) * t1;
            }
        }

        
    } else {
        if (x1 > p) {
            //pickup
            timet += abs(0 - p) * t1;
            timet += abs(0 - x1) * t1;
            
            //d = 1
            if (x2 < x1) {
                timet += abs(s - x1) * t1;
                timet += abs(s - x2) * t1;
            } else {
                timet += abs(x1 - x2) * t1;
            }
        } else {
            //pickup
            timet += abs(x1 - p) * t1;

            if (x2 > x1) {
                timet += abs(0 - x1) * t1;
                timet += abs(0 - x2) * t1;
            } else {
                timet += abs(x1 - x2) * t1;
            }
        }
    }
    //cout << timet << " " << timex << endl;
    cout << min(timet, timex) << endl;

    return 0;
}