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

int area(P rect)
{
    return rect.first * rect.second;
}
using PP = pair<P, P>;
PP split(vp &c, int p, int r)
{
    int h = c[p].first, w = c[p].second;
    r %= h + w;
    P a, b;
    if (r > h)
    {
        r -= h;
        a = P(h, r);
        b = P(h, w - r);
    }
    else
    {
        a = P(r, w);
        b = P(h - r, w);
    }
    if (area(a) > area(b))
        swap(a, b);

    return PP(a, b);
}

int main()
{
    int n, h, w;
    while (cin >> n >> h >> w, n || h || w)
    {
        vp c(n + 1);
        c[0] = P(h, w);
        rep(i, n)
        {
            int p, r;
            cin >> p >> r;
            p--;
            PP cut = split(c, p, r);
            for (int after = p; after < i; after++)
            {
                c[after] = c[after + 1];
            }
            c[i] = cut.first;
            c[i + 1] = cut.second;
        }
        sort(c.begin(), c.end(), [](P a, P b) { return area(a) < area(b); });

        rep(i, n + 1)
        {
            cout << area(c[i]) << (i == n ? "\n" : " ");
        }
    }

    return 0;
}