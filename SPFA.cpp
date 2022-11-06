/*
                      SPFA (Shortest Path Faster Algorithm)
                         Average Time Complexity : O(m)
                          Worst Time Complexity : O(mn)
            It is used to find the shortest distance of every vertex from a given vertex.
            This algorithm can be used in place of Bellman Ford Algorithm and
                has better time complexity.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 2005;
vector<bool> inqueue;
vector<int> dst, par;
vector<vector<pair<int, int>>> adj;
int iter;

bool detect_cycle(int n)
{
	vector<int> vec;
	vector<bool> visited(MAXN), instack(MAXN);
	for (int i = 1; i <= n; i++)
		if (!visited[i])
		{
			for (int j = i; j != -1; j = par[j])
				if (!visited[j])
				{
					visited[j] = true;
					vec.push_back(j);
					instack[j] = true;
				}
				else
				{
					if (instack[j])
						return true;
					break;
				}
			for (int j : vec)
				instack[j] = false;
			vec.clear();
		}
	return false;
}


void SPFA(int x, int n) {

	dst = vector<int>(MAXN, INT_MAX);
	par = vector<int>(MAXN, -1);
	inqueue = vector<bool>(MAXN, false);
	iter = 0;

	queue<int> q;
	q.push(x);
	dst[x] = 0;
	inqueue[x] = true;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		inqueue[temp] = false;
		for (auto i : adj[temp]) {
			if (dst[i.first] > dst[temp] + i.second) {
				dst[i.first] = dst[temp] + i.second;
				par[i.first] = temp;
				iter++;
				if (iter == n) {
					if (detect_cycle(n)) {
						cout << "negative cycle is found\n";
						return ;
					}
					iter = 0;
				}
				if (!inqueue[i.first]) {
					q.push(i.first);
					inqueue[i.first] = true;
				}
			}
		}
	}

	if (detect_cycle(n)) {
		cout << "negative cycle is found\n";
		return ;
	}

	for (int i = 1; i <= n; i++)
		cout << dst[i] << " ";
	cout << "\n";

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
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}

	SPFA(1);

	return 0;
}