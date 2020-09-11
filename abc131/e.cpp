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

    if (k > (n - 2) * (n - 1) / 2)
    {
        cout << -1 << endl;
        return 0;
    }

    int m = (n * (n - 1)) / 2 - k;
    cout << m << endl;
    rep(i, n - 1)
    {
        printf("%d %d\n", 1, i + 2);
    }
    int c = n - 1;
    for (int i = 2; i < n; ++i)
    {
        if (c >= m)
            break;
        for (int j = i + 1; j <= n; ++j)
        {
            if (c >= m)
                break;
            printf("%d %d\n", i, j);
            c++;
        }
    }

    return 0;
}