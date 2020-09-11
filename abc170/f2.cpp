// #define _GLIBCXX_DEBUG
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

const int INF = 1e8;

struct edge
{
    int c;
    P p;
    edge(P p, int c) : p(p), c(c) {}
    bool operator>(const edge &r) const { return c > r.c; }
};

int main()
{
    int h, w, k;
    cin >> h >> w >> k;
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    x1--;
    y1--;
    x2--;
    y2--;

    vvchar g(h, vchar(w));
    rep(y, h) rep(x, w) cin >> g[y][x];
    priority_queue<edge, vector<edge>, greater<edge>> q;
    q.emplace(edge(P(y1, x1), 0));
    vector<int> dir = {1, 0, -1, 0, 1};
    vvint d(h, vint(w, INF));
    d[y1][x1] = 0;

    while (q.size())
    {
        edge e = q.top();
        P p = e.p;
        q.pop();
        int y = p.first, x = p.second;
        if (p == P(y2, x2))
            break;
        int now = d[y][x];
        rep(i, 4)
        {
            int dx = dir[i], dy = dir[i + 1];
            for (int i = 1; i <= k; ++i)
            {

                int nx = x + dx * i,
                    ny = y + dy * i;
                // THIS LAST CONDITION IS EXTREMELY IMPORTANT to avoid TLE.
                // If we already can reach a new place in `now` steps, then the following check is unnecessary
                // and you can also reach any place that can be reached in equal or less time
                // by searching from the new place instead of where we are now.
                if (ny < 0 || ny >= h || nx < 0 || nx >= w || g[ny][nx] == '@' || d[ny][nx] <= now)
                    break;

                if (d[ny][nx] > now + 1)
                {
                    d[ny][nx] = now + 1;
                    q.push(edge(P(ny, nx), now + 1));
                }
            }
        }
    }

    if (d[y2][x2] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << d[y2][x2] << endl;
    }

    return 0;
}