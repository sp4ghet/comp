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
    vint a(n);
    iota(a.begin(), a.end(), 1);
    set<int> s;

    auto swapper = [&](int x) {
        swap(a[x], a[x + 1]);
        for (int i = x - 1; i <= x + 1; ++i)
        {
            if (i < 0 || i >= n - 1)
                continue;

            if (a[i] > a[i + 1])
            {
                s.emplace(i);
            }
            else
            {
                s.erase(i);
            }
        }
    };

    rep(_, q)
    {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        if (t == 1)
        {
            swapper(x);
        }
        else
        {
            while (true)
            {
                auto idx = s.lower_bound(x);
                if (idx == s.end() || *idx >= y)
                    break;
                swapper(*idx);
            }
        }
    }

    rep(i, n) cout << a[i] << " ";
    cout << endl;
    return 0;
}