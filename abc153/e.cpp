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

int main()
{
    int h, n;
    cin >> h >> n;
    vector<P> spell(n);
    rep(i, n) cin >> spell[i].first >> spell[i].second;
    vector<vector<int>> dp(n + 1, vector<int>(h + 1, INT32_MAX));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= h; ++j)
        {
            int d = j - spell[i].first;
            chmax(d, 0);

            chmin(dp[i][j], dp[i][d] + spell[i].second);
            chmin(dp[i + 1][j], dp[i][j]);
            chmin(dp[i + 1][j], dp[i][d] + spell[i].second);
        }
    }
    cout << dp[n][h] << endl;

    return 0;
}