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
int p = 1e9 + 7; //10^9 + 7
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

ll pow2(ll x, ll p)
{
    ll r = 1;
    ll a = 2;
    while (true)
    {
        if (x & 1)
        {
            r *= (a % p);
            r %= p;
        }
        x >>= 1;
        if (x == 0)
            break;
        a *= a;
        a %= p;
    }

    return r;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int pop = 0;
    rep(i, n) if (s[i] == '1') pop++;
    ll valpl = 0, valmn = 0;
    p = pop + 1;
    rep(i, n)
    {
        if (s[i] == '1')
            valpl += pow2(n - i - 1, p);
        valpl %= p;
    }

    p = pop - 1;
    if (p)
    {
        rep(i, n)
        {
            if (s[i] == '1')
                valmn += pow2(n - i - 1, p);
            valmn %= p;
        }
    }

    rep(i, n)
    {
        int step = 1;
        ll nowv;
        if (s[i] == '1')
        {
            p = pop - 1;
            if (p)
            {
                nowv = valmn + p - pow2(n - i - 1, p);
                nowv %= p;
            }
            else
            {
                step = 0;
                nowv = 0;
            }
        }
        else
        {
            p = pop + 1;
            nowv = valpl + pow2(n - i - 1, p);
            nowv %= p;
        }

        int a = nowv;
        while (a)
        {
            a %= __builtin_popcount(a);
            step++;
        }

        cout << step << endl;
    }

    return 0;
}