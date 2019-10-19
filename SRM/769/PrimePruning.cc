#include <bits/stdc++.h>

using namespace std;

class PrimePruning {
public:
    string maximize(int, int);
};

string PrimePruning::maximize(int N, int E) {
    vector<int> prime(400000 + 1, 1);
    vector<int> primes;
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= 400000; ++i) {
        if (prime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j <= 400000; j += i) {
                prime[j] = 0;
            }
        }
    }
    vector<int> cnt(26, 0);
    for (int i = 0; i < N && i < (int)primes.size(); ++i) {
       ++cnt[primes[i] % 26];
    }
    if (cnt[25] >= N - E) {
        return string(N - E, 'z');
    }
    string s;
    for (int i = 0; i < N && i < (int)primes.size(); ++i) {
       s += 'a' + primes[i] % 26;
    }
    for (int i = 0; i < (int)s.size() && (int)s.size() > N - E; ++i) {
        int j = i + 1;
        while (j < (int)s.size() && s[j] <= s[i]) {
            ++j;
        }
        if (j < (int)s.size()) {
            if ((int)s.size() - (j - i) >= N - E) {
                string t = s.substr(0, i) + s.substr(j);
                s = t;
                --i;
             } 
        }
    }
    return s.substr(0, N - E);
}