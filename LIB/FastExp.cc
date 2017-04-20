constexpr int MOD = 1000*1000*1000 + 7;

int modPow(int a, int b, int c = MOD){
    long long x = 1, y = a;
    while (b > 0){
        if (b%2 == 1){
            x = (x*y) % c;
        }
        y = (y*y) % c;
        b /= 2;
    }
    return x % c;
}