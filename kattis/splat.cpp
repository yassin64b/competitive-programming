#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

constexpr double PI = 3.141592653589793238463;

struct color {
	double X, Y, V;
	double rad2;
	string name;
};

double dist2(double x1, double y1, double x2, double y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c;
	cin >> c;
	for (int t = 0; t < c; ++t) {
		int n;
		cin >> n;
		vector<color> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i].X >> v[i].Y >> v[i].V >> v[i].name;
			v[i].rad2 = v[i].V / PI;
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; ++i) {
			double X, Y;
			cin >> X >> Y;
			string color = "white";	
			for (int i = 0; i < n; ++i) {
				if (dist2(v[i].X, v[i].Y, X, Y) <= v[i].rad2) {
					color = v[i].name;
				}
			}
			cout << color << "\n";		
		}
	}
	return 0;
}