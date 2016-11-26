#include <iostream>
#include <limits>
int main() {
    int a = 0, b = 0, n;
    std::cin >> n;
    //std::cin.ignore();
    char c;
    for (int i = 0; i < n; ++i) {
        std::cin >> c;
        if (c == 'A') 
            ++a;
        else
            ++b;
    }
    //std::cout << a << " " << b << std::endl;
    if (a > b)
        std::cout << "Anton" << std::endl;
    else if (a < b)
        std::cout << "Danik" << std::endl;
    else
        std::cout << "Friendship" << std::endl;

    //std::cout << std::numeric_limits<long long>::max() << std::endl;
    return 0;
}