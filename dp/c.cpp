#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, s, n) for (int i = s; i < n; ++i)
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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i] >> c[i];
        a[i]; b[i]; c[i];
    }

    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    rep(i, 1, n){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
    }

    int ans = max(dp[n-1][0], dp[n-1][1]);
    ans = max(ans, dp[n-1][2]);

    cout << ans << endl;

    return 0;
}
