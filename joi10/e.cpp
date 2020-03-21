#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
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
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<char>> g(h, vector<char>(w));
    P s;
    vector<P> t(n);
    rep(y, h) rep(x, w)
    {
        cin >> g[y][x];
        if (g[y][x] == 'S')
            s = P(y, x);
        if (g[y][x] - '1' >= 0 && g[y][x] - '1' < n)
        {
            t[g[y][x] - '1'] = P(y, x);
        }
    }

    int ans = 0;
    rep(i, n)
    {
        queue<P> q;
        q.push(s);
        vector<vector<int>> d(h, vector<int>(w, -1));
        d[s.first][s.second] = 0;
        while (q.size())
        {
            P n = q.front();
            q.pop();
            int ny = n.first,
                nx = n.second;
            if (n == t[i])
            {
                break;
            }

            if (ny > 0 && g[ny - 1][nx] != 'X')
            {
                if (d[ny - 1][nx] < 0)
                {
                    d[ny - 1][nx] = d[ny][nx] + 1;
                    q.push(P(ny - 1, nx));
                }
            }
            if (ny < h - 1 && g[ny + 1][nx] != 'X')
            {
                if (d[ny + 1][nx] < 0)
                {
                    d[ny + 1][nx] = d[ny][nx] + 1;
                    q.push(P(ny + 1, nx));
                }
            }
            if (nx > 0 && g[ny][nx - 1] != 'X')
            {
                if (d[ny][nx - 1] < 0)
                {
                    d[ny][nx - 1] = d[ny][nx] + 1;
                    q.push(P(ny, nx - 1));
                }
            }
            if (nx < w - 1 && g[ny][nx + 1] != 'X')
            {
                if (d[ny][nx + 1] < 0)
                {
                    d[ny][nx + 1] = d[ny][nx] + 1;
                    q.push(P(ny, nx + 1));
                }
            }
        }
        int now = d[t[i].first][t[i].second];
        ans += now;
        s = t[i];
    }

    cout << ans << endl;

    return 0;
}