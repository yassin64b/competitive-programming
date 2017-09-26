#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class GraphAndPairs {
public:
    vector<int> construct(int d, int k) {
    	int node_id = 0;
        vector<int> res{0};
        
        if (d == 2) {
        	while (k > 0) {
                int first = node_id;
            	int sz = 0;
                while (sz <= k) {
                	res.push_back(++node_id);
                    res.push_back(first);
                    k -= sz;
                    ++sz;
                }
                ++node_id;
            }
            res[0] = node_id;
            return res;
        }
        
        if (k >= 100) {
        	int a = 100, b = k / 100;
            int first = node_id, last = node_id + d - 2;
            for (node_id = first; node_id < last; ++node_id) {
             	res.push_back(node_id); res.push_back(node_id + 1);   
            }
            for (int i = 0; i < a; ++i) {
            	res.push_back(++node_id); res.push_back(first);
            }
            for (int i = 0; i < b; ++i) {
             	res.push_back(++node_id); res.push_back(last);   
            }
            ++node_id;
            k -= a * b;
        }
        if (k >= 10) {
        	int a = 10, b = k / 10;
            int first = node_id, last = node_id + d - 2;
            for (node_id = first; node_id < last; ++node_id) {
             	res.push_back(node_id); res.push_back(node_id + 1);   
            }
            for (int i = 0; i < a; ++i) {
            	res.push_back(++node_id); res.push_back(first);
            }
            for (int i = 0; i < b; ++i) {
             	res.push_back(++node_id); res.push_back(last);   
            }
            ++node_id;
            k -= a * b;
        }
        if (k >= 1) {
        	int a = 1, b = k / 1;
            int first = node_id, last = node_id + d - 2;
            for (node_id = first; node_id < last; ++node_id) {
             	res.push_back(node_id); res.push_back(node_id + 1);   
            }
            for (int i = 0; i < a; ++i) {
            	res.push_back(++node_id); res.push_back(first);
            }
            for (int i = 0; i < b; ++i) {
             	res.push_back(++node_id); res.push_back(last);   
            }
            ++node_id;
            k -= a * b;
        }
        res[0] = node_id;
        return res;
    }
};