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
	int n, m, a;
	cin >> n >> m >> a;
	cout << ((ll)n/a + (n%a ? 1 : 0)) * ((ll)m/a + (m%a ? 1 : 0)) << endl; 


	return 0;
}