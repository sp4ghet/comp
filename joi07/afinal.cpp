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
    int n;
    cin >> n;
    vint a(n);
    rep(i, n) cin >> a[i];
    stack<int> b;
    // 0 -> white, 1 -> black
    b.push(a[0] ? -1 : 1);
    for (int i = 1; i < n; ++i)
    {
        bool white = a[i] == 0;
        int add = a[i] ? -1 : 1;
        if ((b.top() > 0) == white)
        {
            b.top() += add;
            continue;
        }
        if (i % 2 == 0)
        {
            b.push(add);
        }
        else
        {
            int now = -1 * b.top() + add;
            b.pop();
            if (b.size())
            {
                b.top() += now;
            }
            else
            {
                b.push(now);
            }
        }
    }
    int ans = 0;
    while (b.size())
    {
        int add = b.top();
        b.pop();
        // cout << add << " ";
        if (add > 0)
            ans += add;
    }
    // cout << endl;

    cout << ans << endl;

    return 0;
}