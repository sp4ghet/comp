#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

const int p = 2019;
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
};

int main()
{
    int l, r;
    cin >> l >> r;

    int sml, lrg;
    sml = min(l % 2019, r % 2019);
    lrg = max(l % 2019, r % 2019);

    int ans = 2020;
    for (ll i = l; i < r; i++)
    {
        for (ll j = i + 1; j <= r; j++)
        {
            int now = (i * j) % 2019ll;
            ans = min(ans, now);
            if (ans == 0)
            {
                break;
            }
        }

        if (ans == 0)
        {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}