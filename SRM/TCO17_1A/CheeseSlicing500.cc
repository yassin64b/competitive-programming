#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;

class CheeseSlicing {
public:
    int totalArea(int, int, int, int);
};

int CheeseSlicing::totalArea(int A, int B, int C, int S) {
    int dim[3]{A, B, C};
    if (A < S || B < S || C < S) {
        return 0;
    }
    int res = 0;
    if (A <= min(B, C)) {
        res = B*C;
    } else if (B <= min(A, C)) {
        res = A*C;
    } else {
        res = A*B;
    }
    queue<tuple<int,int,int>> q;
    q.emplace(A, B, C);
    while (!q.empty()) {
        tie(dim[0], dim[1], dim[2]) = q.front();
        sort(dim, dim+3);
        q.pop();
        for (int i = 0; i < 3; ++i) {
            if (dim[i] - S >= S) {
                int tmp = dim[1] * dim[2];
                res -= tmp;
                int nxt[3];
                for (int j = 0, ind = 1; j < 3; ++j) {
                    if (i != j) {
                        nxt[ind] = dim[j];
                        ++ind;
                    }
                }
                //cout << "make from " << dim[0] << " " << dim[1] << " " << dim[2] << endl;
                nxt[0] = S;
                res += nxt[1] * nxt[2];
                q.emplace(nxt[0], nxt[1], nxt[2]);
                //cout << nxt[0] << " " << nxt[1] << " " << nxt[2] << endl;
                nxt[0] = dim[i]-S;
                sort(nxt, nxt+3);
                res += nxt[1] * nxt[2];
                q.emplace(nxt[0], nxt[1], nxt[2]);
                //cout << nxt[0] << " " << nxt[1] << " " << nxt[2] << endl;
                break;
            }
        }
        
    }
    return res;
}