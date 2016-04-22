#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int N, longest = 0;
	cin >> N;

	vector<int> LS(N, 1), a(N);

	for(int i = 0; i < N; ++i)
		cin >> a[i];

	for(int i = 0; i < N; ++i)
	{
		int cur = 0;
		for(int j = 0; j < i; ++j)
			if(a[i] > a[j]) cur = max(cur, LS[j]); 
		
		LS[i] += cur;
		if(LS[i] > longest) longest = LS[i];
	}

	cout << longest << endl;

	string output;

	for(int i = N-1; i >= 0; --i)
	{
		if(LS[i] == longest)
		{
			output =  to_string(a[i]) + " " + output;
			--longest;
		}
	}

	cout << output << endl;

	return 0;
}