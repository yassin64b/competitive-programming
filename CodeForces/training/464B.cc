#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1'000'000'000;
constexpr double EPS = 1e-6;

using i64 = long long;

struct point {
    int x, y, z;
};

i64 dot(point a, point b) {
    return 1LL * a.x * b.x + 1LL * a.y * b.y + 1LL * a.z * b.z;
}

i64 norm(point a) {
    return dot(a, a);
}

double angle(point a, point b) {
    double rad_ang = acos(dot(a, b) / sqrt(norm(a)) / sqrt(norm(b)));
    return rad_ang * 180. / 3.141592653589793238463;
}

point diff(point a, point b) {
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}
double dist(point a, point b) {
    point d = diff(a, b);
    return sqrt(norm(d));
}

bool gen_perm(int i, int n, point p[]) {
    if (i == n) {
        double min_dist = INF;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = j1 + 1; j2 < n; ++j2) {
                min_dist = min(min_dist, dist(p[j1], p[j2]));
            }
        }
        for (int j1 = 0; j1 < n; ++j1) {
            vector<int> adj;
            for (int j2 = 0; j2 < n; ++j2) {
                double cur_dist = dist(p[j1], p[j2]);
                if (abs(min_dist - cur_dist) < EPS) {
                    adj.push_back(j2);
                }
            }
            if ((int)adj.size() != 3) {
                return false;
            } else {
                for (int k1 = 0; k1 < 3; ++k1) {
                    for (int k2 = k1 + 1; k2 < 3; ++k2) {
                        point d1 = diff(p[adj[k1]], p[j1]);
                        point d2 = diff(p[adj[k2]], p[j1]);
                        double ang = abs(angle(d1, d2));
                        if (abs(ang - 90.) > EPS) {
                            return false;
                        }
                    }
                }
            }
        }
        cout << "YES\n";
        for (int k = 0; k < n; ++k) {
            cout << p[k].x << " " << p[k].y << " " << p[k].z << "\n";
        }
        return true;
    }
    int tmp_p[]{p[i].x, p[i].y, p[i].z};
    sort(begin(tmp_p), end(tmp_p));
    do {
        p[i].x = tmp_p[0];
        p[i].y = tmp_p[1];
        p[i].z = tmp_p[2];
        if (gen_perm(i + 1, n, p)) {
            return true;
        }
    } while (next_permutation(begin(tmp_p), end(tmp_p)));
    return false;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    constexpr int n = 8;
    point p[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].z;
    }
    if (!gen_perm(1, n, p)) {
        cout << "NO\n";
    }
    return 0;
}