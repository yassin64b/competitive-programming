#include <bits/stdc++.h>

using namespace std;
using f64 = long double;
constexpr f64 PI = 3.141592653589793238462643383279502884L;

class agc021_b {
private:
    f64 cross(pair<f64, f64> O, pair<f64, f64> A, pair<f64, f64> B) {
        return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
    }
    
    f64 dist(f64 x1, f64 y1, f64 x2, f64 y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        if (n == 2) {
            out << 0.5 << "\n" << 0.5 << "\n";
            return;
        }
        vector<pair<f64, f64>> xy(n), cxy;
        for (int i = 0; i < n; ++i) {
            in >> xy[i].first >> xy[i].second;
        }
        cxy = xy;

        int k = 0;
        vector<pair<f64, f64>> H(2*n);
        sort(xy.begin(), xy.end());
        for (int i = 0; i < n; ++i) {
            while (k >= 2 && cross(H[k-2], H[k-1], xy[i]) <= 0) k--;
            H[k++] = xy[i];
        }
        for (int i = n-2, t = k+1; i >= 0; i--) {
            while (k >= t && cross(H[k-2], H[k-1], xy[i]) <= 0) k--;
            H[k++] = xy[i];
        }
        H.resize(k-1);
        int m = H.size();
        vector<int> hull(m, -1);
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (cxy[i].first == H[j].first && cxy[i].second == H[j].second) {
                    hull[j] = i;
                    break;
                }
            }
        }
        
        vector<f64> res(n, 0.);
        f64 sum = 0.;
        for (int i = 0; i < m; i++) {
            assert(hull[i] != -1);
            f64 x1 = cxy[hull[i]].first, y1 = cxy[hull[i]].second;
            f64 x2 = cxy[hull[(i + 1) % m]].first, y2 = cxy[hull[(i + 1) % m]].second;
            f64 x3 = cxy[hull[(i - 1 + m) % m]].first, y3 = cxy[hull[(i - 1 + m) % m]].second;
            f64 b = dist(x1, y1, x2, y2);
            f64 a = dist(x1, y1, x3, y3);
            f64 c = dist(x2, y2, x3, y3);
            f64 tmp = (a * a + b * b - c * c) / (2. * a * b);
            f64 angle;
            if (tmp < -1.) angle = PI;
            else if (tmp > 1.) angle = 0.;
            else angle = acos(tmp);
            assert(!isnan(angle));
            angle = angle * 180. / PI;
            angle = 180. - angle;
            res[hull[i]] = angle;
            sum += angle;
        }
        for (int i = 0; i < n; ++i) {
            res[i] /= sum;
            out.precision(20);
            out << fixed << res[i] << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    agc021_b solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
