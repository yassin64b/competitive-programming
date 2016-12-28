#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int K, T; 
	cin >> K >> T;

	vector<int> a(T);
	for(int i = 0; i < T; ++i)
		cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	if(T == 1)
	{
		cout << a[0]-1 << endl;
		return 0;
	}

	int ind1 = 0, ind2 = 1;
	while(ind1 != ind2)
	{
		while(ind1 < T && a[ind1] == 0) ++ind1;
		while(ind2 < T && (a[ind2] == 0 || ind2 == ind1)) ++ind2;
		if(ind1 == T || ind2 == T) break;
		--a[ind1];
		--a[ind2];
		//cout << ind1 << " " << ind2 << endl;
	}
	if(ind2 == T && ind1 < T)
		--a[ind1];
	int res = 0;
	for(int i = 0; i < T; ++i)
	{
		//cout << a[i] << " ";
		res += a[i];
	}
	//cout << endl;
	cout << res << endl;
	return 0;
}