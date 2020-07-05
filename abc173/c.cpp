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

int main()
{
    int h, w, k;
    cin >> h >> w >> k;
    vvchar g(h, vchar(w));
    int blk = 0;
    rep(y, h) rep(x, w)
    {
        cin >> g[y][x];
        if (g[y][x] == '#')
            blk++;
    }
    int ans = 0;
    rep(yc, (1 << h)) rep(xc, (1 << w))
    {
        int now = blk;

        rep(y, h)
        {
            if (((1 << y) & yc) == 0)
                continue;
            rep(x, w)
            {
                if (g[y][x] == '#')
                {
                    now--;
                }
            }
        }

        rep(x, w)
        {
            if (((1 << x) & xc) == 0)
                continue;

            rep(y, h)
            {
                if (((1 << y) & yc))
                    continue;

                if (g[y][x] == '#')
                    now--;
            }
        }
        if (now == k)
        {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}