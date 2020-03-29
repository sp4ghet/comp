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
    int v, e, r;
    cin >> v >> e >> r;
    vector<vector<P>> g(v, vector<P>());
    rep(i, e)
    {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].emplace_back(P(t, d));
    }

    // djikstra
    // ダイクストラ法
    vector<int> d(v, INT32_MAX);
    d[r] = 0;
    priority_queue<int> p;
    p.push(r);

    while (p.size())
    {
        int n = p.top();
        p.pop();
        for (P t : g[n])
        {
            int dist = d[n] + t.second;
            if (d[t.first] > dist)
            {
                d[t.first] = dist;
                p.push(t.first);
            }
        }
    }

    rep(i, v)
    {
        if (d[i] == INT32_MAX)
        {
            cout << "INF" << endl;
            continue;
        }
        cout << d[i] << endl;
    }

    return 0;
}