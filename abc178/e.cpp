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

int dist(P a, P b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    int n;
    cin >> n;
    vp a(n);
    rep(i, n) cin >> a[i];
    vp b = a, c = a, d = a;
    rep(i, n) swap(b[i].first, b[i].second);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end(), [](P x, P y) {
        return x.first + x.second < y.first + y.second;
    });
    sort(d.begin(), d.end(), [](P x, P y) {
        return x.first - x.second < y.first - y.second;
    });
    view(a);
    view(b);
    view(c);
    view(d);

    int ans = 0;
    rep(i, n)
    {
        int x = a[i].first, y = a[i].second;
        int dx = max(dist(a[0], a[i]), dist(a[n - 1], a[i]));
        int dy = max(abs(b[0].second - x) + abs(b[0].first - y), abs(b[n - 1].second - x) + abs(b[n - 1].first - y));
        int dur = max(dist(c[0], a[i]), dist(c[n - 1], a[i]));
        int ddl = max(dist(d[0], a[i]), dist(d[n - 1], a[i]));
        ans = max(ans, max(dy, dx));
        ans = max(ans, dur);
        ans = max(ans, ddl);
    }
    cout << ans << endl;

    return 0;
}

// 4
// 1 1
// 10 10
// 0 10
// 10 0