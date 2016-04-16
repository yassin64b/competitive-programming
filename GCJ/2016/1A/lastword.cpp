#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;

	string S;

	for(int t = 1; t <= T; ++t)
	{
		cin >> S;

		string res(1, S[0]);
		
		for(int i = 1; i < (int)S.size(); ++i)
		{
			if(S[i] >= res[0])
				res = S[i] + res;
			else
				res += S[i];
		}

		cout << "Case #" << t << ": " << res << endl;
	}

	return 0;
}