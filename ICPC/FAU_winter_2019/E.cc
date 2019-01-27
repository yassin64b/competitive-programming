#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    const vector<string> el{"H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne",
                            "Na", "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca",
                            "Sc", "Ti", "V",  "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
                            "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y",  "Zr",
                            "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
                            "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
                            "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
                            "Lu", "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg",
                            "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
                            "Pa", "U",  "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
                            "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
                            "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    vector<string> lel{"H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne",
                            "Na", "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca",
                            "Sc", "Ti", "V",  "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
                            "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y",  "Zr",
                            "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
                            "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
                            "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
                            "Lu", "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg",
                            "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
                            "Pa", "U",  "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
                            "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
                            "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    for (string &s : lel) {
        transform(begin(s), end(s), begin(s), ::tolower);
    }

    string s;
    cin >> s;
    const int n = s.size(), m = el.size();
    vector<int> dp(n + 1, -2);
    dp[0] = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int len = lel[j].size();
            if (dp[i] != -2 && i + len <= n && s.substr(i, len) == lel[j]) {
                dp[i + len] = j;
            }
        }
    }
    if (dp[n] == -2) {
        cout << "impossible\n";
    }

    vector<string> res;
    int i = n;
    while (dp[i] >= 0) {
        res.push_back(el[dp[i]]);
        i -= el[dp[i]].size();
    }
    reverse(begin(res), end(res));
    for (const string &s : res) {
        cout << s << " ";
    }
    cout << "\n";

    return 0;
}

