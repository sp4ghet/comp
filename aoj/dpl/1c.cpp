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
    int n, w;
    cin >> n >> w;
    vector<P> b(n);
    // v, w
    rep(i, n) cin >> b[i].first >> b[i].second;

    vector<vector<int>> dp(n + 1, vector<int>(w + 1));
    rep(i, n)
    {
        rep(j, w + 1)
        {
            if (j - b[i].second >= 0)
            {
                chmax(dp[i + 1][j], dp[i][j - b[i].second] + b[i].first);
                chmax(dp[i + 1][j], dp[i + 1][j - b[i].second] + b[i].first);
            }
            chmax(dp[i + 1][j], dp[i][j]);
        }
    }
    cout << dp[n][w] << endl;

    return 0;
}