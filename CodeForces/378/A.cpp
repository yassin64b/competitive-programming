#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int ab = 1, cur = 1;
	string s;
	cin >> s;

	for(int i = 0; i < (int)s.size(); ++i)
	{
		if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
			s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
			ab = max(ab, cur), cur = 1;
		else
			++cur;
	}
	ab = max(ab, cur);
	cout << ab << endl;
	return 0;
}