#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int64_t a;
    std::vector<double> v;
    
    while (std::cin >> a) {
        v.push_back(sqrt(a));
    }

    for (int i = v.size() - 1; i >= 0; --i) {
        std::cout.precision(17);
        std::cout << std::fixed << v[i] << std::endl;
    }
    
    return 0;
}