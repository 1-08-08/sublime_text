/*
                        gp hash table
                example of policy based data structure.
                similar to unordered map but works faster than unordered map.
*/
#include<bits/stdc++.h>
using namespace std;

struct splitmix64 {
	size_t operator()(size_t x) const {
		static const size_t fixed = chrono::steady_clock::now().time_since_epoch().count();
		x += 0x9e3779b97f4a7c15 + fixed;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
};

int main() {

	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	auto start = std::chrono::high_resolution_clock::now();

	gp_hash_table<int, int, splitmix64> mp;
	ffor(i, 1, 10)
	mp[i] = i * i;

	for (auto & i : mp)
		cout << i.ff << " " << i.ss << "\n";

	cout << fixed << setprecision(8);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	cerr << "Time taken : " << ((double)duration.count()) / ((double) 1e9) << "s " << endl;


	return 0;
}