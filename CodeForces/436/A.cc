#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int num1 = a[0], cnt1 = 0;
	int num2 = -1, cnt2 = 0;
	for (int i = 0; i < n; ++i) {
		cnt1 += (a[i] == num1);
		if (a[i] != num1) {
			num2 = a[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		cnt2 += (a[i] == num2);
	}
	if (cnt1 == cnt2 && cnt1 == n / 2) {
		 cout << "YES\n";
		 cout << num1 << " " << num2 << "\n";
	} else {
		cout << "NO\n";
	}
}