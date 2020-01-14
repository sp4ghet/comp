#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < n; ++i)
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

const ll p = 1e9 + 7;

vector<ll> pows(2 * 10e5 + 7, -1);

ll pow2(ll x)
{
    if (pows[x] >= 0)
        return pows[x];
    ll a = 1;
    rep(i, x)
    {
        a = (a * 2) % p;
        pows[i + 1] = a;
    }
    return a;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> c(n);
    rep(i, n) cin >> c[i];
    sort(c.begin(), c.end());

    vector<ll> facts(n);
    rep(i, n)
    {
        ll r = n - 1 - i;
        if (r == 0)
        {
            facts[i] = pow2(i);
            break;
        }
        facts[i] = pow2(i) * (pow2(r) + (pow2(r - 1) * (r)) % p);
        facts[i] %= p;
    }

    ll ans = 0;
    rep(i, n)
    {
        ll add = (c[i] * facts[i]) % p;
        ans += add;
        ans %= p;
    }
    ans *= pow2(n);
    ans %= p;

    cout << ans << endl;

    return 0;
}