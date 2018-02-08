// C++11
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <random>
#include <cassert>
#include <chrono>
//#include <cstdlib>

using namespace std;


class PointsOnTheCircle {
public:
    vector<int> permute(vector<int> matrix) {
        int N = (int)sqrt(matrix.size());
        if (N * N < (int)matrix.size()) {
            ++N;
        }
        vector<vector<int>> g(N);
        int mx_num_edges = 0, num_edges = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (matrix[i * N + j]) {
                    g[i].push_back(j);
                    ++num_edges;
                }
            }
            mx_num_edges = max(mx_num_edges, (int)g[i].size());
        }
        //num_edges /= 2;
        const int NUM_IT = 1000000000 / (N * N * mx_num_edges);

        //for random numbers
        auto now = chrono::system_clock::now();
        auto now_ms = chrono::time_point_cast<chrono::milliseconds>(now);
        auto epoch = now_ms.time_since_epoch();
        auto value = chrono::duration_cast<chrono::milliseconds>(epoch);
        mt19937 gen(value.count());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        //srand(457456);

        //for simulated annealing 
        vector<double> T(NUM_IT, 0);
        const double alpha = 0.95, beta = alpha / NUM_IT;
        T[0] = alpha;
        for (int i = 1; i < NUM_IT; ++i) {
            T[i] = T[i - 1] - beta;
        }

        const double deg = 2 * 3.14 / N;
        const double radius = 1.;
        vector<pair<double, double>> coords(N);
        for (int i = 0; i < N; ++i) { //calculate polygon vertex coordinates
            coords[i].first = radius * sin(deg * i);
            coords[i].second = radius * cos(deg * i);
        }
        vector<double> dist(N, 0.);
        for (int i = 1; i < N; ++i) { //calculate length of line between 0 and i
            double a = coords[i].first - coords[0].first;
            double b = coords[i].second - coords[0].second;
            dist[i] = sqrt(a * a + b * b);
        }

        vector<int> res(N, -1);
        vector<int> inv_res(N, -1);
        for (int w = 0; w < N; ++w) { //choose initial solution
            int ind = -1, mx_deg = -1, mx_real = -1;
            for (int j = 0; j < N; ++j) {
                if (inv_res[j] == -1) {
                    int cur_deg = 0, cur_real = 0;
                    for (int k : g[j]) {
                        cur_real += 1;
                        cur_deg += (inv_res[k] != -1);
                    }
                    if (cur_deg > mx_deg || (cur_deg == mx_deg && cur_real > mx_real)) {
                        mx_deg = cur_deg;
                        mx_real = cur_real;
                        ind = j;
                    }
                }
            }
            assert(ind != -1);      
            int i = -1;
            double best_dist = 1e18;
            for (int j = 0; j < N; ++j) {
                if (res[j] == -1) {
                    double cur_dist = 0;
                    for (int k : g[ind]) {
                        if (inv_res[k] != -1) {
                            int d = abs(j - inv_res[k]);
                            assert(d >= 0 && d < N);
                            cur_dist += dist[d];
                        }
                    }
                    if (cur_dist < best_dist) {
                        best_dist = cur_dist;
                        i = j;
                    }
                }
            }
            assert(i != -1);
            res[i] = ind;
            inv_res[ind] = i;
        }

        /*vector<int> res(N), inv_res(N);
        for (int i = 0; i < N; ++i) {
            res[i] = i;
        }
        random_shuffle(res.begin(), res.end());
        for (int i = 0; i < N; ++i) {
            inv_res[res[i]] = i;
        }*/

        vector<int> best_res(res);
        double best_score = 0;
        for (int i = 0; i < N; ++i) {
            for (int k : g[i]) {
                int d = abs(i - inv_res[k]);
                best_score += dist[d];
            }
        }
        double res_score = best_score;

        for (int w = 0; w < NUM_IT; ++w) { //iteratively improve
            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    double cur = 0;
                    for (int k : g[res[i]]) {
                        int d = abs(inv_res[res[i]] - inv_res[k]);
                        assert(d >= 0 && d < N);
                        cur += dist[d];
                    }
                    for (int k : g[res[j]]) {
                        int d = abs(inv_res[res[j]] - inv_res[k]);
                        assert(d >= 0 && d < N);
                        cur += dist[d];
                    }
                    swap(res[i], res[j]);
                    swap(inv_res[res[i]], inv_res[res[j]]);
                    double new_cur = 0;
                    for (int k : g[res[i]]) {
                        int d = abs(inv_res[res[i]] - inv_res[k]);
                        assert(d >= 0 && d < N);
                        new_cur += dist[d];
                    }
                    for (int k : g[res[j]]) {
                        int d = abs(inv_res[res[j]] - inv_res[k]);
                        assert(d >= 0 && d < N);
                        new_cur += dist[d];
                    }
                    if (new_cur < cur) {
                        res_score -= cur - new_cur;
                        //cout << "improv " << cur - new_cur << endl;
                    } else {
                        //double rand_num = (double)rand() / RAND_MAX;
                        double rand_num = dis(gen);
                        double prob = exp(-(new_cur - cur) / T[w]);
                        if (rand_num < prob) {
                            res_score -= cur - new_cur;
                            //cout << "improv prob " << cur - new_cur << endl;
                        } else {
                            swap(res[i], res[j]);
                            swap(inv_res[res[i]], inv_res[res[j]]);
                        }
                        
                    }
                    if (res_score < best_score) {
                        best_score = res_score;
                        best_res = res;
                    }
                }
            }
        }
        
        return best_res;
    }
};
// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < (int)v.size(); ++i)
        cin >> v[i];
}

int main() {
    PointsOnTheCircle pc;
    int M;
    cin >> M;
    vector<int> matrix(M);
    getVector(matrix);
    
    vector<int> ret = pc.permute(matrix);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}