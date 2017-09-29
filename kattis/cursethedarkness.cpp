#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	int m;
	cin >> m;
	for (int t = 1; t <= m; ++t) {
		double X, Y;
		int n;
		cin >> X >> Y >> n;
		bool poss = false;
		for (int i = 0; i < n; ++i) {
			double a, b;
			cin >> a >> b;
			poss = poss || dist(X, Y, a, b) <= 8 * 8;
		}
		cout << (poss ? "light a candle\n" : "curse the darkness\n");
	}
	return 0;
}