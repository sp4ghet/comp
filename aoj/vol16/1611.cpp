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

int calc(int l, int r, vector<vector<int>> &dp, vector<int> &w)
{
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    if (abs(l - r) <= 1)
    {
        return 0;
    }
    int res = 0;
    if (abs(w[l] - w[r - 1]) <= 1 && calc(l + 1, r - 1, dp, w) == r - l - 2)
    {
        res = r - l;
    }
    for (int mid = l + 1; mid <= r - 1; mid++)
    {
        res = max(res, calc(l, mid, dp, w) + calc(mid, r, dp, w));
    }
    return dp[l][r] = res;
}

int main()
{
    int n;

    cin >> n;
    while (n != 0)
    {
        vector<int> w(n);
        rep(i, n) cin >> w[i];
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        int ans = calc(0, n, dp, w);
        cout << ans << endl;

        cin >> n;
    }

    return 0;
}