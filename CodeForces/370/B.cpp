#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.size();
  if (n % 2 == 1) {
    cout << -1 << endl;
    return 0;
  }

  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') --x;
    else if (s[i] == 'R') ++x;
    else if (s[i] == 'U') ++y;
    else if (s[i] == 'D') --y;
  }
  cout << (abs(x) + abs(y)) / 2 << endl;

  return 0;
}