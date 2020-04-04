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

int main()
{
    int n;
    cin >> n;
    vvll dp(n, vll(n));
    rep(i, n) rep(j, n) cin >> dp[i][j];

    vvll backup = dp;

    rep(k, n) rep(i, n) rep(j, n)
    {
        chmin(dp[i][j], dp[i][k] + dp[k][j]);
    }

    bool ok = true;
    rep(i, n) rep(j, n)
    {
        if (backup[i][j] != dp[i][j])
        {
            ok = false;
            break;
        }
    }

    if (!ok)
    {
        cout << -1 << endl;
        return 0;
    }

    rep(k, n) rep(i, n) rep(j, n)
    {
        if (i == j || i == k || j == k)
            continue;

        if (dp[i][j] == dp[i][k] + dp[k][j])
        {
            backup[i][j] = 0;
        }
    }
    ll ans = 0;
    rep(i, n) for (int j = i; j < n; j++)
    {
        ans += backup[i][j];
    }

    cout << ans << endl;

    return 0;
}