#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dist(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);    
}

int square(pair<int, int> p[4])
{
    int d2 = dist(p[0], p[1]);
    int d3 = dist(p[0], p[2]);
    int d4 = dist(p[0], p[3]);
 
    if (d2 == d3 && 2*d2 == d4) {
        int d = dist(p[1], p[3]);
        return (d == dist(p[2], p[3]) && d == d2);
    }
 
    if (d3 == d4 && 2*d3 == d2) {
        int d = dist(p[1], p[2]);
        return (d == dist(p[1], p[3]) && d == d3);
    }
    if (d2 == d4 && 2*d2 == d3) {
        int d = dist(p[1], p[2]);
        return (d == dist(p[2], p[3]) && d == d2);
    }
 
    return 0;
}

int main() 
{
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        pair<int, int> pts[4];
        for (int i = 0; i < 4; ++i) {
            cin >> pts[i].first >> pts[i].second;
        }
        cout << square(pts) << "\n";
    }
    
    
    return 0;
}