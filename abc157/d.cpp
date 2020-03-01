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

vector<P> uft;
P par(int n)
{
    if (uft[n].first == n)
    {
        return uft[n];
    }

    return uft[n] = par(uft[n].first);
}

bool unite(int x, int y)
{
    P rx = par(x);
    P ry = par(y);
    if (rx.first == ry.first)
        return false;
    uft[rx.first].first = ry.first;
    uft[rx.first].second += ry.second;
    uft[ry.first].second += rx.second;
    return true;
}

int main()
{
    int v, e, k;
    cin >> v >> e >> k;
    uft = vector<P>(v);

    vector<vector<int>> g(v, vector<int>());
    queue<P> eg;
    rep(i, e)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        eg.push(P(a, b));
    }
    vector<vector<int>> block(v, vector<int>());
    rep(i, k)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        block[a].emplace_back(b);
        block[b].emplace_back(a);
    }

    rep(i, v) uft[i] = P(i, 1);
    while (eg.size())
    {
        P n = eg.front();
        eg.pop();
        unite(n.first, n.second);
    }

    rep(i, v)
    {
        P t = par(i);
        int cand = t.second;
        cand -= g[i].size() + 1;
        rep(j, block[i].size())
        {
            int b = block[i][j];

            if (par(b).first == par(i).first)
            {
                cand--;
            }
        }
        cout << max(0, cand) << " ";
    }

    cout << endl;

    return 0;
}