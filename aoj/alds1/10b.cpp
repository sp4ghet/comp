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

vector<vector<ll>> dp;
ll INF = 1ll << 25;

vector<P> m;

ll rec(int l, int r)
{
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }

    if (abs(l - r) <= 1)
        return dp[l][r] = 0;

    ll res = 1 << 25;
    // e.g. A(BCD), (AB)(CD), (ABC)D where ABC-> A(BC) or (AB)C , etc.
    for (int i = l; i < r - 1; i++)
    {
        chmin(res, rec(l, i + 1) + rec(i + 1, r) + m[l].first * m[i].second * m[r - 1].second);
    }

    return dp[l][r] = res;
}

int main()
{
    int n;
    cin >> n;
    m = vector<P>(n);
    dp = vector<vector<ll>>(n, vector<ll>(n, -1));
    rep(i, n) cin >> m[i].first >> m[i].second;

    ll ans = rec(0, n);

    view(dp);

    cout << ans << endl;

    return 0;
}