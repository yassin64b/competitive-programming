#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <utility>
#include <sstream>

using namespace std;

typedef long long lli;
typedef pair<int,int> pii;

class BadNeighbors
{
public:
	int maxDonations(vector<int> don)
	{
		int N = (int) don.size();

		int ret = max(don[0], don[1]);
		if(N == 2) return ret;
		if(N == 3) return max(ret, don[2]);
		
		//dpf for 0 to N-2, dpl for 1 to N-1
		vector<int> dpf(N-1, 0), dpl(N-1,0);
		
		for(int i = 0; i < N-1; ++i)
			dpf[i] = don[i], dpl[i] = don[i+1];

		dpf[2] = dpf[0] + don[2];
		ret = max(ret, dpf[2]);

		dpl[2] = dpl[0] + don[2+1];
		ret = max(ret, dpl[2]);

		for(int i = 3; i < N-1; ++i)
		{
			dpf[i] = max(dpf[i-2], dpf[i-3]) + don[i];
			dpl[i] = max(dpl[i-2], dpl[i-3]) + don[i+1];

			//cout << i << " : " << dpf[i] << "-" << dpl[i] << endl;
			ret = max(ret, dpf[i]);
			ret = max(ret, dpl[i]);
		}

		return ret;
	}

};

int main()
{
	BadNeighbors b;

	cout << b.maxDonations({10,3,2,5,7,8}) << endl;
	cout << b.maxDonations(	{ 11, 15 }) << endl;
	cout << b.maxDonations({7, 7, 7, 7, 7, 7, 7}) << endl;
	cout << b.maxDonations({1, 2, 3, 4, 5, 1, 2, 3, 4, 5}) << endl;
	cout << b.maxDonations({94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
  			6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  			52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72}) << endl;
	cout << b.maxDonations({268, 265, 254, 470, 850, 746, 225, 541, 595, 773, 924, 112, 597, 413, 965, 222, 722, 287, 263, 326, 109, 4, 776, 458, 621, 34, 211, 982, 108, 295, 974, 978, 1, 677, 600, 671, 318, 779, 328, 358}) << endl;
}