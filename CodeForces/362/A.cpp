#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int t, s, x;
	cin >> t >> s >> x;

	if(t == x) cout << "YES" << endl;
	else if(x < t + s) cout << "NO" << endl;
	else if(abs(((double)x - t) / s - round(((double)x - t) / s)) <= 0.001
	 || abs(((double)x - t - 1) / s - round(((double)x - t - 1) / s)) <= 0.001)
		cout << "YES" << endl;
	else
	 	cout << "NO" << endl; 

	return 0;
} 