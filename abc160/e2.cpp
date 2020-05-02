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
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vint r(a), g(b), n(c);
    rep(i, a) cin >> r[i];
    rep(i, b) cin >> g[i];
    rep(i, c) cin >> n[i];

    sort(r.rbegin(), r.rend());
    sort(g.rbegin(), g.rend());
    sort(n.rbegin(), n.rbegin());

    vint all;
    rep(i, x) { all.emplace_back(r[i]); }
    rep(i, y) all.emplace_back(g[i]);
    rep(i, c) all.emplace_back(n[i]);

    sort(all.rbegin(), all.rend());

    ll ans = 0;
    rep(i, x + y)
    {
        ans += all[i];
    }

    cout << ans << endl;

    return 0;
}