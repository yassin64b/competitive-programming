#include <vector>
#include <algorithm>
using namespace std;

class Quorum
{
public:
	int count(vector<int> arr, int k)
	{
		sort(arr.begin(), arr.end());
		int res = 0;
		for(int i = 0; i < k; ++i)
			res += arr[i];
		return res;
	}
};