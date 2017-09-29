#include <iostream>
#include <vector>
#include <utility>

using namespace std;

constexpr double carlen = 4.4;
constexpr int MAXT = 3 * 1000 * 1000;

int main() {
	int X1, X2;
	cin >> X1 >> X2;
	int N1;
	cin >> N1;
	vector<int> T1(N1);
	for (int i = 0; i < N1; ++i) {
		cin >> T1[i];
	}
	int N2;
	cin >> N2;
	vector<int> T2(N2);
	for (int i = 0; i < N2; ++i) {
		cin >> T2[i];
	}

	vector<pair<int, int>> pos(MAXT + 1);
	pos[0] = {X1, X2};

	for (int i = 1, speed = 0, j = 0; i <= MAXT; ++i) {
		if (j < N1 && i == T1[j]) {
			speed = 1 - speed;
			++j;
		}
		pos[i].first = pos[i - 1].first + speed;
	}
	for (int i = 1, speed = 0, j = 0; i <= MAXT; ++i) {
		if (j < N2 && i == T2[j]) {
			speed = 1 - speed;
			++j;
		}
		pos[i].second = pos[i - 1].second + speed;
	}
	
	if (X1 > X2) {
		for (int i = 1; i <= MAXT; ++i) {
			if (pos[i].second + carlen >= pos[i].first) {
				cout << "bumper tap at time " << i + 1 << "\n";
				return 0;
			}
		}
	} else {
		for (int i = 1; i <= MAXT; ++i) {
			if (pos[i].first + carlen >= pos[i].second) {
				cout << "bumper tap at time " << i + 1 << "\n";
				return 0;
			}
		}
	}
	cout << "safe and sound\n";
	return 0;
}