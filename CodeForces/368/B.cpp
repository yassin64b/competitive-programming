#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;

  vector<pair<pair<int, int>, int>> roads(m);
  for (int i = 0; i < m; ++i) {
    int u, v, l;
    cin >> u >> v >> l;
    roads[i] = {{u, v}, l};
  }

  map<int, bool> storage;
  for (int i = 0; i < k; ++i) {
    int a;
    cin >> a;
    storage[a] = true;
  }

  if (k == 0) {
    cout << -1 << endl;
    return 0;
  }

  int minRubles = 2e9;
  for (int i = 0; i < m; ++i) {
    int u = roads[i].first.first, v = roads[i].first.second;
    int l = roads[i].second;
    if (storage.find(u) != storage.end() && storage.find(v) == storage.end()) {
      minRubles = min(minRubles, l);
    } else if (storage.find(u) == storage.end() && storage.find(v) != storage.end()) {
      minRubles = min(minRubles, l);
    }
  }

  cout << (minRubles == 2e9 ? -1 : minRubles) << endl;
 
  return 0;
}