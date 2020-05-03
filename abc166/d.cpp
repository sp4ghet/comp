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

ll pow5(ll n)
{
    return n * n * n * n * n;
}

int main()
{
    ll x;
    cin >> x;
    for (ll i = 1; i < 200; i++)
    {
        ll now = x;
        if (now == pow5(i))
        {
            printf("%lld %lld\n", i, 0ll);
            return 0;
        }
        ll sub = now - pow5(i); // -(-j)^5 = x - i^5
        for (ll j = 1; j < 200; j++)
        {
            if (sub == pow5(j))
            {
                printf("%lld -%lld\n", j, i);
                return 0;
            }
        }
        ll add = now + pow5(i); // x + i^5 = -(j^5)
        for (ll j = 1; j < 200; j++)
        {
            if (add == pow5(j))
            {
                printf("%lld %lld\n", j, i);
                return 0;
            }
        }
    }

    return 0;
}