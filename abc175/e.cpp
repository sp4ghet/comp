#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using vint = vector<int>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vchar = vector<char>;
using vvchar = vector<vchar>;
using vp = vector<P>;
using vpp = vector<pair<P, P>>;
using vvp = vector<vp>;

istream &operator>>(istream &is, P &a)
{
    return is >> a.first >> a.second;
}
ostream &operator<<(ostream &os, const P &a) { return os << "(" << a.first << "," << a.second << ")"; }

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

ll dp[3005][3005][5];

int main()
{
    int r, c, k;
    cin >> r >> c >> k;

    vvint g(r, vint(c));
    rep(i, k)
    {
        int y, x, v;
        cin >> y >> x >> v;
        g[y - 1][x - 1] = v;
    }

    rep(y, r) rep(x, c) rep(i, 4)
    {
        // carry over to the right
        chmax(dp[y][x + 1][i], dp[y][x][i]);
        // take the one we're looking at
        //  came from above
        chmax(dp[y][x + 1][i + 1], dp[y][x + 1][0] + g[y][x]);
        //  came from left
        chmax(dp[y][x + 1][i + 1], dp[y][x][i] + g[y][x]);
        // move down
        chmax(dp[y + 1][x + 1][0], dp[y][x + 1][i]);
    }

    // view(g);
    // rep(y, r + 2)
    // {
    //     rep(x, c + 2)
    //     {
    //         cout << "[";
    //         rep(i, 4)
    //         {
    //             cout << dp[y][x][i] << " ";
    //         }
    //         cout << "]";
    //     }
    //     cout << endl;
    // }

    cout << dp[r][c][0] << endl;

    return 0;
}