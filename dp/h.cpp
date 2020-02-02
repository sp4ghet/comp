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
const ll p = 1e9 + 7;
struct mint
{
    ll x;
    mint(ll x = 0) : x(x % p) {}
    mint &operator+=(const mint a)
    {
        if ((x += a.x) >= p)
            x -= p;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((x += p - a.x) >= p)
            x -= p;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= p;
        return *this;
    }

    mint operator+(const mint a) const
    {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const
    {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const
    {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const
    {
        if (t == 0)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }

    mint inv() const
    {
        return pow(p - 2);
    }
    mint &operator/=(const mint a)
    {
        return (*this) *= a.inv();
    }
};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    rep(v, h)
    {
        rep(u, w)
        {
            cin >> grid[v][u];
        }
    }
    vector<vector<mint>> dp(h, vector<mint>(w));
    dp[0][0] = 1;
    rep(i, w)
    {
        if (grid[0][i] == '#')
            break;
        dp[0][i] = 1;
    }
    rep(i, h)
    {
        if (grid[i][0] == '#')
            break;
        dp[i][0] = 1;
    }

    for (int y = 1; y < h; ++y)
    {
        for (int x = 1; x < w; x++)
        {
            if (grid[y][x] == '#')
            {
                continue;
            }
            dp[y][x] += dp[y][x - 1];
            dp[y][x] += dp[y - 1][x];
        }
    }
    cout << dp[h - 1][w - 1].x << endl;

    return 0;
}