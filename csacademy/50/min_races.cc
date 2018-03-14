#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> v(N);
    vector<int> classes(N);
    //vector<vector<int>> c(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
        classes[v[i].second - 1] = v[i].first;
        //c[v[i].first - 1].push_back(v[i].second - 1);
    }
    reverse(classes.begin(), classes.end());
    multiset<int> cur;
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (cur.upper_bound(classes[i]) != cur.end()) {
            //cout << "replace " << *cur.upper_bound(classes[i]) << " with " << classes[i] << endl;
            cur.erase(cur.upper_bound(classes[i]));
            cur.insert(classes[i]);
        } else {
            //cout << "new " << classes[i] << endl;
            cur.insert(classes[i]);
            ++res;
        }
    }
    cout << res << "\n";
    return 0;
}