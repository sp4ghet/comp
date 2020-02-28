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

vector<vector<char>> m;
vector<vector<int>> d;
queue<P> q;

int bfs(P g, int r, int c)
{
    while (q.size())
    {
        P n = q.front();
        q.pop();
        int nd = d[n.first][n.second];
        if (n.first == g.first && n.second == g.second)
        {
            return nd;
        }
        if (n.first < r - 1 && d[n.first + 1][n.second] == -1 && m[n.first + 1][n.second] == '.')
        {
            q.push(P(n.first + 1, n.second));
            d[n.first + 1][n.second] = nd + 1;
        }
        if (n.first > 0 && d[n.first - 1][n.second] == -1 && m[n.first - 1][n.second] == '.')
        {
            q.push(P(n.first - 1, n.second));
            d[n.first - 1][n.second] = nd + 1;
        }
        if (n.second < c - 1 && d[n.first][n.second + 1] == -1 && m[n.first][n.second + 1] == '.')
        {
            q.push(P(n.first, n.second + 1));
            d[n.first][n.second + 1] = nd + 1;
        }
        if (n.second > 0 && d[n.first][n.second - 1] == -1 && m[n.first][n.second - 1] == '.')
        {
            q.push(P(n.first, n.second - 1));
            d[n.first][n.second - 1] = nd + 1;
        }
    }
    return d[g.first][g.second];
}

int main()
{
    int r, c;
    P s, g;
    cin >> r >> c >> s.first >> s.second >> g.first >> g.second;
    s.first--;
    s.second--;
    g.first--;
    g.second--;

    m = vector<vector<char>>(r, vector<char>(c));
    d = vector<vector<int>>(r, vector<int>(c, -1));
    rep(i, r) rep(j, c) cin >> m[i][j];

    q.push(s);
    d[s.first][s.second] = 0;
    int ans = bfs(g, r, c);

    cout << ans << endl;

    return 0;
}