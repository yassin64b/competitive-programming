#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <cassert>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string type;
	unordered_map<string, int> m;
	map<int, string> minv;
	while (cin >> type) {
		if (type == "def") {
			string name;
			int val;
			cin >> name >> val;
			if (m.find(name) != m.end()) {
				minv.erase(m[name]);
			}
			m[name] = val;
			minv[val] = name;
		} else if (type == "calc") {
			string nxt, mem;
			int res = 0;
			bool unknown = false;
			while (cin >> nxt && nxt != "=") {
				mem += nxt;
				if (nxt == "+") {
					cin >> nxt;
					mem += " " + nxt + " ";
					if (m.find(nxt) == m.end()) {
						unknown = true;
					} else {
						res += m[nxt];
					}
				} else if (nxt == "-") {
					cin >> nxt;
					mem += " " + nxt + " ";
					if (m.find(nxt) == m.end()) {
						unknown = true;
					} else {
						res -= m[nxt];
					}
				} else {
					if (m.find(nxt) == m.end()) {
						unknown = true;
					} else {
						res = m[nxt];
					}
					mem += " ";
				}
			}
			mem += nxt;
			if (minv.find(res) == minv.end()) {
				unknown = true;
			}
			cout << mem;
			if (unknown) {
				cout << " unknown" << "\n";
			} else {
				cout << " " << minv[res] << "\n";
			}
		} else {
			assert(type == "clear");
			m.clear();
			minv.clear();
		}
	}

	return 0;
}
