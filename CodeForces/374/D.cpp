#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <functional>
using namespace std;

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const pair<long long, int>& lhs, const pair<long long, int>& rhs) const
  {
    return (abs(lhs.first) > abs(rhs.first));
  }
};

int main() {
	ios::sync_with_stdio(false);
   
    int n, k, x;
    cin >> n >> k >> x;

    vector<long long> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int ncnt = 0;
    for(int i = 0; i < n; ++i)
        ncnt += (a[i] < 0);

    /*vector<pair<long long, int>> v(n);
    for(int i = 0; i < n; ++i)
        v[i] = make_pair((a[i] < 0 ? -a[i] : a[i]), i);    
    sort(v.begin(), v.end());*/
    priority_queue< pair<long long, int>, vector<pair<long long, int>>, mycomparison > v;
    for(int i = 0; i < n; ++i)
        v.push(make_pair(a[i], i));

    for(int i = 0; i < k; ++i)
    {
        pair<long long, int> cur = v.top();
        v.pop();
        if(ncnt % 2 == 0)
        {
            if(cur.first < 0)
                cur.first += x;
            else
                cur.first -= x;
        }
        else
        {
            if(cur.first < 0)
                cur.first -= x;
            else
                cur.first += x;
        }
        //cout << cur.first << " " << cur.second << endl;
       
            if(a[cur.second] < 0 && cur.first >= 0)
                --ncnt;
            else if(a[cur.second] >= 0 && cur.first < 0)
                ++ncnt;
            a[cur.second] = cur.first;
            v.push(cur);
  
    }

    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
	return 0;
}