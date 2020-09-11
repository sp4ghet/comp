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
const ll p = 1e9 + 7; //10^9 + 7
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
    priority_queue<ll> pos;
    priority_queue<ll, vll, greater<ll>> neg;

    rep(i, n)
    {
        ll a;
        cin >> a;
        if (a >= 0)
            pos.push(a);
        if (a < 0)
            neg.push(a);
    }
    if (pos.size() && pos.top() == 0 && k % 2)
    {
        cout << 0 << endl;
        return 0;
    }

    mint ans = 1;
    if (pos.size() == 0 && k % 2)
    {
        while (neg.size() > k)
            neg.pop();

        rep(i, k)
        {
            ans *= neg.top();
            neg.pop();
        }
        cout << (ans.x + p) % p << endl;
        return 0;
    }

    int c = 0;
    while (c < k)
    {
        ll px = 0, nx = 0, p1 = 1, p2 = -1, n1 = 1, n2 = -1;
        bool pok = pos.size() >= 2,
             nok = neg.size() >= 2;
        if (k - c == 1)
        {
            // printf("end: %d %d %d\n", c, pos.size(), neg.size());
            if (pos.size())
                ans *= pos.top();
            if (pos.size() == 0 && neg.size())
                ans *= neg.top();
            break;
        }

        if (pos.size() == 1 && neg.size() == 1)
        {
            ans *= mint(pos.top() * neg.top());
            break;
        }

        if (pok)
        {
            p1 = pos.top();
            pos.pop();
            p2 = pos.top();
            pos.pop();
        }
        if (nok)
        {
            n1 = neg.top();
            neg.pop();
            n2 = neg.top();
            neg.pop();
        }

        px = p1 * p2;
        nx = n1 * n2;
        if (px > nx)
        {
            ans *= p1;
            pos.push(p2);
            if (nok)
            {
                neg.push(n1);
                neg.push(n2);
            }
            c++;
        }
        else
        {
            ans *= nx;
            if (pok)
            {
                pos.push(p1);
                pos.push(p2);
            }
            c += 2;
        }
    }

    cout << (ans.x + p) % p << endl;

    return 0;
}

// 7 5
// -8 -7 -6 5 4 3 2

// 5 3
// -5 -4 -4 3 3

// 10 10
// -1000000000 -100000000 -10000000 -1000000 -100000 -10000 -1000 -100 -10 -1