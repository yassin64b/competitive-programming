#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
	string a, b;

	while(getline(cin, a) && getline(cin, b))
	{
		//cout << a << " " << b << endl;
		vector<int> va(26, 0), vb(26, 0);

		for(char& c: a)
			va[c-'a']++;

		for(char& c: b)
			vb[c-'a']++;

		string res;
		for(int i = 0; i < 26; ++i)
		{
			int cnt = min(va[i], vb[i]);
			while(cnt--)
				res += 'a'+i;
		}	
		cout << res << endl;
	}
}