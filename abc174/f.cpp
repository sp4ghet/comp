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
    int n, q;
    cin >> n >> q;
    vint c(n);
    rep(i, n) cin >> c[i];

    vint pi(n + 1, -1);
    vvint ps(n);
    rep(i, n)
    {
        int l = pi[c[i]];
        if (l != -1)
            ps[l].emplace_back(i);
        pi[c[i]] = i;
    }

    vvp qs(n);
    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        qs[l].emplace_back(r, i);
    }

    vint ans(q);
    BIT<int> d(n);
    for (int x = n - 1; x >= 0; --x)
    {
        for (int y : ps[x])
            d.add(y);

        for (P qr : qs[x])
        {
            int r = qr.first, i = qr.second;
            ans[i] = (r - x + 1) - d.sum(r);
        }
    }

    for (int x : ans)
    {
        cout << x << endl;
    }

    return 0;
}