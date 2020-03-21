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
    int r, c;
    cin >> r >> c;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;

    vector<vector<char>> g(r, vector<char>(c));
    rep(y, r) rep(x, c) cin >> g[y][x];

    queue<P> q;
    vector<vector<int>> d(r, vector<int>(c, -1));
    q.push(P(sy, sx));
    d[sy][sx] = 0;

    while (q.size())
    {
        P n = q.front();
        q.pop();
        if (n.first == gy && n.second == gx)
        {
            break;
        }

        if (n.first > 0 && g[n.first - 1][n.second] == '.')
        {
            if (d[n.first - 1][n.second] < 0)
            {
                d[n.first - 1][n.second] = d[n.first][n.second] + 1;
                q.push(P(n.first - 1, n.second));
            }
        }
        if (n.first < r - 1 && g[n.first + 1][n.second] == '.')
        {
            if (d[n.first + 1][n.second] < 0)
            {
                d[n.first + 1][n.second] = d[n.first][n.second] + 1;
                q.push(P(n.first + 1, n.second));
            }
        }
        if (n.second > 0 && g[n.first][n.second - 1] == '.')
        {
            if (d[n.first][n.second - 1] < 0)
            {
                d[n.first][n.second - 1] = d[n.first][n.second] + 1;
                q.push(P(n.first, n.second - 1));
            }
        }
        if (n.second < c - 1 && g[n.first][n.second + 1] == '.')
        {
            if (d[n.first][n.second + 1] < 0)
            {
                d[n.first][n.second + 1] = d[n.first][n.second] + 1;
                q.push(P(n.first, n.second + 1));
            }
        }
    }

    cout << d[gy][gx] << endl;

    return 0;
}