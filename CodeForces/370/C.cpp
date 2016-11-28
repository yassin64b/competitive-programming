#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  int x, y;
  cin >> x >> y;

  int xs[] = {y, y, y};
  int cnt = 0;
  //int ind = 0;
  while (xs[0] != x || xs[1] != x || xs[2] != x) {
    sort(xs, xs + 3);
    xs[0] = min(xs[1] + xs[2] - 1, x);
    ++cnt;
  }
  cout << cnt << endl;
  return 0;
}