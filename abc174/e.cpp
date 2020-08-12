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
    vint a(n);
    rep(i, n) cin >> a[i];

    auto pos = [&](int x) {
        int sum = 0;
        rep(i, n)
        {
            int cut = a[i] / x;
            if (a[i] % x)
                cut++;
            cut--;
            sum += cut;
        }
        return sum <= k;
    };

    int l = 1,
        r = max_element(a.begin(), a.end())[0];
    while (l < r)
    {
        int mid = (l + r) / 2;
        bool ok = pos(mid);
        if (ok)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << r << endl;

    return 0;
}