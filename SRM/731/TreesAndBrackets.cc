#include <bits/stdc++.h>

using namespace std;

class TreesAndBrackets {
public:
    string check(string, string);
};

string TreesAndBrackets::check(string t1, string t2) {
    int n = t1.size(), m = t2.size();
    if (m > n) {
        return "Impossible";
    }
    stack<int> st;
    vector<int> match(n, -1);
    for (int i = 0; i < n; ++i) {
        if (t1[i] == '(') st.push(i);
        else {
            match[i] = st.top();
            match[st.top()] = i;
            st.pop();
        }
    }
    int j = 0;
    vector<int> cur;
    for (int i = 0; i < (int)t1.size(); ++i, ++j) {
        if (t1[i] != t2[j]) {
            while (!cur.empty() && cur.back() >= min(i, match[i])) --j, cur.pop_back();
            --j;
            i = max(i, match[i]);
        } else 
            cur.push_back(i);
    }
    if (j != (int)t2.size()) return "Impossible";
    
    return "Possible";
}