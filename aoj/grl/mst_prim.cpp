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
    int v, e;
    cin >> v >> e;
    vector<vector<P>> g(v, vector<P>());
    rep(i, e)
    {
        int s, t, u;
        cin >> s >> t >> u;
        g[s].emplace_back(P(u, t));
        g[t].emplace_back(P(u, s));
    }

    priority_queue<P, vector<P>, greater<P>> q;
    vector<int> t;
    int ans = 0;

    int i = 0;
    t.emplace_back(0);
    while (t.size() < v)
    {
        for (auto v : g[i])
        {
            q.push(v);
        }
        P a = q.top();
        q.pop();

        while (binary_search(t.begin(), t.end(), a.second))
        {
            a = q.top();
            q.pop();
        }
        auto ub = upper_bound(t.begin(), t.end(), a.second);
        ans += a.first;
        t.emplace(ub++, a.second);

        i = a.second;
    }

    cout << ans << endl;

    return 0;
}