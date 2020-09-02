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
#ifndef ONLINE_JUDGE
    for (const auto &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
#endif
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

int main()
{
    int h, w;
    cin >> h >> w;
    vvchar g(h, vchar(w));
    rep(y, h) rep(x, w) cin >> g[y][x];

    int ans = 0;
    rep(y, h) rep(x, w)
    {
        if (g[y][x] == '#')
            continue;
        if (ans == h + w - 1)
            break;
        int now = 0;
        for (int ry = y; ry <= h; ry++)
        {
            if (ry >= h || g[ry][x] == '#')
            {
                now += ry - y - 1;
                break;
            }
        }
        for (int ry = y; ry >= -1; ry--)
        {
            if (ry < 0 || g[ry][x] == '#')
            {
                now += y - ry - 1;
                break;
            }
        }
        for (int rx = x; rx <= w; rx++)
        {
            if (rx >= w || g[y][rx] == '#')
            {
                now += rx - x - 1;
                break;
            }
        }
        for (int rx = x; rx >= -1; rx--)
        {
            if (rx < 0 || g[y][rx] == '#')
            {
                now += x - rx - 1;
                break;
            }
        }
        ans = max(ans, now + 1);
    }

    cout << ans << endl;

    return 0;
}