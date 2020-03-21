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
    cin >> w >> h;
    vector<vector<int>> g(h + 2, vector<int>(w + 2));
    rep(y, h) rep(x, w)
    {
        cin >> g[y + 1][x + 1];
    }

    queue<P> q;
    int ans = 0;

    q.push(P(0, 0));
    while (q.size())
    {
        P n = q.front();
        q.pop();
        int ny = n.first,
            nx = n.second;

        int now = 0;
        int l = nx;
        if (ny % 2 == 0)
        {
            l--;
        }
        // empty
        // left
        if (nx > 0 && g[ny][nx - 1] == 1)
        {
            now++;
        }
        // right
        if (nx < w + 1 && g[ny][nx + 1] == 1)
        {
            now++;
        }
        //up left
        if (l >= 0 && ny > 0 && g[ny - 1][l] == 1)
        {
            now++;
        }
        //up right
        if (ny > 0 && g[ny - 1][l + 1] == 1)
        {
            now++;
        }
        //low left
        if (ny < h + 1 && l >= 0 && g[ny + 1][l] == 1)
        {
            now++;
        }
        //low right
        if (ny < h + 1 && g[ny + 1][l + 1] == 1)
        {
            now++;
        }

        //movable
        // left
        if (nx > 0 && g[ny][nx - 1] == 0)
        {
            g[ny][nx - 1] = 2;
            q.push(P(ny, nx - 1));
        }
        // right
        if (nx < w + 1 && g[ny][nx + 1] == 0)
        {
            g[ny][nx + 1] = 2;
            q.push(P(ny, nx + 1));
        }
        //up left
        if (l >= 0 && ny > 0 && g[ny - 1][l] == 0)
        {
            g[ny - 1][l] = 2;
            q.push(P(ny - 1, l));
        }
        //up right
        if (ny > 0 && l < w + 1 && g[ny - 1][l + 1] == 0)
        {
            g[ny - 1][l + 1] = 2;
            q.push(P(ny - 1, l + 1));
        }
        //low left
        if (ny < h + 1 && l >= 0 && g[ny + 1][l] == 0)
        {
            g[ny + 1][l] = 2;
            q.push(P(ny + 1, l));
        }
        //low right
        if (ny < h + 1 && l < w + 1 && g[ny + 1][l + 1] == 0)
        {
            g[ny + 1][l + 1] = 2;
            q.push(P(ny + 1, l + 1));
        }

        ans += now;
    }

    cout << ans << endl;
    return 0;
}