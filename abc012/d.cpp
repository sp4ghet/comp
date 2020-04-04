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

#define INF 1LL << 50

int main()
{
    int n, m;
    cin >> n >> m;
    vvll dp(n, vll(n, INF));
    rep(i, m)
    {
        int f, t, c;
        cin >> f >> t >> c;
        f--;
        t--;
        dp[f][t] = c;
        dp[t][f] = c;
    }
    rep(i, n) dp[i][i] = 0;

    rep(k, n) rep(i, n) rep(j, n)
    {
        if (dp[i][k] == INF || dp[k][j] == INF)
            continue;

        chmin(dp[i][j], dp[i][k] + dp[k][j]);
    }

    ll ans = INF;
    rep(i, n)
    {
        ll now = max_element(dp[i].begin(), dp[i].end())[0];
        chmin(ans, now);
    }

    cout << ans << endl;

    return 0;
}