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

vector<vector<int>> g;
vector<int> d, f;

int dfs(int v, int t)
{
    if (f[v] != INT32_MAX)
    {
        return f[v];
    }
    if (d[v] != INT32_MAX && f[v] == INT32_MAX)
    {
        return t - 1;
    }

    d[v] = min(d[v], t);

    int tt = t + 1;
    for (auto to : g[v])
    {
        if (v == to)
            continue;
        tt = max(tt, dfs(to, tt) + 1);
    }
    f[v] = min(tt, f[v]);

    return tt;
}

int main()
{
    int n;
    cin >> n;
    g = vector<vector<int>>(n, vector<int>());
    d = vector<int>(n, INT32_MAX);
    f = vector<int>(n, INT32_MAX);

    rep(i, n)
    {
        int k;
        cin >> k >> k;
        rep(j, k)
        {
            int t;
            cin >> t;
            t--;
            g[i].emplace_back(t);
        }
    }

    int t = 1;
    rep(i, n)
    {
        if (f[i] == INT32_MAX)
        {
            t = dfs(i, t) + 1;
        }
    }

    rep(i, n)
    {
        cout << (i + 1) << " " << d[i] << " " << f[i] << endl;
    }

    return 0;
}