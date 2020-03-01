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

int INF = 2e5 + 5;
int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> dp(10, vector<int>(10, INF));
    rep(i, 10) rep(j, 10) cin >> dp[i][j];
    rep(k, 10) rep(i, 10) rep(j, 10)
    {
        chmin(dp[i][j], dp[i][k] + dp[k][j]);
    }

    int ans = 0;
    rep(i, h) rep(j, w)
    {
        int n;
        cin >> n;
        if (n < 0)
        {
            continue;
        }
        ans += dp[n][1];
    }
    cout << ans << endl;

    return 0;
}