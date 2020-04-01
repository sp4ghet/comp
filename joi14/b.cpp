// #define _GLIBCXX_DEBUG

#pragma region template
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma endregion
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

vector<vector<ll>> dp;
vector<int> a;
int n;

int f(int x)
{
    return (x + n) % n;
}

int main()
{
    cin >> n;
    a = vector<int>(n);

    rep(i, n) cin >> a[i];

    ll ans = 0;

    dp = vector<vector<ll>>(n + 1, vector<ll>(n + 1, -1));

    rep(i, n) dp[i][i] = a[i];

    for (int w = 1; w < n; w++)
    {
        for (int l = 0; l < n; l++)
        {
            int r = f(l + w - 1);
            // update with one more slice added
            int ll = f(l - 1), rr = f(r + 1);

            if (dp[l][r] == -1)
                continue;

            if (w % 2)
            {
                // IOI eats
                if (a[ll] > a[rr])
                {
                    // IOI ate the left cake, shift left back
                    chmax(dp[ll][r], dp[l][r]);
                }
                else
                {
                    chmax(dp[l][rr], dp[l][r]);
                }
            }
            else
            {
                // JOI(you) eat
                chmax(dp[ll][r], dp[l][r] + a[ll]);
                chmax(dp[l][rr], dp[l][r] + a[rr]);
            }
        }
    }

    rep(i, n)
    {
        int r = f(i + n - 1);
        chmax(ans, dp[i][r]);
    }

    cout << ans << endl;

    return 0;
}
