#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cassert>

using namespace std;

constexpr double INF = 1e18;

void dijkstra(int start, const vector<vector<pair<int, int>>>& g, 
		vector<double>& time, const vector<double>& police, double speed) {
    priority_queue<pair<double, int>> pq;
    pq.emplace(-0., start);
    time[start] = 0.;
    while (!pq.empty()) {
        double cur_t = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (!police.empty() && police[u] <= cur_t) {
            continue;
        }
        if (cur_t > time[u]) {
        	continue;
        }
        for (const pair<int, int>& p : g[u]) {
        	int v = p.first, dist = p.second;
            if (cur_t + dist / speed < time[v]) {
            	if (!police.empty() && police[v] <= cur_t + dist / speed) {
		            continue;
		        }
                pq.emplace(-(cur_t + dist / speed), v);
                time[v] = cur_t + dist / speed;
            }
        }
    }
}

int main() {
	int n, m, e;
	cin >> n >> m >> e;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; ++i) {
		int a, b, l;
		cin >> a >> b >> l;
		g[a - 1].emplace_back(b - 1, l);
		g[b - 1].emplace_back(a - 1, l);
	}
	vector<int> goals(e);
	for (int i = 0; i < e; ++i) {
		cin >> goals[i];
		--goals[i];
	}
	int b, p;
	cin >> b >> p;
	--b; --p;
	
	vector<double> police(n, INF);
	dijkstra(p, g, police, {}, 160.);

	double low = 0, high = 1e9, speed;
	bool possatall = false;
	for (int it = 0; it <= 10000; ++it) {
		speed = (low + high) / 2;
		vector<double> t(n, INF);
		dijkstra(b, g, t, police, speed);
		bool poss = false;
		for (int goal : goals) {
			if (t[goal] < INF) {
				assert(t[goal] < police[goal]);
				poss = true;
				break;
			}
		}
		if (poss) {
			possatall = true;
			high = speed;
		} else {
			low = speed;
		}
	}
	if (!possatall) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout.precision(17);
		cout << fixed << speed << "\n";
	}
	return 0;
}