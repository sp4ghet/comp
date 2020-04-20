#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
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

const ll INF = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vint a(n);
    vp b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) b[i] = P(a[i], i);
    sort(b.rbegin(), b.rend());

    vvll dp(n + 1, vll(n + 1, -INF));
    dp[0][0] = 0;

    rep(i, n)
    {
        P now = b[i];
        rep(j, i + 1)
        {
            chmax(dp[i + 1][j + 1], dp[i][j] + now.first * abs(now.second - j));
            chmax(dp[i + 1][j], dp[i][j] + now.first * abs((n - i - 1 + j) - now.second));
        }
    }

    ll ans = 0;
    rep(i, n + 1)
    {
        chmax(ans, dp[n][i]);
    }

    cout << ans << endl;

    return 0;
}