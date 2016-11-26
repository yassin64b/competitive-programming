#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <utility>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	long long mor, mit, ab;
	cin >> mor >> mit >> ab;

	long long res;
	if(mor == max(mor, max(mit, ab)))
	{
		if(mor > ab)
		{
			if(mor > mit) //morgens abgereist
			{
				res = mor - mit + mor - ab - 2;
				//cout << 1 << endl;
			} 
			else //mittags
			{
				res = mor - mit + mor - ab - 1;
				//cout << 2 << endl;
			}
		} 
		else //abends
		{
			res = mor - mit + mor - ab;
			//cout << 3 << endl;
		}
	}
	else if(mit == max(mor, max(mit, ab)))
	{
		if(mit > mor) //mittags angekommen
		{
			if(mit > ab) //mittags abgereist
			{
				res = mit - mor + mit - ab - 2;
				//cout << 4 << endl;
			} 
			else //abends ab
			{
				res = mit - mor + mit - ab - 1;
				//cout << 5 << endl;
			}
		} 
		else //morgens angekommen
		{
			if(mit > ab) //mittags abgereist
			{
				res = mit - mor + mit - ab - 1;
				//cout << 6 << endl;
			} 
			else //abends ab
			{
				res = mit - mor + mit - ab;
				//cout << 7 << endl;
			}
		}
	}
	else
	{
		if(ab > mor)
		{
			if(ab > mit) 
			{
				res = ab - mor + ab - mit - 2;
				//cout << 8 << endl;
			} 
			else //mittags
			{
				res = ab - mor + ab - mit - 1;
				//cout << 9 << endl;
			}
		} 
		else //abends
		{
			res = ab - mor + ab - mit;
			//cout << 10 << endl;
		}
	}
	if(mor == ab && ab > mit)
	{
		res = min(res, mor - mit - 1);
	}
	cout << res << endl;
	return 0;
}