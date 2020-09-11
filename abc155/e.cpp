#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
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
using vvll = vector<vll>;
const ll INF = 1e12;
int main()
{
    string s;
    cin >> s;
    int n = s.size();

    vvll dp(n + 1, vll(2, INF));
    // pay just the right amount
    dp[0][0] = 0;
    // pay one extra
    dp[0][1] = 1;

    rep(i, n)
    {
        int x = s[i] - '0';
        // if you have no carriage, you need to pay the exact digit
        chmin(dp[i + 1][0], dp[i][0] + x);
        // if you want to create carriage, it takes one extra
        chmin(dp[i + 1][1], dp[i][0] + x + 1);
        // if you want to use carriage, you can do 10 - digit for free
        chmin(dp[i + 1][0], dp[i][1] + (10 - x));
        // if you want to keep carriage going, you can do 10-x and you get 1 less change here, so subtract that.
        chmin(dp[i + 1][1], dp[i][1] + (10 - x) - 1);
    }

    // the answer is how much you paid
    cout << dp[n][0] << endl;
    return 0;
}