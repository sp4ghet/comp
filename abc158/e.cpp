#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

#pragma region mod
int p = 1e9 + 7; //10^9 + 7
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

#pragma endregion

int main()
{
    int n;
    cin >> n >> p;
    string st;
    cin >> st;
    ll ans = 0;
    if (p == 2 || p == 5)
    {
        rep(i, n)
        {
            int x = st.at(i) - '0';
            if (x % p == 0)
            {
                ans += (i + 1);
            }
        }
        cout << ans << endl;
        return 0;
    }

    vector<mint> ten(n, 1);
    rep(i, n - 1) ten[i + 1] = ten[i] * 10;
    vector<mint> s(n + 1);
    map<int, int> cnt;
    for (int i = 1; i < n + 1; i++)
    {
        int j = n - i;
        int x = st.at(j) - '0';
        s[i] = s[i - 1] + ten[i - 1] * x;
    }

    rep(i, n + 1)
    {
        ans += cnt[s[i].x];
        cnt[s[i].x]++;
    }

    cout << ans << endl;

    return 0;
}