#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class RememberWords {
public:
    long long range_sum(long long a, long long b) {
    	if (a > b) {
        	swap(a, b);   
        }
        if (a == 0) {
            //cout << "    range " << a << "-" << b << ": " << b * (b + 1) / 2 << "   ";
            return b * (b + 1) / 2;
        }
        //cout << "    range " << a << "-" << b << ": " << b * (b + 1) / 2 - ((a - 1) * a / 2) << "     ";
        return b * (b + 1) / 2 - ((a - 1) * a / 2);
    }
    int can(long long first, int len, long long num) {
     	long long sum1 = range_sum(first, max(0LL, first - (len - 1)));
        long long sum2 = range_sum(first, first + len - 1);
        if (sum1 <= num && sum2 >= num) {
            return 0;
        } else if (sum1 > num) {
            return 1;
        }
        return -1;
    }
    string isPossible(int d1, int d2, int w1, int w2) {
        long long low = 0, high = w1 + w2;
        while (low <= high) {
       		long long mid = (low + high) / 2;
            //cout << "check: " << mid << "," << d1 << "," << w1 << " and " << mid << "," << d2 + 1 << "," << w2 + mid << endl;
           	int a = can(mid, d1, w1), b = can(mid, d2 + 1, w2 + mid);
            //cout << a << " " << b << endl;
            if (a == 0 && b == 0) {
             	return "Possible";    
            } else if (a >= 0 && b >= 0) {
             	high = mid - 1;   
            } else if (a <= 0 && b <= 0) {
             	low = mid + 1;   
            } else {
            	return "Impossible";    
            }
       	}
        return "Impossible";
    }
};