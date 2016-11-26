#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
    int n, num = 0;
    cin >> n;
    int cnt[4] = {0};
    for(int i = 0; i < n; ++i)
    {
        int s;
        cin >> s;
        cnt[s-1]++;
    }
    num += cnt[3];
    //cout << num << endl;
    num += cnt[1]/2, cnt[1] -= (cnt[1]/2)*2;
    //cout << num << endl;
    int tmp = min(cnt[0],cnt[2]);
    num += tmp, cnt[0] -= tmp, cnt[2] -= tmp;
    //cout << num << endl;
    if(cnt[2] > 0)
    {
        num += cnt[2];
    }
    //cout << num << endl;
    if(cnt[0] > 0)
    {
        num += cnt[0]/4, cnt[0] = cnt[0]%4;
        if((cnt[0] || cnt[1]) && cnt[0] + cnt[1]*2 <= 4)
            ++num, cnt[1] = 0;
        else if(cnt[0] || cnt[1])
            num += 2, cnt[1] = 0;
    }
    //cout << num << endl;

    num += cnt[1];

    cout << num << endl;
}