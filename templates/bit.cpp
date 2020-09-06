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

#pragma region BIT
// binary index tree
// (fenwick tree)
// note: i&(-i) gives the least significant bit
template <typename T>
struct BIT
{
    int n;
    vector<T> a;
    BIT(int n) : n(n), a(n + 1) {}

    void add(int i, T x = 1)
    {
        for (++i; i <= n; i += i & (-i))
        {
            a[i] += x;
        }
    }
    T sum(int i)
    {
        T ret = 0;
        for (++i; i; i -= i & (-i))
        {
            ret += a[i];
        }
        return ret;
    }
    T sum(int l, int r)
    {
        return sum(r - 1) - sum(l - 1);
    }
};
#pragma endregion

int main()
{

    return 0;
}