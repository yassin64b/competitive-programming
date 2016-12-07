#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    int num = 0;
    vector<int> cnts(2 * 26, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cnts[26 + s[i] - 'A']++;
        } else {
            cnts[s[i] - 'a']++;
        }
    }
    for (int i = 0; i < 2 * 26; ++i) {
        if (cnts[i] > 0) ++num;
    }
    //cout << num << endl;

    vector<int> cur(2 * 26, 0);
    int numOnes = 0, start = 0, res = n;
    for (int i = 0; i < n; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (cur[26 + s[i] - 'A'] == 0) {
                ++numOnes;
            }
            cur[26 + s[i] - 'A']++;
        } else {
            if (cur[s[i] - 'a'] == 0) {
                ++numOnes;
            }
            cur[s[i] - 'a']++;
        }
        while (start <= i && numOnes == num) {
            res = min(res, i - start + 1);
            if (s[start] >= 'A' && s[start] <= 'Z') {
                if (cur[26 + s[start] - 'A'] == 1) {
                    --numOnes;
                }
                cur[26 + s[start] - 'A']--;
            } else {
                if (cur[s[start] - 'a'] == 1) {
                    --numOnes;
                }
                cur[s[start] - 'a']--;
            }
            ++start;
        }
        //cout << start << " " << i << endl;
    }
    cout << res << endl;
    return 0;
}