#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vchar = vector<char>;
using vvchar = vector<vchar>;
using vp = vector<P>;
using vpp = vector<pair<P, P>>;
using vvp = vector<vp>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
istream &operator>>(istream &is, P &a)
{
    return is >> a.first >> a.second;
}
ostream &operator<<(ostream &os, const P &a) { return os << "(" << a.first << "," << a.second << ")"; }

template <typename T>

void view(const std::vector<T> &v)
{
#ifndef ONLINE_JUDGE
    for (const auto &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
#endif
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

void dfs(int v, vvp &g, vint &c)
{
    for (P p : g[v])
    {
        if (c[p.first] != -1)
            continue;
        int newc = !c[v];
        if (p.second % 2)
        {
            c[p.first] = newc;
        }
        else
        {
            c[p.first] = c[v];
        }
        dfs(p.first, g, c);
    }
}

int main()
{
    int n;
    cin >> n;
    vvp g(n);
    vint c(n, -1);
    rep(i, n - 1)
    {
        int f, t, w;
        cin >> f >> t >> w;
        g[f - 1].emplace_back(P(t - 1, w));
        g[t - 1].emplace_back(P(f - 1, w));
    }
    c[0] = 1;
    dfs(0, g, c);

    rep(i, n)
    {
        cout << c[i] << (i == n - 1 ? "" : "\n");
    }
    cout << endl;

    return 0;
}