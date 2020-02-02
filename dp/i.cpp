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
    int n;
    cin >> n;
    int half = (n + 1) / 2;
    vector<double> p(n);
    rep(i, n) cin >> p[i];

    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    dp[0][0] = 1.;
    rep(i, n)
    {
        rep(j, i + 1)
        {
            dp[i + 1][j + 1] += dp[i][j] * p[i];
            dp[i + 1][j] += dp[i][j] * (1. - p[i]);
        }
    }

    double res = 0.;
    for (int k = half; k <= n; k++)
    {
        res += dp[n][k];
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}