#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> lists;
  map<int, int> m;
  lists.push_back({a[0]});
  m[a[0]] = 0;
  for (int i = 1; i < n; ++i) {
    auto it = m.lower_bound(a[i]);
    if (it == m.begin()) {
      lists.push_back({a[i]});
      m[a[i]] = lists.size() - 1;
    } else {
      --it;
      int ind = it->second;
      lists[ind].push_back(a[i]);
      m.erase(it);
      m[a[i]] = ind;
    }
  }
  for (const vector<int>& v : lists) {
    for (int x : v) {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  return 0;
}
