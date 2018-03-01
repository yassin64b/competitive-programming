// C++11
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

class PrincessesAndMonsters {
private:
    const string _dir_str = "NSWEA";
    const int MX_DIR = 3;
    const vector<pair<int, int>> _dir_change{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};
    int _t, _S, _K;
    int _CLIQUE_SZ = 10;

    vector<pair<int, int>> _knights;
    vector<pair<int, int>> _princesses;
    vector<pair<int, int>> _monsters;
    vector<pair<int, int>> _corners;
    vector<vector<int>> _goto_princess;

    mt19937 _gen;
    uniform_int_distribution<int> _dis;

    int valid(int x, int y) {
        //cerr << x << "," << y << "->";
        if ((x == 0 || x == _S - 1) && (y == 0 || y == _S - 1)) {
            //cerr << 1 << endl;
            return 1; // exit
        } else if (x < 0 || x >= _S || y < 0 || y >= _S) {
            //cerr << 0 << endl;
            return 0; // off grid
        } 
        //cerr << 2 << endl;
        return 2; // ok
    }
    int valid(const pair<int, int> &p) {
        return valid(p.first, p.second);
    }
public:
    string initialize(int S, vector<int> princesses, vector<int> monsters, int K) {
        auto now = chrono::system_clock::now();
        auto now_ms = chrono::time_point_cast<chrono::milliseconds>(now);
        auto epoch = now_ms.time_since_epoch();
        auto value = chrono::duration_cast<chrono::milliseconds>(epoch);
        _gen = mt19937(value.count());
        _dis = uniform_int_distribution<int>(0, MX_DIR);

        _S = S;
        _t = _S * _S * _S;  
        _K = K;
        _knights.resize(_K);
        _goto_princess.resize(_K);
        _corners = {{0, 0}, {0, _S - 1}, {_S - 1, _S - 1}, {_S - 1, 0}};

        _princesses.resize(princesses.size() / 2);
        for (int i = 0; i < (int)_princesses.size(); ++i) {
            _princesses[i] = {princesses[2 * i], princesses[2 * i + 1]};
        }

        _monsters.resize(monsters.size() / 2);
        for (int i = 0; i < (int)_monsters.size(); ++i) {
            _monsters[i] = {monsters[2 * i], monsters[2 * i + 1]};
        }

        int num_m = _monsters.size();
        _CLIQUE_SZ = min(10, 5 + num_m * 5 * 5 / (_S * _S));
        //cerr << _CLIQUE_SZ << " " << num_m << endl;

        //uniform_int_distribution<int> init_dis(0, 3);
        string init_pos(_K, ' ');
        int corner_ind = 3;//, princess_ind = -1;
        for (int i = 0; i < _K; i += _CLIQUE_SZ) {
            corner_ind = (corner_ind + 1) % 4;
            //princess_ind = (princess_ind + 1) % _princesses.size();
            for (int j = i; j < i + _CLIQUE_SZ && j < _K; ++j) {
                assert(corner_ind >= 0 && corner_ind <= 3);
                init_pos[j] = corner_ind + '0';
                _knights[j] = _corners[corner_ind];
                assert(valid(_knights[j]));
                //_goto_princess[j] = princess_ind;
                //cerr << _knights[j].first << " " << _knights[j].second << endl;
            }
        }
        for (int k = 0; k < 10 * (int)_princesses.size(); ) {
            for (int i = 0; i < _K; i += _CLIQUE_SZ) {
                for (int j = i; j < i + _CLIQUE_SZ && j < _K; ++j) {
                    _goto_princess[j].push_back(k % _princesses.size());
                }
                ++k;
            }
        }

        return init_pos;
    }

    int goto_corner(const pair<int, int> &k_pos, int dist) {
        //cerr << "goto corner" << k_pos.first << "," << k_pos.second << "," << dist << endl;
        for (const auto &c_pos : _corners) {
            int a = c_pos.first - k_pos.first, b = c_pos.second - k_pos.second;
            //cerr << a << "," << b << ":";
            int cur_dist = abs(a) + abs(b);
            //cerr << cur_dist << ":";
            if (cur_dist <= dist) {
                if (abs(a) > abs(b)) {
                    //cerr << a << endl;
                    return (a > 0 ? 1 : 0);
                } else {
                    //cerr << b << endl;
                    return (b > 0 ? 3 : 2);
                }
            }
        }
        assert(false);
        return -1;
    }
    int goto_rand(const pair<int, int> &k_pos) {
        int dir_ind;
        bool ok = false;

        // check if it is valid and no exit
        do {
            ok = true;
            dir_ind = _dis(_gen);
            //cerr << "goto rand " << k_pos.first << "," << k_pos.second << endl;
            //cerr << "try " << dir_ind << endl;
            ok = (valid(k_pos.first + _dir_change[dir_ind].first,
                           k_pos.second + _dir_change[dir_ind].second) == 2);
        } while (!ok);
        return dir_ind;
    }
    int goto_princess(const pair<int, int> &k_pos, const pair<int, int> &p_pos) {
        int a = p_pos.first - k_pos.first, b = p_pos.second - k_pos.second;
        if (abs(a) > abs(b)) {
            return (a > 0 ? 1 : 0);
        } else {
            return (b > 0 ? 3 : 2);
        }
        if (a != 0 && b != 0) {
            if (_dis(_gen) % 2 == 0) {
                return (a > 0 ? 1 : 0);
            } else {
                return (b > 0 ? 3 : 2);
            }
        } else if (a != 0) {
            return (a > 0 ? 1 : 0);
        } else if (b != 0) {
            return (b > 0 ? 3 : 2);
        }
        assert(false);
        return -1;
    }

