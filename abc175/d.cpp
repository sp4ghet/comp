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
    int n, k;
    cin >> n >> k;
    vll p(n), c(n);
    rep(i, n) cin >> p[i];
    rep(i, n) p[i]--;
    rep(i, n) cin >> c[i];
    vint vis(n);
    int loopId = 1;
    vvll g;
    rep(i, n)
    {
        if (vis[i])
            continue;
        vll now = vll();
        int j = p[i];
        now.emplace_back(c[i]);
        while (j != i)
        {
            vis[j] = loopId;
            now.emplace_back(c[j]);
            j = p[j];
        }
        g.emplace_back(now);
        loopId++;
    }

    ll ans = INT64_MIN;
    for (vll now : g)
    {
        int m = now.size();
        ll loopScore = 0;
        rep(i, m)
        {
            loopScore += now[i];
        }
        ll maxScore = INT64_MIN;
        rep(i, m)
        {
            int j = i;
            ll sc = 0;
            rep(l, min(m, k))
            {
                j = (i + l) % m;
                sc += now[j];
                ll loops = ((k - l - 1) / m);
                ll nowScore = loopScore * loops + sc;
                nowScore = max(nowScore, sc);
                maxScore = max(nowScore, maxScore);
            }
        }

        ans = max(ans, maxScore);
    }

    cout << ans << endl;

    return 0;
}