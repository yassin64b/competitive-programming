#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	for(int i = 0; i < n; ++i) 
	{
		int a;
		cin >> a;
		if(a == 0) 
			++cnt;
	}
	if(n == 1 && cnt == 0) 
		cout << "YES" << endl;
	else if(n == 1 || cnt == 0 || cnt > 1) 
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}