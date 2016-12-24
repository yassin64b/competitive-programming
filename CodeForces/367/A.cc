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

    int a, b, n;
    cin >> a >> b >> n;
    
    double res = 100000;
    for (int i = 0; i < n; ++i) {
        int x, y, v; 
        cin >> x >> y >> v;

        double t = sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v;
        res = min(res, t);
    }
    cout.precision(20);
    cout << fixed << res << endl;

    return 0;
}