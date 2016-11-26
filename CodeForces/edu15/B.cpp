#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;

typedef long long int ll;

int main() 
{
	int N;
	cin >> N;
	unordered_map<ll, ll> m;
	for(int i = 0; i < N; ++i) 
	{
		ll t;
		cin >> t;
		m[t] += 1;
	}

	ll res = 0;
	for(auto& it: m) 
	{
		if(it.second == 0)
			continue;
		for(int k = 0; k < 31; ++k) 
		{
			ll p2 = (1 << k); 
			if(p2 < it.first) 
				continue; 
			ll aj = p2 - it.first;

			auto it2 = m.find(aj);
			if(it2 != m.end() && it2->second > 0)
			{
				if(*it2 == it)
					res += (it2->second) * (it2->second - 1) / 2;
				else
					res += (it2->second) * (it.second);
			}
		}
		it.second = 0;
	}

	cout << res << endl;
	return 0;
}	