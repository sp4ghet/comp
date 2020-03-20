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

vector<vector<int>> m;

void dfs(int x, int y, int h, int w)
{
    m[y][x] = 0;

    for (int i = max(0, y - 1); i <= min(h - 1, y + 1); ++i)
    {
        for (int j = max(0, x - 1); j <= min(w - 1, x + 1); ++j)
        {
            if (m[i][j])
            {
                // cout << y << " " << x << "->" << i << " " << j << endl;
                dfs(j, i, h, w);
            }
        }
    }
}

int main()
{
    int w = 1, h = 1;
    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
        {
            break;
        }
        m = vector<vector<int>>(h, vector<int>(w));
        rep(i, h) rep(j, w) cin >> m[i][j];

        int ans = 0;
        rep(i, h) rep(j, w)
        {
            if (m[i][j])
            {
                ans++;
                dfs(j, i, h, w);
            }
        }

        cout << ans << endl;
    }

    return 0;
}