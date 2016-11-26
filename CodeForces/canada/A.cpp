#include <string>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, res = 0;
	cin >> n;
	string s;
	cin >> s;
	int i = 0;
	while(i < n && s[i] == '<')
		++res, ++i;
	i = n-1;
	while(i >= 0 && s[i] == '>')
		++res, --i;
	cout << res << endl;
	return 0;
}