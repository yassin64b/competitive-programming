#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);

	int n, a, b, k;
	string shots;
	cin >> n >> a >> b >> k >> shots;

	vector<int> res;
	int cnt = 0, ind = -1;
	for (int i = 0; i < n; ++i) {
		if (shots[i] == '0') {
			++cnt;
			if (cnt == b) {
				if (a > 0) {
					ind = i;
					--a;
					cnt = 0;
				} else {
					cnt = 0;
					res.push_back(i+1);
				}
			}
		} else {
			cnt = 0;
		}
	}
	cout << res.size()+1 << endl;
	for (auto &x: res) {
		cout << x << " ";
	}
	cout << ind+1 << endl;
	//cout << shots << endl;
    return 0;
}