#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct runner {
	string name;
	double a, b;
};

int main() {
    int n;
    cin >> n;
    vector<runner> v(n);
    for (int i = 0; i < n; ++i) {
    	cin >> v[i].name >> v[i].a >> v[i].b;
    }
    vector<runner> v2(v);
    sort(v.begin(), v.end(), [](const runner& lhs, const runner& rhs) {
    	return lhs.a < rhs.a;
    });
    sort(v2.begin(), v2.end(), [](const runner& lhs, const runner& rhs) {
    	return lhs.b < rhs.b;
    });
    double res = 1e9;
    for (int i = 0; i < 4; ++i) {
    	double time = v[i].a;
    	int num = 3;
    	for (int j = 0; j < num; ++j) {
    		if (v2[j].name == v[i].name) {
    			++num;
    		} else {
    			time += v2[j].b;
    		}
    	}
    	res = min(res, time);
    }
    for (int i = 0; i < 4; ++i) {
    	double time = v[i].a;
    	int num = 3;
    	for (int j = 0; j < num; ++j) {
    		if (v2[j].name == v[i].name) {
    			++num;
    		} else {
    			time += v2[j].b;
    		}
    	}
    	if (abs(time - res) < 1e-9) {
    		cout.precision(2);
    		cout << fixed << time << "\n";
    		cout << v[i].name << "\n";
    		int num = 3;
	    	for (int j = 0; j < num; ++j) {
	    		if (v2[j].name == v[i].name) {
	    			++num;
	    		} else {
	    			cout << v2[j].name << "\n";
	    		}
	    	}
            return 0;
    	}
    }
}