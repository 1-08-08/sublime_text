
/*
                        Fenwick Tree/ Binary Indexed Tree
                          Time Complexity : O(logn)
                        Used for range sum/xor query and update
                    Used to find inversions in an array in O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<int> fw1d(MAXN);
vector<vector<int>> fw2d(MAXN, vector<int>(MAXN));

// 1D Fenwick Tree
void update_xor(int idx, int val, int n) {
    for (; idx <= n; idx += idx & -idx)
        fw1d[idx] ^= val;
}

int query(int idx) {
    int ret = 0;
    for (; idx > 0; idx -= idx & -idx)
        ret ^= fw1d[idx];
    return ret;
}

void update(int idx, int val, int n)
{
    for (; idx <= n; idx += idx & -idx)
        fw1d[idx] += val;
}

int query(int idx)
{
    int ret = 0;
    for (; idx > 0; idx -= idx & -idx)
        ret += fw1d[idx];
    return ret;
}

int count_inversion(vector<int> &v)
{
    int n = (int)v.size(), x = 0, prev = -1e9 - 5;
    vector<int> temp = v;
    sort(temp.begin(), temp.end());
    map<int, int> p;
    for (int i = 0; i < n; i++)
    {
        if (temp[i] > prev)
            x++;
        prev = temp[i], p[prev] = x;
    }
    int ret = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        update(p[v[i]], 1, n);
        ret += query(p[v[i]] - 1);
    }
    return ret;
}

// 2D Fenwick Tree

void update(int x, int y, int n, int m, int val) {
    for (int xx = x; xx <= n; xx += xx & -xx) {
        for (int yy = y; yy <= m; yy += yy & -yy)
            fw2d[xx][yy] += val;
    }
}

int query(int x, int y) {
    int ret = 0;
    for (int xx = x; xx > 0; xx -= xx & -xx) {
        for (int yy = y; yy > 0; yy -= yy & -yy)
            ret += fw2d[xx][yy];
    }
    return ret;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}