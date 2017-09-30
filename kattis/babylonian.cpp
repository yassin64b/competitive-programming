n#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> split_string(const string& s, const char token = ',') {
	vector<int> res;
	size_t cur = 0, pos = s.find(token);
	while (true) {
		if (pos == string::npos) {
			string tmp = s.substr(cur);
			if (tmp == "") {
				tmp = "0";
			}
			res.push_back(stoi(tmp));
			break;
		} else {
			string tmp = s.substr(cur, pos - cur);
			if (tmp == "") {
				tmp = "0";
			}
			res.push_back(stoi(tmp));
			cur = pos + 1;
			pos = s.find(token, cur);
		}
	}
	return res;	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int t = 0; t < N; ++t) {
		string S;
		cin >> S;
		vector<int> v(split_string(S));
		long long res = 0, mult = 1;
		for (int i = v.size() - 1; i >= 0; --i) {
			res += v[i] * mult;
			mult *= 60;
		}
		cout << res << "\n";
	}
	return 0;
}
