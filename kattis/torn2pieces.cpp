#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

void dfs(int u, int dest, const vector<vector<int>>& g, vector<int>& vis, vector<int>& res) {
	vis[u] = 1;
	if (u == dest) {
		res.push_back(u);
		return;
	}
	for (int v : g[u]) {
		if (!vis[v]) {
			dfs(v, dest, g, vis, res);
			if (!res.empty()) {
				res.push_back(u);
				return;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	unordered_map<string, int> sid;
	vector<string> sname;
	vector<vector<int>> g(N*N + 1);
	int id = 0;
	for (int i = 0; i < N; ++i) {
		string name, line, tmp;
		cin >> name;
		if (!sid[name]) {
			sid[name] = ++id;
			sname.push_back(name);
		}
		getline(cin, line);
		stringstream ss(line);
		while (ss >> tmp) {
			if (!sid[tmp]) {
				sid[tmp] = ++id;
				sname.push_back(tmp);
			}
			g[sid[name]].push_back(sid[tmp]);
			g[sid[tmp]].push_back(sid[name]);
		}
	}
	string start, dest;
	cin >> start >> dest;
	vector<int> vis(id + 1, 0), res;
	if (!sid[start]) {
		sid[start] = ++id;
		sname.push_back(start);
	}
	if (!sid[dest]) {
		sid[dest] = ++id;
		sname.push_back(dest);
	}
	dfs(sid[start], sid[dest], g, vis, res);
	if (res.empty()) {
		cout << "no route found\n";
	} else {
		reverse(res.begin(), res.end());
		for (int x : res) {
			cout << sname[x - 1] << " ";
		}
		cout << endl;
	}

	return 0;
}
