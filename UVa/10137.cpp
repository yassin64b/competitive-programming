#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int N;

	while(cin >> N && N)
	{
		double sum = 0;
		vector<double> v(N);

		for(int i = 0; i < N; ++i)
		{
			cin >> v[i];
			sum += v[i];
		}	

		sum /= N;
		
		double res = 0, res2 = 0;
		for(int i = 0; i < N; ++i)
		{
			double tmp = int((v[i]-sum) * 100.0) / 100.0;
			if(tmp > 0)
				res += tmp;
			else
				res2 += tmp;
		}
		
		cout << fixed << setprecision(2) << "$" << max(abs(res),abs(res2)) << endl;
	}
}