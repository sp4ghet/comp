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
    int n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;
    vector<vector<int>> g(n, vector<int>());
    rep(i, n - 1)
    {
        g[i].emplace_back(i + 1);
        g[i + 1].emplace_back(i);
    }
    g[x].emplace_back(y);
    g[y].emplace_back(x);

    vector<vector<int>> ds(n, vector<int>(n, -1));
    rep(i, n)
    {
        queue<int> q;
        q.push(i);
        ds[i][i] = 0;
        while (q.size())
        {
            int v = q.front();
            q.pop();
            for (int nv : g[v])
            {
                if (ds[i][nv] >= 0)
                    continue;
                ds[i][nv] = ds[i][v] + 1;
                q.push(nv);
            }
        }
    }

    vector<int> d(n);
    rep(i, n) rep(j, n)
    {
        d[ds[i][j]] += 1;
    }

    for (int i = 1; i < n; ++i)
    {
        cout << d[i] / 2 << endl;
    }

    return 0;
}