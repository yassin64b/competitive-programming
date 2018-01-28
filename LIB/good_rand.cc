//random_device is crap on windows minGW, don't use!

auto now = chrono::system_clock::now();
auto now_ms = chrono::time_point_cast<chrono::milliseconds>(now);
auto epoch = now_ms.time_since_epoch();
auto value = chrono::duration_cast<chrono::milliseconds>(epoch);
mt19937 gen(value.count());
uniform_int_distribution<int> dis(1, n);