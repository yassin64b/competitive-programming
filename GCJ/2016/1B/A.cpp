#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>
#include <queue>
#include <string>

using namespace std;

bool check(vector<int>& cnt, string s)
{
	bool flag = true;
	vector<int> tmp(cnt);

	for(int i = 0; flag && i < (int)s.size(); ++i)
	{
		if(!tmp[s[i]-'A'])
			flag = false;

		--tmp[s[i]-'A'];
	}

	if(!flag) return false;

	for(int i = 0; flag && i < (int)s.size(); ++i)
	{
		--cnt[s[i]-'A'];
	}

	return true;
}	

int main()
{
	int T; 
	cin >> T;

	for(int t = 1; t <= T; ++t)
	{	
		string S;
		cin >> S;

		vector<int> cnt(26, 0);
		for(int i = 0; i < (int)S.size(); ++i)
			++cnt[S[i]-'A'];

		vector<int> num;


		while(check(cnt, "ZERO")) //unique Z
			num.push_back(0);
		while(check(cnt, "SIX")) //unique X
			num.push_back(6);
		while(check(cnt, "FOUR")) // unique U
			num.push_back(4);
		while(check(cnt, "FIVE")) //after check for 4 unique F
			num.push_back(5);
		while(check(cnt, "TWO")) // unique W
			num.push_back(2);
		while(check(cnt, "EIGHT")) //unique G
			num.push_back(8);
		while(check(cnt, "SEVEN")) //rest V
			num.push_back(7);
		while(check(cnt, "ONE")) //rest O
			num.push_back(1);
		while(check(cnt, "THREE")) //rest R
			num.push_back(3);
		while(check(cnt, "NINE")) //rest
			num.push_back(9);

		sort(num.begin(), num.end());

		cout << "Case #" << t << ": ";
		for(int& x: num)
			cout << x;
		cout << endl;
	}

	return 0;
}


