#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> p(n);
	for(int i = 0; i < n; ++i)
		cin >> p[i];

	vector<string> text(n);
	getline(cin, text[0]);
	for(int i = 0; i < n; ++i)
		getline(cin, text[i]);

	bool flag = true;
	for(int i = 0; i < n; ++i)
	{
		int cnt = 0;
		for(int j = 0; j < (int)text[i].size(); ++j)
		{
			if(text[i][j] == 'a' || text[i][j] == 'e' || text[i][j] == 'i' ||
				text[i][j] == 'o' || text[i][j] == 'u' || text[i][j] == 'y')
				++cnt;
		}
		if(cnt != p[i])
			flag = false;
		//cout << cnt << endl;
	}

	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}