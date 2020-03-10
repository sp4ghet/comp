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

int main()
{
    int m, n;
    cin >> m;
    vector<P> c(m);
    rep(i, m) cin >> c[i].first >> c[i].second;
    cin >> n;
    vector<P> s(n);
    rep(i, n) cin >> s[i].first >> s[i].second;

    sort(c.begin(), c.end());
    sort(s.begin(), s.end());

    P d;
    rep(i, n) rep(j, m)
    {
        P t = s[i];
        P f = c[j];
        d = P(t.first - f.first, t.second - f.second);
        bool ok = true;
        rep(a, m)
        {
            P look = P(c[a].first + d.first, c[a].second + d.second);
            ok = ok && binary_search(s.begin(), s.end(), look);
            if (!ok)
                break;
        }
        if (ok)
        {
            cout << d.first << " " << d.second << endl;
            return 0;
        }
    }

        return 0;
}