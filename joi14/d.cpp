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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    vector<int> c(m);
    rep(i, m) cin >> c[i];

    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, INT32_MAX));
    dp[0][0] = 0;
    rep(i, m) rep(j, n)
    {
        chmin(dp[i + 1][j], dp[i][j]);
        chmin(dp[i + 1][j + 1], dp[i][j + 1]);
        chmin(dp[i + 1][j + 1], dp[i][j] + c[i] * d[j]);
    }
    cout << dp[m][n] << endl;
    return 0;
}