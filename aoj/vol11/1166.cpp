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
    int w, h;
    cin >> w >> h;
    do
    {
        vector<vector<vector<P>>> g(h, vector<vector<P>>(w, vector<P>()));
        int ls = 2 * h - 1;
        rep(i, ls)
        {
            int y = i / 2;
            if (i % 2 == 0)
            {
                rep(j, w - 1)
                {
                    int wall;
                    cin >> wall;
                    if (!wall)
                    {
                        g[y][j].emplace_back(P(y, j + 1));
                        g[y][j + 1].emplace_back(P(y, j));
                    }
                }
            }
            else
            {
                rep(j, w)
                {
                    int wall;
                    cin >> wall;
                    if (!wall)
                    {
                        g[y][j].emplace_back(P(y + 1, j));
                        g[y + 1][j].emplace_back(P(y, j));
                    }
                }
            }
        }

        queue<P> q;
        q.push(P(0, 0));
        vector<vector<int>> d(h, vector<int>(w, -1));
        d[0][0] = 1;
        while (q.size())
        {
            P n = q.front();
            q.pop();
            int ny = n.first,
                nx = n.second;
            if (n == P(h - 1, w - 1))
            {
                break;
            }

            for (P t : g[ny][nx])
            {
                int ty = t.first, tx = t.second;
                if (d[ty][tx] < 0)
                {
                    d[ty][tx] = d[ny][nx] + 1;
                    q.push(t);
                }
            }
        }

        cout << max(0, d[h - 1][w - 1]) << endl;

        cin >> w >> h;
    } while (w != 0 && h != 0);

    return 0;
}