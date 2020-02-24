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
    int t;
    cin >> t;
    vector<vector<int>> g(t, vector<int>(t));
    rep(i, t) rep(j, t) cin >> g[i][j];
    vector<int> dp(t + 2);
    int maxk = 0;
    rep(i, t + 1)
    {
        rep(j, i) for (int k = j; k < i; ++k)
        {
            chmax(maxk, j);
            chmax(dp[i + 1], dp[j]);
            chmax(dp[i + 1], dp[j] + g[j][k]);
        }
    }
    cout << maxk << endl;
    view(dp);

    cout << dp[t + 1] << endl;

    return 0;
}