#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cassert>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> a(n);
	set<int> missing;
	for (int i = 1; i <= n; ++i) {
		missing.insert(i);
	}
	vector<int> freq(n + 1, 0), seenfreq(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++freq[a[i]];
		missing.erase(a[i]);
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (freq[a[i]] > 1 && *missing.begin() < a[i]) {
			++res;
			--freq[a[i]];
			a[i] = *missing.begin();
			missing.erase(missing.begin());
		} else if (freq[a[i]] > 1 && seenfreq[a[i]] >= 1) {
			assert(seenfreq[a[i]] == 1);
			++res;
			--freq[a[i]];
			a[i] = *missing.begin();
			missing.erase(missing.begin());
		}
		++seenfreq[a[i]];
	}
	cout << res << "\n";
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}