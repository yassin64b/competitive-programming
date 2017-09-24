#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  vector<long long> mx1(n, 0), mx2(n, 0);
  mx1[0] = a[0];
  for (int i = 1; i < n; ++i) {
    mx1[i] = max(mx1[i - 1] + 1, (long long)a[i]);
  }
  mx2[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    mx2[i] = max(mx2[i + 1] + 1, (long long)a[i]);
  }

  vector<long long> peakval(n, 0);
  for (int i = 0; i < n; ++i) {
    peakval[i] = max(mx1[i], mx2[i]);
  }

  vector<long long> inccost(n, 0), deccost(n, 0);
  for (int i = 1; i < n; ++i) {
    inccost[i] = inccost[i - 1] + (mx1[i] - a[i]);
  }
  for (int i = n - 2; i >= 0; --i) {
    deccost[i] = deccost[i + 1] + (mx2[i] - a[i]);
  }

  long long res = peakval[0] - a[0] + deccost[1];
  res = min(res, peakval[n - 1] - a[n - 1] + inccost[n - 2]);
  for (int i = 1; i < n; ++i) {
    res = min(res, peakval[i] - a[i] + inccost[i - 1] + deccost[i + 1]);
  }
  std::cout << res << std::endl;
  return 0;
}
