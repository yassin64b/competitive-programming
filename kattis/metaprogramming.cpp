#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unordered_map<string, int> m;
	string com;
	while (cin >> com) {
		if (com == "define") {
			int val;
			string name;
			cin >> val >> name;
			m[name] = val;
		} else {
			string n1, n2;
			char op;
			cin >> n1 >> op >> n2;
			if (m.find(n1) == m.end() || m.find(n2) == m.end()) {
				cout << "undefined\n";
			} else {
				if (op == '<') {
					cout << (m[n1] < m[n2] ? "true" : "false") << "\n";
				} else if (op == '>') {
					cout << (m[n1] > m[n2] ? "true" : "false") << "\n";
				} else {
					cout << (m[n1] == m[n2] ? "true" : "false") << "\n";
				}
			}
		}
	}
	return 0;
}
