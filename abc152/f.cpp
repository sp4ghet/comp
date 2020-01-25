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

struct Edge
{
    int to, id;
    Edge(int to, int id) : to(to), id(id) {}
};

vector<Edge> tree[55];

vector<int> path;
bool dfs(int v, int tv, int p = -1)
{
    if (v == tv)
    {
        return true;
    }

    for (Edge e : tree[v])
    {
        if (e.to == p)
            continue;
        if (dfs(e.to, tv, v))
        {
            path.push_back(e.id);
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].emplace_back(Edge(b, i));
        tree[b].emplace_back(Edge(a, i));
    }
    cin >> m;
    vector<ll> eset(m);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        path = vector<int>();
        dfs(a, b);
        for (int e : path)
        {
            eset[i] |= 1ll << e;
        }
    }

    ll ans = 0;
    rep(i, 1 << m)
    {
        ll mask = 0;
        rep(j, m)
        {
            if (i >> j & 1)
            {
                mask |= eset[j];
            }
        }
        int whites = __builtin_popcountll(mask);
        ll count = 1ll << (n - 1 - whites);
        if (__builtin_popcountll(i) % 2 == 0)
        {
            ans += count;
        }
        else
        {
            ans -= count;
        }
    }

    cout << ans << endl;

    return 0;
}