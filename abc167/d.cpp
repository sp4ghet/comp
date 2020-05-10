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

#define rep(i, n) for (ll i = 0; i < n; ++i)
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

int main()
{
    ll n, k;
    cin >> n >> k;
    vint a(n);
    rep(i, n)
    {
        cin >> a[i];
        a[i]--;
    }
    vll vis(n, 0);
    ll i = 0;
    while (true)
    {
        if (vis[i] >= 2)
        {
            break;
        }
        vis[i]++;
        i = a[i];
    }

    ll loop = 0, pre = 0;
    rep(i, n)
    {
        pre += vis[i] == 1;
        loop += vis[i] == 2;
    }
    if (k >= pre)
    {
        k -= pre;
        k %= loop;
    }
    else
    {
        int now = 0;
        rep(i, k)
        {
            now = a[now];
        }
        cout << now + 1 << endl;
        return 0;
    }

    vis = vll(n, -pre - 5);
    i = 0;
    ll c = 0;
    while (true)
    {
        if (vis[i] >= 0)
            break;
        vis[i] = c - pre;
        i = a[i];
        c++;
    }
    rep(i, n)
    {
        if (vis[i] == k)
        {
            cout << i + 1 << endl;
        }
    }

    return 0;
}