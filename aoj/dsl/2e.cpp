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
    int n, q;
    cin >> n >> q;
    int size = 1 << (int)(log2(n) + 1) + 1;
    vint seg(size, 0);

    auto get = [&](int i) {
        int k = i + n;
        int ans = seg[k];
        while (k)
        {
            k /= 2;
            ans += seg[k];
        }
        return ans;
    };
    auto addRange = [&](int s, int t, int x) {
        int l = s + n,
            r = t + n;
        while (l < r)
        {
            if (l % 2)
            {
                seg[l] += x;
                l++;
            }
            l /= 2;
            if (r % 2)
            {
                seg[r - 1] += x;
                r--;
            }
            r /= 2;
        }
    };
    rep(i, q)
    {
        int com, s, t, x;
        cin >> com;
        if (com)
        {
            cin >> t;
            int ans = get(t);
            cout << ans << "\n";
        }
        else
        {
            cin >> s >> t >> x;
            addRange(s, t + 1, x);
        }
    }

    return 0;
}