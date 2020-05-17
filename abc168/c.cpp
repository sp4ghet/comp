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
    const double pi = acos(-1);
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    double now = h * 60 + m;

    double angleA = fmod(now / (12.0 * 60), 1.0);
    angleA *= pi * 2.;
    double angleB = fmod(m / 60, 1.0);
    angleB *= pi * 2.;
    double ax = a * cos(angleA), ay = a * sin(angleA);
    double bx = b * cos(angleB), by = b * sin(angleB);
    double dx = (bx - ax), dy = (by - ay);
    dx *= dx;
    dy *= dy;

    double dist = sqrt(dx + dy);

    cout << fixed << setprecision(15) << dist << endl;

    return 0;
}