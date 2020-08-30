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

const int w = 2000;

vvint g(w + 5, vint(w + 5, INT32_MAX));

int main()
{
    int n, gx, gy;
    cin >> n >> gx >> gy;
    gx += w / 2;
    gy += w / 2;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        a += w / 2;
        b += w / 2;
        g[a][b] = -1;
    }

    queue<P> q;
    g[w / 2][w / 2] = 0;
    q.push({w / 2, w / 2});
    vint dir = {
        -1,
        1,
        1,
        0,
        -1,
        0,
        1,
    };

    // rep(i, 6)
    // {
    //     cout << P(dir[i], dir[i + 1]) << " ";
    // }
    // cout << endl;

    while (!q.empty())
    {
        P p = q.front();
        q.pop();
        int x = p.first,
            y = p.second,
            now = g[x][y];
        if (x == gx && y == gy)
            break;

        rep(i, 6)
        {

            int nx = x + dir[i],
                ny = y + dir[i + 1];
            if (nx < 0 || nx >= w + 5 || ny < 0 || ny >= w + 5)
                continue;

            if (g[nx][ny] <= now + 1)
                continue;

            g[nx][ny] = now + 1;
            q.push({nx, ny});
        }
    }

    if (g[gx][gy] == INT32_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << g[gx][gy] << endl;
    }

    return 0;
}