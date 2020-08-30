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

    bool tr = false;
    map<int, int> tx, ty;
    rep(i, q)
    {
        int t, a, b;
        cin >> t;
        if (tr)
        {
            if (t == 1)
                t = 2;
            else if (t == 2)
                t = 1;
        }
        int nx, ny, px, py;
        switch (t)
        {
        // change row a/b
        case 1:
            cin >> a >> b;
            py = a;
            if (ty[a])
            {
                py = ty[a];
            }
            ny = b;
            if (ty[b])
            {
                ny = ty[b];
            }
            ty[b] = py;
            ty[a] = ny;
            break;
        case 2:
            // change column a/b
            cin >> a >> b;
            px = a;
            if (tx[px])
            {
                px = tx[a];
            }
            nx = b;
            if (tx[b])
            {
                nx = tx[b];
            }
            tx[b] = px;
            tx[a] = nx;
            break;
        case 3:
            tr = !tr;
            break;
        case 4:
            cin >> a >> b;
            if (tr)
                swap(a, b);
            ll y = ty[a] ? ty[a] : a, x = tx[b] ? tx[b] : b;
            ll m = n;
            ll ans = m * (y - 1) + (x - 1);
            cout << ans << endl;

            break;
        }
    }

    return 0;
}