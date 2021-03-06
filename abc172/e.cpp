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
    mint perm(int n, int k)
    {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * invs[n - k];
    }
};
#pragma endregion
vector<mint> fac;

mint npr(mint n, mint r)
{
    mint x = fac[n.x];
    x /= fac[(n - r).x];
    return x;
}

int main()
{
    // We want two series of length n consisting of the numbers 1~m satisfying:
    // 1. a_i != a_j (i != j)
    // 2. a_i != b_i for all i
    int n, m;
    cin >> n >> m;
    comb ncr(m);

    // The number of series which satisfies condition 1 is given by mPn
    // Naiively, if we just need 2 series which satisfy condition 1, then the answer would just be (mPn)*(mPn)
    mint ans = ncr.perm(m, n);

    // However, we need to exclude cases where a_i = b_i for any i
    mint x = 0;

    // We can confirm that there are (m-1)P(n-1) cases where a_i may be equal to b_i.
    // We can also confirm that there are (m-2)P(n-2) cases where a_i = b_i AND a_j = b_j.
    // There are nC2 ways to choose a pair (i,j) from 1~n, so we need to subtract the overlap.
    // for an overlap of 3, we would need to add the overlap since we will have subtracted too many.
    // Inductively, we need to keep going until we hit nCn * (m-n)P(n-n) which is just 1.
    rep(i, n)
    {
        mint y = ncr(n, i + 1) * ncr.perm(m - i - 1, n - i - 1);
        x += (i % 2) ? mint(0) - y : y;
    }
    ans *= (ans - x);

    cout << ans << endl;

    return 0;
}
