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

ll gcd(ll A, ll B)
{
    if (A < B)
    {
        return gcd(B, A);
    }
    if (B == 0)
    {
        return A;
    }
    return gcd(B, A % B);
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

int f(int b)
{
    int res = 0;
    while (b % 2 == 0)
    {
        b /= 2;
        res++;
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
        a[i] /= 2;
    }

    int k = f(a[0]);
    rep(i, n)
    {
        if (k != f(a[i]))
        {
            cout << 0 << endl;
            return 0;
        }
        // a[i] = a[i] >> k;
    }
    // m = m >> k;
    ll t = 1;
    for (auto &x : a)
    {
        t = lcm(t, x);
        if (t > m)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = m / t;
    ans = (ans + 1) / 2;

    cout << ans << endl;

    return 0;
}