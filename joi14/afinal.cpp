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

struct prices
{
    ll a, b, c;
    prices(int aa = 0, int bb = 0, int cc = 0) : a(aa), b(bb), c(cc) {}
};

int main()
{
    int n, m;
    cin >> n >> m;
    vint a(n + 1);
    int now;
    cin >> now;
    now--;
    rep(i, m - 1)
    {
        int p;
        cin >> p;
        p--;
        if (p < now)
        {
            a[p]++;
            a[now]--;
        }
        else
        {
            a[now]++;
            a[p]--;
        }
        now = p;
    }
    vector<prices> t(n);
    rep(i, n - 1)
    {
        cin >> t[i + 1].a >> t[i + 1].b >> t[i + 1].c;
    }

    vint c(n);
    rep(i, n - 1) c[i + 1] = c[i] + a[i];

    ll ans = 0;
    rep(i, n)
    {
        ll cost = min(t[i].a * c[i], t[i].c + t[i].b * c[i]);
        ans += cost;
    }

    cout << ans << endl;

    return 0;
}