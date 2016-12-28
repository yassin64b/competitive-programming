#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	bool flag1 = false, flag2 = false;
	for(int i = 0; i < (int)s.size(); ++i)
	{
		if(s[i] == 'C')
			flag1 = true;
		if(s[i] == 'F' && flag1)
			flag2 = true;
	}
	if(flag1 && flag2)
	{
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;
	return 0;
}