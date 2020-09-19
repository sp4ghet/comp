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
    ll n, x, m;
    cin >> n >> x >> m;

    vll a(m);
    ll y = x;
    ll st = -1, ed = -1, ly = -1;
    ll ans = 0;
    for (ll i = 0; i < n; ++i)
    {
        ans += y;

        y = (y * y) % m;
        if ((i < n - 1) && a[y])
        {
            st = a[y];
            ed = i + 1;
            ly = y;
            break;
        }
        a[y] = i + 1;
    }
    if (ly == -1)
    {
        cout << ans << endl;
        return 0;
    }

    y = x;
    ans = 0;
    rep(i, st)
    {
        ans += y;
        y = (y * y) % m;
    }

    ll k = ed - st;
    n -= st;
    ll lop = 0;
    rep(i, k)
    {
        lop += y;
        y = (y * y) % m;
    }
    ans += (n / k) * lop;
    n = n % k;
    rep(i, n)
    {
        ans += y;
        y = (y * y) % m;
    }

    cout << ans << endl;

    return 0;
}