#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
const int mod = 1000000007;

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	int n, q;
	cin >> n >> q;
	vi v(n + 1), rs(q);
	ffor(i, 1, n + 1)
	cin >> v[i];

	int x = 0, y = (int)sqrt(n);
	vvi query;
	while (q--) {
		int left, right, block;
		cin >> left >> right;
		block = (left / y);
		query.pb({block, right, left, x++});
	}
	sort(all(query));

	int l = 0, r = 0, res = 0;
	for (auto &ve : query) {
		while (l > ve[2]) {
			l--;
			cnt[v[l]]++;
			// include l into your answer.
		}
		while (r < ve[1]) {
			r++;
			cnt[v[r]]++;
			// include r into your answer.
		}
		while (l < ve[2]) {
			cnt[v[l]]--;
			// remove l from your answer.
			l++;
		}
		while (r > ve[1]) {
			cnt[v[r]]--;
			// remove r from your answer.
			r--;
		}
		rs[ve[3]] = res;
	}

	for (auto &i : rs)
		cout << i << "\n";

	return 0;
}