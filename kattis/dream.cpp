#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <iterator>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<string> events;
	unordered_map<string, int> eind;
	for (int i = 0; i < n; ++i) {
		char type;
		cin >> type;
		if (type == 'E') {
			string e;
			cin >> e;
			eind[e] = events.size();
			events.push_back(e);
		} else if (type == 'D') {
			int r;
			cin >> r;
			for (int i = events.size() - r; i < (int)events.size(); ++i) {
				eind.erase(events[i]);
			}
			events.erase(events.end() - r, events.end());
		} else {
			int k;
			cin >> k;
			
			int dreamFrom = events.size();
			int noDreamTo = -1;
			for (int j = 0; j < k; ++j) {
				string e;
				cin >> e;
				if (e[0] == '!') {
					e = e.substr(1);
					if (eind.find(e) != eind.end()) {
						dreamFrom = min(dreamFrom, eind[e]);
					}
				} else {
					if (eind.find(e) == eind.end()) {
						noDreamTo = events.size();
					} else {
						noDreamTo = max(noDreamTo, eind[e]);
					}
				}
			}
			if (noDreamTo < dreamFrom) {
				if (dreamFrom == (int)events.size()) {
					cout << "Yes\n";
				} else {
					cout << events.size() - dreamFrom << " Just A Dream\n";
				}
			} else {
				cout << "Plot Error\n";
			}
		}
	}

	return 0;
}
