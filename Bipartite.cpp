#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 100005;

vector<int> col(MAXN);
vector<bool> vis(MAXN);
vector<vector<int>> adj(MAXN);

bool dfs_bipartite(int x, int cl) {
	vis[x] = true;
	col[x] = cl;
	for (auto i : adj[x]) {
		if (vis[i] && col[i] == cl)
			return false;
		if (!vis[i] && !dfs_bipartite(i, 3 - cl))
			return false;
	}
	return true;
}

bool is_bipartite(int x) {
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && !dfs_bipartite(i, 1))
			return false;
	}
	return true;
}

int32_t main()
{

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	auto start = std::chrono::high_resolution_clock::now();

	int n, m;
	cin >> n >> m;
	vvi adj(n + 1);
	ffor(i, 0, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	if (is_bipartite(n))
		cout << "Graph is bipartite\n";
	else
		cout << "Graph is not bipartite\n";

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	cerr << "Time taken : " << ((long double)duration.count()) / ((long double) 1e9) << "s " << endl;

	return 0;
}