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
using ld = long double;
using vld = vector<ld>;
using vvld = vector<vld>;
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

#define fst first
#define snd second

const int INF = 1e9;
struct edge
{
    int c;
    P p;
    edge(int c, P p) : c(c), p(p) {}
    bool operator>(const edge &r) const { return c > r.c; }
};
int main()
{

    int h, w, k, x1, y1, x2, y2;
    cin >> h >> w >> k;
    cin >> y1 >> x1 >> y2 >> x2;
    x1--;
    y1--;
    x2--;
    y2--;
    vvchar g(h, vchar(w));
    rep(y, h) rep(x, w) cin >> g[y][x];
    vvint v(h, vint(w, INF));

    priority_queue<edge, vector<edge>, greater<edge>> q;
    P start = P(y1, x1), goal = P(y2, x2);
    q.push(edge(0, start));
    v[y1][x1] = 0;

    vint dy = {0, 1, 0, -1}, dx = {1, 0, -1, 0};
    while (q.size())
    {
        edge e = q.top();
        q.pop();
        P p = e.p;

        if (p == goal)
        {
            break;
        }

        int now = e.c;
        rep(dir, 4) for (int i = 1; i <= k; i++)
        {
            int ny = p.fst + dy[dir] * i;
            int nx = p.snd + dx[dir] * i;
            if (ny < 0 || nx < 0 || ny > h - 1 || nx > w - 1 || g[ny][nx] == '@' || v[ny][nx] <= now)
            {
                break;
            }

            if (v[ny][nx] > now + 1)
            {
                v[ny][nx] = now + 1;
                q.push(edge(now + 1, P(ny, nx)));
            }
        }
    }

    ld ans = ceil(v[y2][x2]);
    if (ans == INF)
    {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}