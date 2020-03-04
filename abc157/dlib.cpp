#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
template <typename T>
void view(const std::vector<T> &v)
{
    for (const auto &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}
template <typename T>
void view(const std::vector<std::vector<T>> &vv)
{
    for (const auto &v : vv)
    {
        view(v);
    }
}
#pragma endregion

struct UnionFind
{
    vector<int> d;
    // d[x] is the index of the parent of x
    // d[x] is -size if x is a root

    UnionFind(int n) : d(vector<int>(n, -1)) {}
    int root(int x)
    {
        if (d[x] < 0)
        {
            return x;
        }
        return d[x] = root(d[x]);
    }

    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
        {
            return false;
        }
        if (d[x] > d[y])
            swap(x, y); // x always bigger tree

        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
    int size(int x) { return -d[root(x)]; }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> g(n);
    UnionFind u(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a]++;
        g[b]++;
        u.unite(a, b);
    }
    vector<vector<int>> b(n, vector<int>());
    rep(i, k)
    {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        b[c].emplace_back(d);
        b[d].emplace_back(c);
    }

    rep(i, n)
    {
        int ans = u.size(i) - 1 - g[i];
        for (int bk : b[i])
        {
            if (u.same(bk, i))
                ans--;
        }

        cout << ans << " ";
    }

    cout << endl;

    return 0;
}