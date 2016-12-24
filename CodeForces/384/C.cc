#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int x = n, y = n + 1, z;
    double nn = n, xx = x, yy = y, zz;

    zz = (2. / nn) - (1. / xx + 1. / yy);
    zz = 1. / zz;
    z = round(zz);
    
    //cout << xx << " " << yy << " " << (zz) << " " << z << endl << endl;
    //cout << abs(z - zz) << endl;
    
    if (x != y && x != z && y != z && abs(z - zz) < 0.001) {
        cout << x << " " << y << " " << z << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}