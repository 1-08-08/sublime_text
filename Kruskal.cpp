/*
                                  Kruskal Algorithm
                             Time Complexity : O(mlogn)
        Spanning Tree : Tree formed from a graph after removing some of the edges.
        Minimum Spanning Tree : Spanning tree whose sum/product of edge weights is minimum.
        Maximum Spanning Tree : Spanning tree whose sum/product of edge weights is maximum.
    To obtain maximum spanning tree, multiply all the edge weights with -1 and apply any mst algorithm.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 100005;
vector<int> id(MAXN), rnk(MAXN);
vector<vector<int>> edges;

int find_set(int x)
{
    if (id[x] == x)
        return x;
    return id[x] = find_set(id[x]);
}

void union_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if (x == y)
        return;
    if (rnk[x] < rnk[y])
        swap(x, y);
    id[y] = x;
    rnk[x] += rnk[y];
}

void kruskal(int n)
{
    for (int i = 0; i <= n; i++)
        id[i] = i, rnk[i] = 1;

    int ret = 0, x, y;
    for (auto edge : edges)
    {
        x = find_set(edge[1]);
        y = find_set(edge[2]);
        if (x != y)
        {
            ret += edge[0];
            union_set(x, y);
        }
    }
    // cout<<ret<<"\n";
}

int main()
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
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());

    kruskal(n);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((long double)duration.count()) / ((long double) 1e9) << "s " << endl;

    return 0;
}