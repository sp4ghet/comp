#define _GLIBCXX_DEBUG
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

#define rep(i, n) for (ll i = 0; i < n; ++i)
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
    ll n, k;
    cin >> n >> k;
    vll a(n), f(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());

    vp prod(n);
    rep(i, n) prod[i] = P(a[i] * f[i], f[i]);
    sort(prod.begin(), prod.end());
    reverse(prod.begin(), prod.end());

    auto pos = [](ll x, ll kk, ll n, vp p) {
        ll j = 0;
        while (kk > 0)
        {
            if (j >= n)
            {
                break;
            }
            if (p[j].first > x)
            {
                ll d = (p[j].first - x);
                d = (d + p[j].second - 1) / p[j].second;
                d = min(d, kk);
                kk -= d;
                p[j].first -= p[j].second * d;
                j++;
            }
            else
            {
                break;
            }
        }

        bool sat = true;
        rep(i, n) sat = sat && (p[i].first <= x);
        return sat;
    };

    ll l = 0,
       r = 1e18;

    while (l < r)
    {
        ll mid = (l + r) / 2;
        bool ok = pos(mid, k, n, prod);
        if (ok)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << r << endl;
    return 0;
}