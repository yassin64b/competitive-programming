#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Robofactory {
public:
    int reveal(vector <int>, vector <string>);
};

int Robofactory::reveal(vector <int> query, vector <string> answer) {
    int n = query.size();
    vector<int> poss;
    poss.push_back(0);
    for (int i = 1; i < n; ++i) {
        if (answer[i] == "Odd" && query[i] % 2 == 0) {
            return i;
        } else if (answer[i] == "Even" && query[i] % 2 == 1) {
            return i;
        } else if (query[i-1] % 2 == 1) {
            //it would have lied, so can't be corrupted
        } else {
            poss.push_back(i);
        }
    }
    if (poss.size() == 1) {
        return poss[0];
    }
    return -1;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!