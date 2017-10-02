#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<string, int> m{{"upper", 1}, {"middle", 2}, {"lower", 3}};

vector<int> split_string(const string& s, const char token = ',') {
	vector<int> res;
	size_t cur = 0, pos = s.find(token);
	while (true) {
		if (pos == string::npos) {
			string tmp = s.substr(cur);
			res.push_back(m[tmp]);
			break;
		} else {
			string tmp = s.substr(cur, pos - cur);
			res.push_back(m[tmp]);
			cur = pos + 1;
			pos = s.find(token, cur);
		}
	}
	return res;	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n;
		cin >> n;
		vector<pair<vector<int>, string>> v(n);
		int mx = 0;
		for (int i = 0; i < n; ++i) {
			string val, trash;
			cin >> v[i].second >> val >> trash;
			v[i].first = split_string(val, '-');
			mx = max(mx, (int)v[i].first.size());
			reverse(v[i].first.begin(), v[i].first.end());
		}
		for (int i = 0; i < n; ++i) {
			while ((int)v[i].first.size() < mx) {
				v[i].first.push_back(m["middle"]);
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; ++i) {
			cout << v[i].second.substr(0, v[i].second.size() - 1) << "\n";
		}
		cout << string(30, '=') << "\n";
	}

	return 0;
}