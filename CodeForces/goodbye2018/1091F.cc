#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<i64> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    string s;
    cin >> s;
    i64 t = 0;
    bool saw_grass = false, saw_water = false;
    // grass holds the amount of grass seen times two to avoid rounding issues
    i64 grass = 0, stamina = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'G') {
            t += 5 * l[i];
            stamina += l[i];
            saw_grass = true;
            grass += 2 * l[i];
        } else if (s[i] == 'W') {
            t += 3 * l[i];
            stamina += l[i];
            saw_water = true;
        } else {
            assert(s[i] == 'L');
            i64 need_stam = max(0LL, l[i] - stamina);
            if (need_stam > 0) {
                if (saw_water) {
                    t += 3 * need_stam;
                    stamina += need_stam;
                } else {
                    assert(saw_grass);
                    t += 5 * need_stam;
                    stamina += need_stam;
                }    
            }
            assert(stamina >= l[i]);
            t += l[i];
            stamina -= l[i];
        }
        grass = min(grass, stamina);
    }
    // convert grass (walk) to fly
    t -= 2 * grass;
    stamina -= grass;
    assert(stamina >= 0);
    // use rest of stamina to convert swim to fly
    t -= stamina;

    cout << t << "\n";

    return 0;
}