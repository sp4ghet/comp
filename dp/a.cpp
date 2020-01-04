#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }

    vector<int> dp(n, 10e5);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < n; i++)
    {
        rep(j, 2)
        {
            int idx = i - (j + 1);
            int cost = dp[idx] + abs(h[i] - h[idx]);
            chmin(dp[i], cost);
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}