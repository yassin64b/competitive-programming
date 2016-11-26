#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>

using namespace std;

struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() < second.size();
    }
};

int main() {
	ios::sync_with_stdio(false);
   
    int N, K;
    cin >> N >> K;

    vector<string> pws(N);
    for(int i = 0; i < N; ++i)
        cin >> pws[i];
	
    string pw;
    cin >> pw;

    compare c;
    sort(pws.begin(), pws.end(), c);

    int time = 0, time1 = 0, time2 = 0;
    bool found = false;
    for(int i = 0; i < N; ++i)
    {
        if(pws[i].size() > pw.size())
            break;

        if(i > 0 && i % K == 0)
            time2 += 5;
        if(!found && i > 0 && i % K == 0)
            time1 += 5;

        ++time2;
        if(!found)
            ++time1;
        
        if(pws[i].size() == pw.size())
        {
            found = true;
        }


    }

    cout << time1 << " " << time2 << endl;

	return 0;
}