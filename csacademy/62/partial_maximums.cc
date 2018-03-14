#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <numeric>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    
    vector<int> r(n);
    int mx = 0;
    for (int i = 0; i < n; ++i)
        if (p[i] > mx)
            mx = p[i], r[i] = 1;
    int sum = accumulate(r.begin(), r.end(), 0);
    
    vector<int> x(n);
    multiset<pair<int, int>> s;
    s.emplace(p[0], 0);
    for (int i = 1; i < n; ++i) {
        if ((--s.end())->first > p[i]) {
            if (s.size() == 1U || (--(--s.end()))->first < p[i]) {
                ++x[(--s.end())->second];
            }
        }
        s.emplace(p[i], i);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        //cout << x[i] << " " << sum - r[i] << endl;
        res = max(res, x[i] + sum - r[i]);
    }
    cout << res << "\n";
    return 0;
}