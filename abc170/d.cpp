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

#pragma region sieve
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
#pragma endregion

int main()
{
    int n;
    cin >> n;
    vint a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int big = a[n - 1];
    vint mark(big + 1);
    int ans = 0;
    rep(i, n)
    {
        mark[a[i]]++;
        if (mark[a[i]] > 1)
        {
            continue;
        }
        for (int j = a[i] * 2; j <= big; j += a[i])
        {
            mark[j]++;
        }
    }

    rep(i, n)
    {
        if (mark[a[i]] > 1)
        {
            continue;
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}