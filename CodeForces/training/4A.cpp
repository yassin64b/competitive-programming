#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <utility>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	int w;
	cin >> w;

	if(w > 2 && w % 2 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}