#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<string> bus(n);
  for (int i = 0; i < n; ++i) {
    cin >> bus[i];
  }
  
  bool flag = false;
  for (int i = 0; !flag && i < n; ++i) {
    if (bus[i][0] == 'O' && bus[i][1] == 'O') {
      bus[i][0] = bus[i][1] = '+';
      flag = true;
    } else if (bus[i][3] == 'O' && bus[i][4] == 'O') {
      bus[i][3] = bus[i][4] = '+';
      flag = true;
    }
  }

  if (flag) {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      cout << bus[i] << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
