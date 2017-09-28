#include <iostream>
#include <string>
#include <algorithm>

const std::string vowels = "aeiouy";

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	while (std::cin >> N && N) {
		std::string res;
		int best = -1;
		for (int i = 0; i < N; ++i) {
			std::string cur;
			int curres = 0;
			std::cin >> cur;
			for (int j = 0; j + 1 < (int)cur.size(); ++j) {
				if (cur[j] == cur[j + 1] && vowels.find(cur[j]) != std::string::npos) {
					++curres;
				}
			}
			if (curres > best) {
				best = curres;
				std::swap(res, cur);
			}
		}
		std::cout << res << "\n";
	}
}