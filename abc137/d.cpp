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

const int INF = 1e9;
int main()
{
    int n, m;
    cin >> n >> m;
    vp a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    priority_queue<int> q;

    int ans = 0;
    rep(i, m)
    {
        auto idx = lower_bound(a.begin(), a.end(), P(i + 1, 0));
        while (idx != a.end() && (*(idx)).first <= i + 1)
        {
            q.push((*idx).second);
            idx++;
        }
        if (!q.empty())
        {
            int x = q.top();
            q.pop();
            ans += x;
        }
    }

    cout << ans << endl;

    return 0;
}