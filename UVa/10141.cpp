#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N, P, num = 0;

	while(cin >> N >> P && N && P && ++num)
	{
		if(num > 1) cout << endl;

		cin.ignore(1);

		string best, cur, tmp;
		double d, bestd = -1;
		int R, maxR = -1;

		for(int n = 0; n < N; ++n)
			getline(cin, tmp);

		for(int p = 0; p < P; ++p)
		{
			getline(cin, cur);

			cin >> d >> R;
			cin.ignore(1);

			for(int r = 0; r < R; ++r)
			{
				getline(cin, tmp);
				if(R > maxR || (R == maxR && (d < bestd || bestd == -1)))
				{
					best = cur;
					maxR = R;
					bestd = d;
				}
			}			
		}
		cout << "RFP #" << num << endl << best << endl;

	}
}