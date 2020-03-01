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
    vector<vector<char>> c(h, vector<char>(w));
    vector<P> f(n);
    P s;
    queue<P> q;
    rep(i, h) rep(j, w)
    {
        cin >> c[i][j];
        if (c[i][j] == 'S')
        {
            s = P(i, j);
        }
        int factory = c[i][j] - '0' - 1;
        if (factory >= 0 && factory < n)
        {
            f[factory] = P(i, j);
        }
    }

    int ans = 0;
    rep(i, n)
    {
        P g = f[i];
        vector<vector<int>> d(h, vector<int>(w, -1));
        d[s.first][s.second] = 0;
        q.push(s);
        while (q.size())
        {
            P n = q.front();
            q.pop();

            int nd = d[n.first][n.second];
            if (n == g)
            {
                ans += nd;
                q = queue<P>();
                break;
            }
            if (n.first > 0 && c[n.first - 1][n.second] != 'X' && d[n.first - 1][n.second] == -1)
            {
                q.push(P(n.first - 1, n.second));
                d[n.first - 1][n.second] = nd + 1;
            }

            if (n.second > 0 && c[n.first][n.second - 1] != 'X' && d[n.first][n.second - 1] == -1)
            {
                q.push(P(n.first, n.second - 1));
                d[n.first][n.second - 1] = nd + 1;
            }
            if (n.first < h - 1 && c[n.first + 1][n.second] != 'X' && d[n.first + 1][n.second] == -1)
            {
                q.push(P(n.first + 1, n.second));
                d[n.first + 1][n.second] = nd + 1;
            }

            if (n.second < w - 1 && c[n.first][n.second + 1] != 'X' && d[n.first][n.second + 1] == -1)
            {
                q.push(P(n.first, n.second + 1));
                d[n.first][n.second + 1] = nd + 1;
            }
        }
        s = g;
    }

    cout << ans << endl;

    return 0;
}