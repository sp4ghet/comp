#define _GLIBCXX_DEBUG
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
    int n;
    cin >> n;
    n++;
    vint a(n);
    rep(i, n) cin >> a[i];
    ll now = 1;
    vll b(n), c(n);
    rep(i, n)
    {
        b[i] = now;
        now -= a[i];
        if (i != n - 1 && now <= 0)
        {
            cout << (-1) << endl;
            return 0;
        }
        now = 2 * now;
    }

    reverse(a.begin(), a.end());
    now = a[0];
    c[0] = now;
    for (int i = 1; i < n; i++)
    {
        now += a[i];
        c[i] = now;
    }
    reverse(c.begin(), c.end());

    ll ans = 0;
    rep(i, n)
    {
        ans += min(b[i], c[i]);
    }
    cout << ans << endl;

    return 0;
}