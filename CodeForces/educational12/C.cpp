#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;

	cin >> s;

	int n = (int) s.size();
	for(int i = 0; i < n-1; ++i)
	{

		if(s[i] == s[i+1])
		{
			char x = 'a';

			while(s[i] == x || i < n-2 && s[i+2] == x)
				++x;

			s[i+1] = x;
		}
	}
	cout << s << endl;
}