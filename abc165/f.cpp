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
#pragma region chminmax
template <typename T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

vint answer;
vint a;

void dfs(int v, int d, vint &dp, vvint &g, int p = -1)
{
    auto in = lower_bound(dp.begin(), dp.end(), a[v]);
    int prev = in[0];
    in[0] = a[v];

    int ans = d;
    while (dp[ans] != INT32_MAX)
    {
        ans++;
    }

    answer[v] = ans;
    for (auto nv : g[v])
    {
        if (nv == p)
            continue;
        dfs(nv, ans, dp, g, v);
    }
    in[0] = prev;
}

int main()
{
    int n;
    cin >> n;
    a = vint(n);
    rep(i, n) cin >> a[i];
    vvint g(n, vint());
    rep(i, n - 1)
    {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        g[f].emplace_back(t);
        g[t].emplace_back(f);
    }

    answer = vint(n);
    vint dp(n + 1, INT32_MAX);
    dfs(0, 0, dp, g);

    rep(i, n)
    {
        cout << answer[i] << endl;
    }

    return 0;
}