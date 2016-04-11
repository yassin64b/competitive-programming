#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int T, m, n, res;
	char c;
	cin >> T;

	for(int t = 0; t < T; ++t)
	{
		cin >> c >> m >> n;
		
		if(c == 'r')
			cout << (int)std::min(m, n) << endl;
		else if(c == 'k')
			cout << (m*n + m*n%2)/2 << endl;
		else if(c == 'Q')
			cout << int(std::min(m,n)) << endl;
		else
		{
			res = (m + m%2) * (n + n%2) / 4;
			cout << res << endl;
		}	
	}
	return 0;
}