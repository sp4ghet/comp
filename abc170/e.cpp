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
    int n, q;
    cin >> n >> q;
    map<int, multiset<int>> k;
    vp child(n);

    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        child[i] = P(a, b);
        k[b].emplace(a);
    }
    multiset<int> maxes;
    for (auto p : k)
    {
        maxes.emplace(*p.second.rbegin());
    }
    rep(i, q)
    {
        int c, d;
        cin >> c >> d;
        c--;
        int b = child[c].second;
        int a = child[c].first;
        child[c].second = d;

        maxes.erase(maxes.find(*k[b].rbegin()));

        k[b].erase(k[b].find(a));

        if (k[b].size())
            maxes.emplace(*k[b].rbegin());

        if (k[d].size())
            maxes.erase(maxes.find(*k[d].rbegin()));

        k[d].emplace(a);
        maxes.emplace(*k[d].rbegin());

        cout << *maxes.begin() << "\n";
    }
    cout << endl;

    return 0;
}