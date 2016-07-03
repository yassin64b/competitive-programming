#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		int K;
		cin >> K;

		vector<int> val(256, 0);

		for(int j = 0; j < K; ++j)
		{
			unsigned char c; //must be unsigned! otherwise RTE (using .at()) or WA (using [])
			cin >> c;
			cin >> val.at((int)c);
		}

		unsigned long long sum = 0;
		int M;
		cin >> M;
		cin.ignore(); //ignore newline
		for(int j = 0; j < M; ++j)
		{
			string s;
			getline(cin, s);

			for(int k = 0; k < (int)s.size(); ++k)
				sum += val.at((int)((unsigned char)s[k]));
		}

		cout << sum/100 << '.' << (sum%100)/10 << sum%10 << '$' << endl;
	}	
}