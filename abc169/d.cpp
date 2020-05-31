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

#pragma region sieve
struct sieve
{
    ll n;
    vector<ll> f, primes;

    sieve(ll n = 1) : n(n), f(sqrt(n) + 5)
    {
        for (ll i = 2; i * i <= n; i++)
        {
            if (f[i])
                continue;
            primes.push_back(i);
            f[i] = i;
            for (ll j = i * i; j <= f.size(); j += i)
            {
                if (!f[j])
                    f[j] = i;
            }
        }
    }

    bool isPrime(ll x)
    {
        return f[x] == x;
    }

    vector<ll> factorList(ll x)
    {
        vector<ll> res;
        while (x != 1)
        {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<pair<ll, ll>> factor(ll x)
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
#pragma endregion

int main()
{
    ll n;
    cin >> n;
    ll k = n;
    vint t(50);
    rep(i, 50) t[i] = (i * (i + 1)) / 2;
    ll ans = 0;
    map<int, int> pl;
    while (n != 1)
    {
        ll g = n;
        for (int p = 2; p <= sqrt(n) + 5; p++)
        {
            while (n % p == 0)
            {
                n /= p;
                pl[p]++;
            }
        }
        if (n == g)
        {
            pl[n]++;
            break;
        }
    }

    for (P p : pl)
    {
        int c = lower_bound(t.begin(), t.end(), p.second) - t.begin();
        if (p.second < t[c])
        {
            c--;
        }

        ans += c;
    }
    if (pl.size() == 0 && k != 1)
    {
        ans = 1;
    }

    cout << ans << endl;

    return 0;
}