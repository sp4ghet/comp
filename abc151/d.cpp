#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

int h, w;
vector<vector<char>> maze(21, vector<char>(21));
vector<vector<int>> current;
int cur_big = 0;
void dfs(int y, int x, int py = -1, int px = -1, int d = 0)
{
    if (current[y][x] != -1)
    {
        if (d >= current[y][x])
        {
            return;
        }
        current[y][x] = min(d, current[y][x]);
    }
    else
    {
        current[y][x] = d;
    }
    cur_big = max(current[y][x], cur_big);
    if (y > 0 && maze[y - 1][x] == '.' && y - 1 != py)
    {
        dfs(y - 1, x, y, x, d + 1);
    }
    if (y < h - 1 && maze[y + 1][x] == '.' && y + 1 != py)
    {
        dfs(y + 1, x, y, x, d + 1);
    }
    if (x > 0 && maze[y][x - 1] == '.' && x - 1 != px)
    {
        dfs(y, x - 1, y, x, d + 1);
    }
    if (x < w - 1 && maze[y][x + 1] == '.' && x + 1 != px)
    {
        dfs(y, x + 1, y, x, d + 1);
    }
}

int main()
{
    cin >> h >> w;
    rep(y, h)
    {
        rep(x, w)
        {
            cin >> maze[y][x];
        }
    }

    int big = 0;
    rep(y, h) rep(x, w)
    {
        if (maze[y][x] == '.')
        {
            int cur_big = 0;
            current = vector<vector<int>>(h, vector<int>(w, -1));
            dfs(y, x);
            for (auto &row : current)
            {
                for (auto &c : row)
                {
                    cur_big = max(cur_big, c);
                }
            }
            big = max(cur_big, big);
        }
    }

    cout << big << endl;

    return 0;
}