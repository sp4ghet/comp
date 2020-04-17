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

#define rep(i, n) for (int i = 1; i <= n; ++i)
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

using vmint = vector<mint>;

int main()
{
    int n, k;
    cin >> n >> k;
    vmint d(k + 1);

    rep(i, k) d[i] = mint(k / i).pow(n);

    for (int i = k; i > 0; i--)
        for (int j = 2 * i; j <= k; j += i)
        {
            d[i] -= d[j];
        }

    mint ans = 0;
    rep(i, k)
    {
        ans += d[i] * i;
    }

    cout << ans << endl;

    return 0;
}