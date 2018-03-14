#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N, X;
    cin >> N >> X;
    vector<pair<int, int>> ab(N);
    for (int i = 0; i < N; ++i) {
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(), ab.end());
    int best = X, cur = X, cur_disc = 0;
    for (int i = 0; i < N; ++i) {
        cur = max(cur, ab[i].first);
        cur_disc += ab[i].second;
        best = min(best, cur - cur_disc);
    }
    cout << best << endl;
    
    return 0;
}