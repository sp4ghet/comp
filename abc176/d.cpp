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

#define fst first
#define snd second

int main()
{

    int h, w, cx, cy, gx, gy;
    int gidx = INT32_MAX;
    cin >> h >> w >> cy >> cx >> gy >> gx;
    cy--;
    cx--;
    gy--;
    gx--;
    vector<string> g(h);
    rep(y, h) cin >> g[y];
    vvint hops = vvint(h, vint(w, INT32_MAX));

    deque<P> q;
    q.push_back(P(cy, cx));
    hops[cy][cx] = 0;

    int dir[] = {1, 0, -1, 0, 1};
    while (q.size())
    {
        P p = q.front();
        q.pop_front();

        int y = p.fst;
        int x = p.snd;

        rep(i, 4)
        {
            int ny = y + dir[i];
            int nx = x + dir[i + 1];
            if (ny >= h || nx >= w || ny < 0 || nx < 0)
                continue;
            if (g[ny][nx] == '#')
                continue;
            if (hops[ny][nx] > hops[y][x])
            {
                hops[ny][nx] = hops[y][x];
                q.push_front(P(ny, nx));
            }
        }

        for (int dy = -2; dy <= 2; dy++)
            for (int dx = -2; dx <= 2; dx++)
            {
                int ny = p.fst + dy,
                    nx = p.snd + dx;
                if (ny >= h || ny < 0 || nx >= w || nx < 0)
                    continue;
                if (g[ny][nx] == '#')
                    continue;
                if (hops[ny][nx] > hops[y][x] + 1)
                {
                    hops[ny][nx] = hops[y][x] + 1;
                    q.push_back(P(ny, nx));
                }
            }
    }

    int ans = hops[gy][gx];
    if (ans == INT32_MAX)
    {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}
