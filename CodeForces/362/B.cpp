#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, a, d; 
	int b;
	cin >> s;
	
	int i = 0, n = s.size();
	while(i < n && s[i] != '.')
		a += s[i++];
	++i;
	while(i < n && s[i] != 'e')
		d += s[i++];
	++i;
	
	b = stoi(s.substr(i));

	string res;
	if(b <= d.size())
		res += a + d.substr(0, b) + "." + d.substr(b);
	else
		res += a + d + string(b - d.size(), '0');

	if(res[0] == '0' && res[1] != '.')
		res = res.substr(1);
	if(res[res.size()-1] == '0' && b <= d.size())
		res = res.substr(0, res.size()-1);
	if(res[res.size()-1] == '.')
		res = res.substr(0, res.size()-1);

	cout << res << endl;
	return 0;
}