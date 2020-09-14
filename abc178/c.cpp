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

#pragma region mod
const int p = 1e9 + 7; //10^9 + 7
struct mint
{
    ll x;
    mint(ll xx = 0) : x(xx % p) {}
    mint &operator+=(const mint a)
    {
        if ((x += a.x) >= p)
            x -= p;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((x += p - a.x) >= p)
            x -= p;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= p;
        return *this;
    }

    mint operator+(const mint a) const
    {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const
    {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const
    {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const
    {
        mint r = 1;
        mint a = *this;
        while (true)
        {
            if (t & 1)
            {
                r *= a;
            }
            t >>= 1;
            if (t == 0)
                break;
            a *= a;
        }

        return r;
    }

    mint inv() const
    {
        return pow(p - 2);
    }

    mint &operator/=(const mint a)
    {
        return (*this) *= a.inv();
    }
};
istream &operator>>(istream &is, mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

struct comb
{
    vector<mint> fact, invs;
    comb(int n) : fact(n + 1), invs(n + 1)
    {
        assert(n < p);

        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i;

        invs[n] = fact[n].inv();
        for (int i = n; i >= 1; --i)
            invs[i - 1] = invs[i] * i;
    }
    mint operator()(int n, int k)
    {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * invs[n - k] * invs[k];
    }
};
#pragma endregion

// mint npr(mint n, mint r, comb ncr)
// {
//     mint ret = ncr.fact[n.x];
//     ret /= ncr.fact[r.x];
//     return ret;
// }

int main()
{
    int n;
    cin >> n;
    comb ncr(n);
    // if (n == 1)
    // {
    //     cout << 0 << endl;
    //     return 0;
    // }
    mint ten = 10;
    mint ans = 0;
    for (int i = 2; i <= n; i++)
    {
        mint np2 = mint(2).pow(i) - 2;
        ans += ncr(n, i) * np2 * mint(8).pow(n - i);
    }

    cout << ans << endl;
    return 0;
}
// 5 14670
// 4 974
// 3 54
// 2 2

// 3 c 1 ways to pick
// * 0 *
// * 9 *

// 4 c 2 ways to pick
// * * 0 0
// * * 0 9
// * * 9 0
// * * 9 9
// 226
//