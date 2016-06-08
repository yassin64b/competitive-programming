#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, A;
	cin >> N >> A;

	vector<int> v(N);
	for(int i = 0; i < N; ++i)
		cin >> v[i];

	int res = v[--A];

	for(int i = 1; i < N; ++i)
	{
		int posl = A - i, posr = A + i;
		//cout << posl << " " << posr << '\t';
		if(posl >= 0 && !(posr < N))
		{
			//cout << "1";
			res += v[posl];
		}
		else if(!(posl >= 0) && posr < N)
		{
			//cout << "2";
			res += v[posr];
		}
		else if(posl >= 0 && posr < N && v[posl] && v[posr])
		{
			//cout << "3";
			res += 2;
		}
		//cout << '\t' << i << ": " << res << endl;
	}

	cout << res << endl;
}
