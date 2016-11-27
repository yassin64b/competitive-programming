#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int gh, ins;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'T')
      ins = i;
    if (s[i] == 'G')
      gh = i;
  }

  if (gh < ins) {
    for (; gh < ins; gh += k) {
      if (s[gh] == '#') {
        cout << "NO" << endl;
        return 0;
      }
    }
  } else {
    for (; gh > ins; gh -= k) {
      if (s[gh] == '#') {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  
  //cout << gh << " " << ins << endl;
  if (gh != ins) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }

  return 0;
}