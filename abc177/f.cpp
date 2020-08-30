#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using vint = vector<int>;
using vvint = vector<vint>;
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
    vp g(h);
    rep(i, h)
    {
        int a, b;
        cin >> a >> b;
        g[i] = {a, b};
    }
    P l = {1, w}, r = {1, w};
    rep(y, h)
    {
        int cst = w + 5;
        if (g[y].first <= l.first && g[y].second >= w)
        {
            for (int i = y; i < h; ++i)
            {
                cout << -1 << endl;
            }
            return 0;
        }
        P nl = {1, g[y].first - 1}, nr = {g[y].second + 1, w};
    }
    return 0;
}

// ...##.
// ##....
// ..##..
// .#####
// ......