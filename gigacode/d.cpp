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

int solve(int h, int w, ll k, ll v, vvint &g)
{
    if (v < k)
        return 0;

    vvll c(h + 1, vll(w + 1));
    rep(y, h) rep(x, w) c[y + 1][x + 1] = c[y + 1][x] + c[y][x + 1] - c[y][x] + g[y][x];

    int res = 0;
    for (int yy = 1; yy <= h; yy++)
        for (int xx = 1; xx <= w; xx++)
        {
            int s = yy * xx;
            if (k * s > v)
                break;
            ll p = 1LL << 60;
            for (int y = 0; y <= h - yy; y++)
                for (int x = 0; x <= w - xx; x++)
                {
                    ll np = c[y + yy][x + xx] - c[y][x + xx] - c[y + yy][x] + c[y][x];
                    p = min(p, np);
                }

            if (v >= k * s + p)
                res = max(res, s);
        }

    return res;
}

int main()
{
    int h, w;
    ll k, v;
    cin >> h >> w >> k >> v;
    vvint g(h, vint(w));
    rep(y, h) rep(x, w) cin >> g[y][x];

    int ans = solve(h, w, k, v, g);

    cout << ans << endl;

    return 0;
}