    string move(vector<int> status, int P, int M, int timeLeft) {
        --_t;
        //cerr << "time: " << _t << endl;
        string commands(_K, ' ');
        for (int i = 0; i < _K; i += _CLIQUE_SZ) {
            //cerr << "it: " << i << endl;
            bool all_dead = true;
            for (int j = i; all_dead && j < i + _CLIQUE_SZ && j < _K; ++j) {
                all_dead = (status[j] < 0);
            }
            if (all_dead) {
                continue;
            }
            int dist_corner = min(abs(_knights[i].first - 0), 
                                  abs(_knights[i].first - (_S - 1)))
                            + min(abs(_knights[i].second - 0),
                                  abs(_knights[i].second - (_S - 1)));
            if (dist_corner >= _t - 1 || (P == 0 && M == 0)) {
                //cerr << "goto closest corner " << dist_corner << endl;
                // go to closest corner
                int dir_ind = goto_corner(_knights[i], dist_corner);
                for (int j = i; j < i + _CLIQUE_SZ && j < _K; ++j) {
                    commands[j] = _dir_str[dir_ind];
                    _knights[j].first += _dir_change[dir_ind].first;
                    _knights[j].second += _dir_change[dir_ind].second;
                    assert(valid(_knights[j]));
                }
                continue;
            }
            bool have_princess = false;
            for (int j = i; j < i + _CLIQUE_SZ && j < _K; ++j) {
                if (status[j] > 0) {
                    have_princess = true;
                }    
            }
            if (!_goto_princess[i].empty()) {
                if (_knights[i].first == _princesses[_goto_princess[i].back()].first
                    && _knights[i].second == _princesses[_goto_princess[i].back()].second) 
                {
                    //cerr << "reached point princess" << endl;
                    for (int j = i; j < i + _CLIQUE_SZ && j < _K; ++j) {
                        _goto_princess[j].pop_back();
                    }
                }
            }
            if (have_princess) {
                /*for (int j = i; j < i + _CLIQUE_SZ && j < _K; ++j) {
                    _goto_princess[j] = -1;
                }*/
                //cerr << "have princess" << endl;
                // go to closest corner, when there, send only one knight to exit
                if (dist_corner == 1) {
                    //cerr << "send one" << endl;
                    int dir_ind1 = goto_corner(_knights[i], dist_corner);
                    int dir_ind2 = goto_rand(_knights[i]);
                    for (int j = i; j < i + _CLIQUE_SZ && j < _K; ++j) {
                        if (status[j] > 0) {
                            commands[j] = _dir_str[dir_ind1];
                        } else {
                            commands[j] = _dir_str[dir_ind2];
                        }
                        _knights[j].first += _dir_change[dir_ind2].first;
                        _knights[j].second += _dir_change[dir_ind2].second;
                        assert(valid(_knights[j])); 
                    }
                } else {
                    //cerr << "all" << endl;
                    int dir_ind = goto_corner(_knights[i], dist_corner);
                    //cerr << "goto -> " << _dir_str[dir_ind] << endl;
                    for (int j = i; j < i + _CLIQUE_SZ && j < _K; ++j) {
                        commands[j] = _dir_str[dir_ind];
                        _knights[j].first += _dir_change[dir_ind].first;
                        _knights[j].second += _dir_change[dir_ind].second;
                        assert(valid(_knights[j]));
                    }
                }
            } else if (!_goto_princess[i].empty()) {
                //cerr << "go princess" << endl;
                int dir_ind = goto_princess(_knights[i], _princesses[_goto_princess[i].back()]);
                for (int j = i; j < i + _CLIQUE_SZ && j < _K; ++j) {
                    commands[j] = _dir_str[dir_ind];    
                    _knights[j].first += _dir_change[dir_ind].first;
                    _knights[j].second += _dir_change[dir_ind].second;
                    assert(valid(_knights[j]));
                }
            } else {
                //cerr << "go rand" << endl;
                // go randomly
                int dir_ind = goto_rand(_knights[i]);
                for (int j = i; j < i + _CLIQUE_SZ && j < _K; ++j) {
                    commands[j] = _dir_str[dir_ind];    
                    _knights[j].first += _dir_change[dir_ind].first;
                    _knights[j].second += _dir_change[dir_ind].second;
                    assert(valid(_knights[j]));
                }
                //cerr << "finished" << endl;
            }
        }
        //cerr << commands << endl;
        return commands;
    }
};


// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < (int)v.size(); ++i)
        cin >> v[i];
}

int main() {
    PrincessesAndMonsters pam;

    int S, P, M, K;
    cin >> S >> P;
    vector<int> princesses(P);
    getVector(princesses);
    cin >> M;
    vector<int> monsters(M);
    getVector(monsters);
    cin >> K;
    
    string retInit = pam.initialize(S, princesses, monsters, K);
    cout << retInit << endl;
    cout.flush();

    for (int st = 0; ; ++st) {
        int nK;
        cin >> nK;
        vector<int> status(K);
        getVector(status);
        int nP, nM;
        cin >> nP >> nM;
        int timeLeft;
        cin >> timeLeft;

        string ret = pam.move(status, nP, nM, timeLeft);
        cout << ret << endl;
        cout.flush();
    }
}
