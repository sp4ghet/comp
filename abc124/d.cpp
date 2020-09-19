#define _GLIBCXX_DEBUG
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
    string s;
    cin >> s;
    s.push_back('2');

    vint cl;
    char now = s[0];
    int l = 0;
    rep(i, n + 1)
    {
        if (now != s[i])
        {
            int cnt = (i - l);
            cnt *= now == '1' ? 1 : -1;
            cl.emplace_back(cnt);
            l = i;
            now = s[i];
        }
    }
    int m = cl.size();
    int k1 = min(m, k * 2 + 1), k0 = min(m, (k - 1) * 2 + 1);

    int s0 = 0, s1 = 0;
    rep(i, k0) s0 += abs(cl[i]);
    int ans = 0;
    if (cl[0] < 0)
    {
        rep(i, k1 - 1) s1 += abs(cl[i]);
        ans = max(s1, s0);
        s1 += abs(cl[min(1, m - 1)]);
    }
    else
    {
        rep(i, k1) s1 += abs(cl[i]);
        ans = max(s1, s0);
    }

    l = 0;

    for (int i = k1 + 1 - (cl[0] < 0); i < m; i += 2)
    {
        s1 -= abs(cl[l]);
        s1 -= abs(cl[l + 1]);
        s1 += abs(cl[i - 1]);
        s1 += abs(cl[i]);
        ans = max(ans, s1);
        if (l == 0 && cl[0] < 0)
        {
            l++;
        }
        else
        {
            l += 2;
        }
    }

    // view(cl);
    // printf("%d %d %d\n", m, k1, k0);
    // printf("%d %d %d\n", l, s1, ans);
    // cout << m - l << endl;

    if (m - l > k1 || (m == 3 && l == 0))
    {
        s1 -= abs(cl[l]);
        s1 -= abs(cl[l + 1]);
        s1 += abs(cl[m - 1]);
        ans = max(ans, s1);
    }

    l = 0;
    for (int i = k0; i < m; ++i)
    {
        s0 -= abs(cl[l]);
        s0 += abs(cl[i]);
        ans = max(ans, s0);
        l++;
    }

    cout << ans << endl;

    return 0;
}