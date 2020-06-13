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
    int n, k;
    cin >> n >> k;
    vint a(n + 1);
    rep(i, n) cin >> a[i];

    vint b(n);
    rep(i, k)
    {
        bool maxed = true;
        b = vint(n);
        rep(j, n)
        {
            int l = a[j];
            int low = max(0, j - l);
            int hig = min(n - 1, j + l);

            b[low]++;
            if (hig < n - 1)
                b[hig + 1]--;
        }

        a = vint(n + 1);
        rep(j, n)
        {
            if (j > 0)
                a[j] += a[j - 1];
            a[j] += b[j];
            maxed = maxed && a[j] >= n;
        }

        if (maxed)
        {
            break;
        }
    }

    rep(i, n)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}