/*
                             CYCLE DETECTION
                        Time Complexity : O(n+m)
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 100005;
vector<bool> visited(MAXN);
vector<vector<int>> adj(MAXN);
vector<int> color(MAXN), parent(MAXN);
int cycle_start, cycle_end;

bool cycle_detect_undirected_graph(int ch, int p) {
	visited[ch] = true;
	for (auto i : adj[ch]) {
		if (i != p) {
			if (visited[i]) {
				cycle_start = i;
				cycle_end = ch;
				return true;
			}
			parent[i] = ch;
			if (cycle_detect_undirected_graph(i, ch))
				return true;
		}
	}
	return false;
}

bool cycle_detect_directed_graph(int x) {
	color[x] = 1;
	for (auto i : adj[x]) {
		if (color[i] == 1) {
			cycle_start = i;
			cycle_end = ch;
			return true;
		}
		parent[i] = ch;
		if (color[i] == 0 && cycle_detect_directed_graph(i))
			return true;
	}
	color[x] = 2;
	return false;
}

int32_t main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // if undirected graph
	}

	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (!color[i] && cycle_detect_directed_graph(i)) {
			flag = true;
			break;
		}
	}

	if (!flag) {
		cout << "No cycle is present in the graph\n";
		return 0;
	}

	vector<int> cycle;
	cycle.push_back(cycle_start);
	while (cycle_end != cycle_start) {
		cycle.push_back(cycle_end);
		cycle_end = parent[cycle_end];
	}
	cycle.push_back(cycle_end);
	reverse(cycle.begin(), cycle.end());

	cout << (int)cycle.size() << "\n";
	for (auto i : cycle)
		cout << i << " ";
	cout << "\n";


	return 0;
}