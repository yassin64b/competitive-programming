#include <iostream>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> v;
	v.push_back(vector<int>(n));
	for (int i = 0; i < n; ++i)
		cin >> v[0][i];
	set<int> s(v[0].begin(), v[0].end());
	int deg = 0;
	while (s.size() > 1U) {
		s.clear();
		++deg;
		v.push_back(vector<int>(n - deg));
		for (int i = 0; i < n - deg; ++i) 
			v[deg][i] = v[deg - 1][i + 1] - v[deg - 1][i];
		s = set<int>(v[deg].begin(), v[deg].end());
	}
	for (int i = deg - 1; i >= 0; --i) {
		v[i].push_back(v[i].back() + v[i + 1].back());
	}
	cout << deg << " " << v[0].back() << "\n";
}