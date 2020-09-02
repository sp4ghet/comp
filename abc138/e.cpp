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
    string s, t;
    cin >> s >> t;
    map<char, vint> m;
    rep(i, s.size())
    {
        m[s[i]].emplace_back(i + 1);
    }
    if (m[t[0]].size() == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    int pre = -1;
    rep(i, t.size())
    {
        if (!m[t[i]].size())
        {
            cout << -1 << endl;
            return 0;
        }
        int idx = upper_bound(m[t[i]].begin(), m[t[i]].end(), pre) - m[t[i]].begin();
        if (idx == m[t[i]].size())
            idx--;

        if (pre >= m[t[i]][idx])
        {
            // printf("%d %d %c\n", pre, m[t[i]][idx], t[i]);
            // view(m[t[i]]);
            ans += s.size();
            pre = m[t[i]][0];
        }
        else
        {
            pre = m[t[i]][idx];
        }
    }
    ans += pre;

    cout << ans << endl;

    return 0;
}