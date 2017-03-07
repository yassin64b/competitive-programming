/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin
 */

#include <fstream>

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <queue>
#include <functional>
#include <stack>
#include <cassert>

using namespace std;

class B {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        
        for (int t = 1; t <= T; ++t) {
            string s1, s2;
            in >> s1 >> s2;
            int n = s1.size(), m = s2.size();
            
            //dp[i][j] = 1 if can match s1[0..i-1] and s2[0..j-1]
            vector<vector<int>> dp(n+1+5, vector<int>(m+1+5, 0));
            dp[0][0] = 1;
            for (int i = 1; s1[i-1] == '*' && i <= n; ++i) {
                dp[i][0] = 1;
            }
            for (int j = 1; s2[j-1] == '*' && j <= m; ++j) {
                dp[0][j] = 1;
            }
            
            
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (s1[i-1] == s2[j-1]) {
                        dp[i][j] += dp[i-1][j-1] >= 1;
                    }
                    if (s1[i-1] == '*') {
                        int add = 0;
                        for (int x = 0; x <= 4; ++x) {
                            while (j+x-1+add < m && s2[j+x-1+add] == '*') dp[i][j+x-1+add] += dp[i-1][j-1], ++add;
                            dp[i][j+x-1+add] += dp[i-1][j-1] + dp[i-1][j] >= 1;
                        }
                    }
                    if (s2[j-1] == '*') {
                        int add = 0;
                        for (int x = 0; x <= 4; ++x) {
                            while (i+x-1+add < n && s1[i+x-1+add] == '*') dp[i+x-1+add][j] += dp[i-1][j-1], ++add;
                            dp[i+x-1+add][j] += dp[i-1][j-1] + dp[i][j-1] >= 1;
                        }
                    }
                    
                }
            }
            
            /*cout << "Case: " << t << endl;
            for (int i = -1; i <= m; ++i) {
                cout << (i > 0 ? s2[i-1] : ' ') << " ";
            }
            cout << endl;
            for (int i = 0; i <= n; ++i) {
                cout << (i > 0 ? s1[i-1] : ' ') << " ";
                for (int j = 0; j <= m; ++j) {
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;*/
            
            out << "Case #" << t << ": ";
            if (dp[n][m]) {
                out << "TRUE\n";
            } else {
                out << "FALSE\n";
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    B solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}