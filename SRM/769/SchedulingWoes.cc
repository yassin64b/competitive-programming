#include <bits/stdc++.h>

using namespace std;

class SchedulingWoes {
public:
    int study(int, int, vector <int>, int, vector <int>, int);
};

int SchedulingWoes::study(int N, int seed, vector <int> D, int maxD, vector <int> T, int factor) {
    vector<int> random(2 * N);
    random[0] = seed;
    for (int i = 1; i < 2 * N; ++i)
        random[i] = (1LL * random[i - 1] * 1103515245 + 12345) % (1LL << 31);
    for (int i = D.size(); i < N; ++i) {
        D.push_back(1 + (random[2 * i] % maxD));
        int maxT = max(1, D[i] / factor);
        T.push_back(1 + (random[2 * i + 1] % maxT));
    }
    vector<pair<int, int>> dt(N);
    for (int i = 0; i < N; ++i) dt[i] = {D[i], T[i]};
    sort(begin(dt), end(dt));
    priority_queue<int> pq;
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        pq.emplace(dt[i].second);
        sum += dt[i].second;
        while (sum > dt[i].first) {
            sum -= pq.top();
            pq.pop();
        }
    }
    return pq.size();
}