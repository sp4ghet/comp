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

const ll INF = 1e18;

int main()
{
    int n;
    cin >> n;
    vint a(n);
    rep(i, n) cin >> a[i];

    // if odd, you can have 2 spaces somewhere
    // if even you can have 1 space
    int k = 1 + n % 2;
    vvll dp(n + 1, vll(4, -INF));
    dp[0][0] = 0;

    rep(i, n) rep(j, k + 1)
    {
        // don't choose
        chmax(dp[i + 1][j + 1], dp[i][j]);

        // you need to choose one if
        // i odd, j odd:
        // e.g. i=3 j=1 then oxxo or xoxo are the possible states
        // in either case, you need to select a[i].
        // i even, j even:
        // e.g. i=2 j=0 then oxo
        // i=4 j=0 then oxoxo(x...)
        // i=4 j=2 then oxxxo
        // there are 3 selected from 5 in i=4 j=0
        // however, the final value is for dp[n][k] so it's ok
        // if k is 1 for even n, then dp[5][1] will be dp[4][0] or dp[4][1]

        if ((i + j) % 2 == 0)
            chmax(dp[i + 1][j], dp[i][j] + a[i]);
        else
            chmax(dp[i + 1][j], dp[i][j]);
    }
    cout << dp[n][k] << endl;

    return 0;
}