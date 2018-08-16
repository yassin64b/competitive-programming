#include <bits/stdc++.h>

using namespace std;

class MinDegreeSubgraph {
public:
    string exists(long long, long long, long long);
};

string MinDegreeSubgraph::exists(long long n, long long m, long long k) {
    if (k * (k + 1) / 2 > m) {
        return "NONE";
    }
    // first part is for (k+1) clique
    // second part: remove at most (n - (k + 1)) nodes with at most k - 1 edges
    if (k * (k + 1) / 2 + (n - (k + 1)) * (k - 1) <= m) {
        return "ALL";
    }
    return "SOME";
}