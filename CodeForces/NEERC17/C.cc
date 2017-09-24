#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;

  string res;
  int curnesting = 0;
  long long cursum = 0;
  for (int i = 0; i < n; ++i) {
    res += "(";
    cursum += curnesting;
    ++curnesting;

    while (cursum + curnesting > k) {
      --curnesting;
      res += ")";
    }
  }
  if (cursum == k && curnesting == 0) {
    cout << res << endl;
  } else {
    cout << "Impossible\n";
  }
  return 0;
}
