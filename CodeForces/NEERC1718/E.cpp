#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	string rev;
	cin >> n >> rev >> m;
	vector<string> w(m);
	for (int i = 0; i < m; ++i) 
		cin >> w[i];
	int let[26] = {0};
	for (int i = 0; i < n; ++i) {
		let[rev[i] - 'a'] = 1;
	}
	set<int> res;
	for (int j = 0; j < 26; ++j) 
		res.insert(j);
	for (int i = 0; i < m; ++i) {
		bool poss = true;
		for (int j = 0; poss && j < n; ++j) {
			if (rev[j] != '*' && rev[j] != w[i][j]) 
				poss = false;
			if (rev[j] == '*' && let[w[i][j] - 'a']) 
				poss = false;
		}
		for (int j = 0; poss && j < 26; ++j) {
			if (!let[j] && w[i].find('a' + j) != string::npos) 
				continue;
			else 
				res.erase(j);	
		}
	}
	cout << res.size() << "\n";
}