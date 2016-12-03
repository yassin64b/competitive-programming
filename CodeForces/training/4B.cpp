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

  int n;
  cin >> n;

  map<string, int> table;
  for (int i = 0; i < n; ++i) {
    string name;
    cin >> name;
    if (table[name] == 0) {
      cout << "OK" << endl;
    } else {
      cout << name << table[name] << endl;
    }
    ++table[name];
  }

  return 0;
}