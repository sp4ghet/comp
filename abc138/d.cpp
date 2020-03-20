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

vector<ll> c;
vector<vector<int>> t;
vector<int> a;
vector<int> d;

void dfs(int v, int x, int dp, int p = -1)
{
    if (d[v] > 0 && d[v] < dp)
    {
        return;
    }
    d[v] = dp;
    x += a[v];
    c[v] += x;
    for (auto nv : t[v])
    {
        if (nv == p)
        {
            continue;
        }
        dfs(nv, x, dp + 1, v);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    t = vector<vector<int>>(n, vector<int>());
    c = vector<ll>(n, 0);
    d = vector<int>(n);

    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        t[a].emplace_back(b);
        t[b].emplace_back(a);
    }

    a = vector<int>(n, 0);
    rep(j, q)
    {
        int p, x;
        cin >> p >> x;
        p--;
        a[p] += x;
    }

    dfs(0, 0, 1);

    view(c);

    return 0;
}