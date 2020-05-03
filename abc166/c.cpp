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

const int MAX_N = 1e5 + 5;
int main()
{
    int n, m;
    cin >> n >> m;
    vint h(n);
    rep(i, n) cin >> h[i];
    vvint g(n, vint());
    bitset<MAX_N> good(n);
    rep(i, n) good[i] = true;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (h[a] > h[b])
        {
            good[b] = false;
        }
        else if (h[a] == h[b])
        {
            good[a] = false;
            good[b] = false;
        }
        else
        {
            good[a] = false;
        }
    }
    int ans = 0;
    rep(i, n)
    {
        if (good[i])
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}