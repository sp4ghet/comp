#include <bits/stdc++.h>
#include <boost/math/common_factor.hpp>
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

ll lcm(vint &a)
{
    ll res = 1;

    for (ll b : a)
    {
        res = boost::math::lcm(res, b);
    }
    return res;
}

int countPow2(int x)
{
    int res = 0;
    while (x % 2 == 0)
    {
        res++;
        x /= 2;
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vint a(n);
    rep(i, n)
    {
        cin >> a[i];
        a[i] /= 2;
    }

    // ここの発想が毎回全然わからん
    int count = countPow2(a[0]);
    rep(i, n)
    {
        if (countPow2(a[i]) != count)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    ll k = lcm(a);
    if (k > m)
    {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 1; k * i <= m; i += 2)
        ans++;

    cout << ans << endl;

    return 0;
}