#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vchar = vector<char>;
using vvchar = vector<vchar>;
using vp = vector<P>;
using vpp = vector<pair<P, P>>;
using vvp = vector<vp>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
istream &operator>>(istream &is, P &a)
{
    return is >> a.first >> a.second;
}
ostream &operator<<(ostream &os, const P &a) { return os << "(" << a.first << "," << a.second << ")"; }

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
    int n, l;
    cin >> n >> l;
    vvint dp(l + 5, vint(2, INT32_MAX));
    dp[0][0] = 0;
    vint h(l + 5);
    rep(i, n)
    {
        int a;
        cin >> a;
        h[a] = 1;
    }
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;

    rep(i, l)
    {
        if (h[i + 1])
        {
            chmin(dp[i + 1][0], dp[i][0] + t3 + t1);
        }
        else
        {
            chmin(dp[i + 1][0], dp[i][0] + t1);
        }
        if (h[i + 2])
        {
            chmin(dp[i + 2][0], dp[i][0] + t1 + t2 + t3);
        }
        else
        {
            chmin(dp[i + 2][0], dp[i][0] + t1 + t2);
        }
        chmin(dp[i + 1][1], dp[i][0] + t1 / 2 + t2 / 2);
        if (h[i + 4])
        {
            chmin(dp[i + 4][0], dp[i][0] + t1 + t2 * 3 + t3);
        }
        else
        {
            chmin(dp[i + 4][0], dp[i][0] + t1 + t2 * 3);
        }
        chmin(dp[i + 1][1], dp[i][0] + t1 / 2 + t2 / 2);
        chmin(dp[i + 2][1], dp[i][0] + t1 / 2 + t2 + t2 / 2);
        chmin(dp[i + 3][1], dp[i][0] + t1 / 2 + t2 * 2 + t2 / 2);

        chmin(dp[i + 1][1], dp[i + 1][0]);
    }

    // view(dp);
    cout << dp[l][1] << endl;

    return 0;
}