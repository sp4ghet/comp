#define _GLIBCXX_DEBUG

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

void sol(int n, vector<int> &w)
{
    vector<vector<int>> dp(n, vector<int>(n + 1));

    rep(i, n - 1)
    {
        if (abs(w[i] - w[i + 1]) < 2)
        {
            dp[i][i + 2] = 2;
        }
    }

    for (int h = 2; h <= n; h++)
    {
        for (int l = 0; l <= n - h; l++)
        {
            int r = l + h;
            if (dp[l + 1][r - 1] == r - l - 2 && abs(w[l] - w[r - 1]) < 2)
            {
                chmax(dp[l][r], 2 + dp[l + 1][r - 1]);
            }
            for (int m = l; m < r; m++)
            {
                chmax(dp[l][r], dp[l][m] + dp[m][r]);
            }
        }
    }

    cout << dp[0][n] << endl;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<int> w(n);
        rep(i, n) cin >> w[i];
        sol(n, w);
    }

    return 0;
}