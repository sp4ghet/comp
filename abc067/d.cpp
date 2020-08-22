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
    int n;
    cin >> n;
    vvint g(n, vint());
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    queue<P> q;
    q.push(P(0, 1));
    q.push(P(n - 1, 2));
    vint col(n);
    col[0] = 1;
    col[n - 1] = 2;
    while (q.size())
    {
        P p = q.front();
        q.pop();
        int i = p.first;
        int c = p.second;
        for (int j : g[i])
        {
            if (col[j])
                continue;
            col[j] = c;
            q.push(P(j, c));
        }
    }

    int f = 0, s = 0;
    rep(i, n)
    {
        if (col[i] == 1)
        {
            f++;
        }
        else
        {
            s++;
        }
    }

    if (f > s)
    {
        cout << "Fennec" << endl;
    }
    else
    {
        cout << "Snuke" << endl;
    }

    return 0;
}