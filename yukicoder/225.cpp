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
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT32_MAX));

    dp[0][0] = 0;
    rep(i, n)
    {
        rep(j, m)
        {
            if (s.at(i) != t.at(j))
            {
                chmin(dp[i + 1][j + 1], dp[i][j] + 1);
            }
            else
            {
                chmin(dp[i + 1][j + 1], dp[i][j]);
            }

            chmin(dp[i + 1][j], dp[i][j] + 1);
            chmin(dp[i][j + 1], dp[i][j] + 1);
            chmin(dp[i + 1][j + 1], dp[i + 1][j] + 1);
            chmin(dp[i + 1][j + 1], dp[i][j + 1] + 1);
        }
    }
    int ans = dp[n][m];

    cout << ans << endl;

    return 0;
}