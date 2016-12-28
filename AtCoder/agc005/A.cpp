#include <iostream>
#include <string>

using namespace std;

int main()
{
	string X;
	cin >> X;

	int tcnt = 0, scnt = 0;
	for(int i = 0; i < (int)X.size(); ++i)
	{
		if(X[i] == 'S')
		{
			++scnt;
		}	
		else
		{
			++tcnt;
			if(scnt > 0)
				--scnt, --tcnt;
		}
	}
	
	cout << tcnt + scnt << endl;
	return 0;
}