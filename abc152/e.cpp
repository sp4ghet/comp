#include <bits/stdc++.h>
#include <boost/math/common_factor.hpp>
using namespace std;
using ll = unsigned long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
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
const int p = 1e9 + 7; //10^9 + 7
struct mint
{
    ll x;
    mint(ll x = 0) : x(x % p) {}
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
        if (t == 0)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }

    mint inv() const
    {
        return pow(p - 2);
    }
    mint &operator/=(const mint a)
    {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const
    {
        mint res(*this);
        return res /= a;
    }
};

struct sieve
{
    int n;
    vector<int> f, primes;

    sieve(int n = 1) : n(n), f(n + 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (f[i])
                continue;
            primes.push_back(i);
            f[i] = i;
            for (ll j = i * i; j <= n; j += i)
            {
                if (!f[j])
                    f[j] = i;
            }
        }
    }

    bool isPrime(int x)
    {
        return f[x] == x;
    }

    vector<int> factorList(int x)
    {
        vector<int> res;
        while (x != 1)
        {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<pair<int, int>> factor(int x)
    {
        auto fl = factorList(x);
        if (fl.size() == 0)
        {
            return {};
        }
        vector<P> res(1, P(fl[0], 0));
        for (int p : fl)
        {
            if (res.back().first == p)
            {
                res.back().second++;
            }
            else
            {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};

int main()
{
    sieve s(1e6);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    map<int, int> mp;
    rep(i, n)
    {
        auto f = s.factor(a[i]);
        for (P p : f)
        {
            mp[p.first] = max(p.second, mp[p.first]);
        }
    }

    mint lcm = 1;
    for (auto p : mp)
    {
        rep(i, p.second) lcm *= p.first;
    }

    mint ans = 0;
    rep(i, n)
    {
        ans += lcm / a[i];
    }

    cout << ans.x << endl;

    return 0;
}