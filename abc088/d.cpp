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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    int ans = 0;
    rep(y, h) rep(x, w)
    {
        cin >> g[y][x];
        ans += (int)(g[y][x] == '.');
    }

    queue<P> q;
    q.emplace(0, 0);
    vector<vector<int>> d(h, vector<int>(w, -1));
    d[0][0] = 0;
    while (q.size())
    {
        P n = q.front();
        q.pop();
        int ny = n.first, nx = n.second;
        if (n == P(h - 1, w - 1))
        {
            break;
        }

        if (ny > 0 && g[ny - 1][nx] == '.' && d[ny - 1][nx] < 0)
        {
            d[ny - 1][nx] = d[ny][nx] + 1;
            q.push(P(ny - 1, nx));
        }
        if (nx > 0 && g[ny][nx - 1] == '.' && d[ny][nx - 1] < 0)
        {
            d[ny][nx - 1] = d[ny][nx] + 1;
            q.push(P(ny, nx - 1));
        }
        if (ny < h - 1 && g[ny + 1][nx] == '.' && d[ny + 1][nx] < 0)
        {
            d[ny + 1][nx] = d[ny][nx] + 1;
            q.push(P(ny + 1, nx));
        }
        if (nx < w - 1 && g[ny][nx + 1] == '.' && d[ny][nx + 1] < 0)
        {
            d[ny][nx + 1] = d[ny][nx] + 1;
            q.push(P(ny, nx + 1));
        }
    }
    if (d[h - 1][w - 1] < 0)
    {
        ans = -1;
    }
    else
    {
        ans -= d[h - 1][w - 1] + 1;
    }

    cout << ans << endl;

    return 0;
}