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
    vector<int> in;
    int n = 0;
    while (true)
    {
        int k;
        cin >> k;
        chmax(n, k);
        if (!k)
            break;
        in.emplace_back(k);
    }

    vector<int> dp(n + 5, 1e6);
    vector<int> dp2(n + 5, 1e6);
    dp[0] = 1;
    dp2[0] = 1;

    int h = 1;
    int i = 1;
    while (h <= n)
    {
        rep(j, n + 1)
        {
            chmin(dp[h], 1);

            if (j - h >= 0)
            {
                chmin(dp[j], dp[j - h] + 1);
            }

            if (h % 2 == 0)
            {
                continue;
            }

            chmin(dp2[h], 1);

            if (j - h >= 0)
            {
                chmin(dp2[j], dp2[j - h] + 1);
            }
        }

        i++;
        h = i * (i + 1) * (i + 2) / 6;
    }

    for (int k : in)
    {
        cout << dp[k] << " " << dp2[k] << endl;
    }

    return 0;
}