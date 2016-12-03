#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<int, int>> trees(n);
    for (int i = 0; i < n; ++i) {
        cin >> trees[i].first >> trees[i].second;
    }

    int occupied = -2e9, last = -2e9, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (trees[i].first <= occupied) {
            occupied = last;
            --cnt;
        }
        if (trees[i].first - trees[i].second > occupied) {
            ++cnt;
            occupied = trees[i].first;
            last = -2e9;
        } else if (trees[i].first > occupied) {
            ++cnt;
            occupied = trees[i].first + trees[i].second;
            last = trees[i].first;
        } 
    }

    cout << cnt << endl;

    return 0;
}