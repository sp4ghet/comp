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
vector<vector<int>> g;
vector<vector<int>> e;
int m, n;
int dfs(int y, int x, vector<vector<int>> k, int d, int py = 0, int px = 0)
{
    if (k[y][x])
    {
        return d;
    }
    k[y][x] = 1;
    d++;

    // cout << x << " " << y << " "
    //      << py << " " << px << " " << d << endl;
    // view(k);
    // cout << endl;

    int j = d;
    if (y > 0 && g[y - 1][x])
    {
        j = max(j, dfs(y - 1, x, k, d, y, x));
    }
    if (y < n - 1 && g[y + 1][x])
    {
        j = max(j, dfs(y + 1, x, k, d, y, x));
    }
    if (x > 0 && g[y][x - 1])
    {
        j = max(j, dfs(y, x - 1, k, d, y, x));
    }
    if (x < m - 1 && g[y][x + 1])
    {
        j = max(j, dfs(y, x + 1, k, d, y, x));
    }

    // if (!(y > 0 && g[y - 1][x]) && !(y < n - 1 && g[y + 1][x]) && !(x > 0 && g[y][x - 1]) && !(x < m - 1 && g[y][x + 1]))
    // {
    //     return d;
    // }
    return j;
}

int main()
{
    cin >> m >> n;
    g = vector<vector<int>>(n, vector<int>(m));

    int c = 0;
    rep(y, n) rep(x, m)
    {
        cin >> g[y][x];
        if (g[y][x])
            ++c;
    }

    int ans = 0;
    rep(y, n) rep(x, m)
    {
        if (ans >= c)
        {
            break;
        }
        if (!g[y][x])
            continue;

        e = vector<vector<int>>(n, vector<int>(m));

        int now = dfs(y, x, e, 0);
        ans = max(now, ans);
    }

    cout << ans << endl;

    return 0;
}