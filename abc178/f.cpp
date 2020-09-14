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
#ifndef ONLINE_JUDGE
    for (const auto &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
#endif
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
    int n;
    cin >> n;
    map<int, int> m;
    vint a(n), b(n);
    rep(i, n)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    rep(i, n)
    {
        cin >> b[i];
        m[b[i]]++;
    }
    for (P p : m)
    {
        if (p.second > n)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    vint c(n + 1), d(n + 1);
    int cp = 0, dp = 0;
    for (int i = 1; i <= n; i++)
    {
        int now = a[cp];
        c[i] = c[i - 1];
        if (now == i)
        {
            while (a[cp] == now)
            {
                c[i]++;
                cp++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int now = b[dp];
        d[i] = d[i - 1];
        if (now == i)
        {
            while (b[dp] == now)
            {
                d[i]++;
                dp++;
            }
        }
    }
    int y = 0;

    for (int i = 1; i <= n; i++)
    {
        y = max(y, c[i] - d[i - 1]);
    }

    // rotate
    vint newB(n);
    rep(i, n)
    {
        newB[(i + y) % n] = b[i];
    }
    cout << "Yes" << endl;
    rep(i, n) printf("%d ", newB[i]);
    cout << endl;
    return 0;
}