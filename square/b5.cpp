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

struct circle
{
    double x, y, r;
    circle(double xx = 0, double yy = 0, double rr = 0) : x(xx), y(yy), r(yy) {}
};

double dist(double x1, double y1, double x2, double y2)
{
    double x3 = x2 - x1, y3 = y2 - y1;
    return sqrt(x3 * x3 + y3 * y3);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<circle> c(n + m);
    rep(i, n) cin >> c[i].x >> c[i].y >> c[i].r;
    rep(i, m) cin >> c[n + i].x >> c[n + i].y;

    double ans = 1e9;
    rep(i, n + m)
    {
        circle now = c[i];
        if (c[i].r > 0)
        {
            ans = min(c[i].r, ans);
            continue;
        }
        double minD = 1e9;
        rep(j, n + m)
        {
            if (i == j)
                continue;
            double d = dist(c[i].x, c[i].y, c[j].x, c[j].y);
            if (c[j].r != 0)
                d -= c[j].r;
            else
                d /= 2.0;
            minD = min(d, minD);
        }
        c[i].r = minD;
        ans = min(c[i].r, ans);
    }

    cout.precision(15);
    cout << fixed << ans << endl;

    return 0;
}