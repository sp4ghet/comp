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

const ll INF = 1e13;
int main()
{
    int n, m;
    cin >> n >> m;
    vvll dp(m + 1, vll(1 << n, INF));
    vp key(m);
    rep(i, m)
    {
        int a, b, x = 0;
        cin >> a >> b;
        rep(i, b)
        {
            int c;
            cin >> c;
            x |= 1 << (c - 1);
        }
        key[i] = P(a, x);
    }
    // for (P p : key)
    // {
    //     cout << p.first << " " << bitset<10>(p.second) << endl;
    // }

    dp[0][0] = 0;
    rep(i, m)
    {
        rep(j, 1 << n)
        {
            int now = j | key[i].second;
            chmin(dp[i + 1][j], dp[i][j]);
            chmin(dp[i + 1][now], dp[i][j] + key[i].first);
        }
    }
    ll ans = dp[m][(1 << n) - 1];

    if (ans == INF)
    {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}