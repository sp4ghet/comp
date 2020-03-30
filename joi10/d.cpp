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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(21));
    dp[0][a[0]] = 1;

    rep(i, n - 1)
    {
        rep(j, 21)
        {
            if (j - a[i + 1] >= 0)
            {
                dp[i + 1][j] += dp[i][j - a[i + 1]];
            }
            if (j + a[i + 1] < 21)
            {
                dp[i + 1][j] += dp[i][j + a[i + 1]];
            }
        }
    }

    cout << dp[n - 2][a[n - 1]] << endl;
    return 0;
}