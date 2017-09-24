#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> v[i].first >> v[i].second;
  }
  vector<pair<int, int>> lists;
  vector<int> vis(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      vis[i] = 1;
      int end = i;
      while (v[end].second) {
        end = v[end].second;
        vis[end] = 1;
      }
      int start = i;
      while (v[start].first) {
        start = v[start].first;
        vis[start] = 1;
      }
      lists.emplace_back(start, end);
    }
  }
  for (int i = 0; i + 1 < (int)lists.size(); ++i) {
    int end1 = lists[i].second, start2 = lists[i + 1].first;
    v[end1].second = start2;
    v[start2].first = end1;
  }
  for (int i = 1; i <= n; ++i) {
    cout << v[i].first << " " << v[i].second << "\n";
  }
  return 0;
}
