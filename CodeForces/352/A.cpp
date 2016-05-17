#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string line;
	for(int i = 1; i <= n; ++i)
	{
		line += to_string(i);

		if(line.size() > n)
			break;
	}
	
	cout << line[n-1] << endl;

	return 0;
}