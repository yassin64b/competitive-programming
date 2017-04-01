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

class PingPongQueue {
public:
    vector <int> whoPlaysNext(vector <int>, int, int);
};

vector <int> PingPongQueue::whoPlaysNext(vector <int> skills, int N, int K) {
    int m = skills.size();
    queue<int> q;
    for (int i = 2; i < m; ++i) {
        q.push(i);
    }
    int cur_streak = 0, cur_streak_player = 0, cur1 = 0, cur2 = 1;
    for (int j = 0; j < K-1; ++j) {
        if (skills[cur1] > skills[cur2]) {
            if (cur_streak_player == cur1) {
                ++cur_streak;
            } else {
                cur_streak = 1;
            }
            cur_streak_player = cur1;
            q.push(cur2);
            cur2 = q.front();
            q.pop();
            if (cur_streak == N) {
                q.push(cur1);
                cur1 = q.front();
                q.pop();
                cur_streak = 0;
            }
        } else {
            if (cur_streak_player == cur2) {
                ++cur_streak;
            } else {
                cur_streak = 1;
            }
            cur_streak_player = cur2;
            q.push(cur1);
            cur1 = q.front();
            q.pop();
            if (cur_streak == N) {
                q.push(cur2);
                cur2 = q.front();
                q.pop();
                cur_streak = 0;
            }
        }
        cout << cur1+1 << " " << cur2+1 << endl;
    }
    return vector<int>{(skills[cur1] < skills[cur2] ? skills[cur1] : skills[cur2]), (skills[cur1] > skills[cur2] ? skills[cur1] : skills[cur2])};
}