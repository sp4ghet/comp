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
    vector<int> c(m);
    rep(i, m) cin >> c[i];

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, n + 5));
    rep(i, n + 1) dp[0][i] = i;

    rep(i, m)
    {
        rep(j, n + 1)
        {
            // no use
            chmin(dp[i + 1][j], dp[i][j]);

            // use
            if (j - c[i] >= 0)
            {
                chmin(dp[i + 1][j], dp[i + 1][j - c[i]] + 1);
            }
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}