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
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>());
    vector<int> d(n, -1);

    rep(i, n)
    {
        int k;
        cin >> k >> k;
        rep(j, k)
        {
            int t;
            cin >> t;
            t--;
            g[i].emplace_back(t);
        }
    }

    queue<int> q;
    q.push(0);
    d[0] = 0;
    while (q.size())
    {
        int v = q.front();
        q.pop();

        for (auto nv : g[v])
        {
            if (d[nv] >= 0)
                continue;

            d[nv] = d[v] + 1;
            q.push(nv);
        }
        // cout << v << " " << q.size() << endl;
    }

    rep(i, n)
    {
        cout << (i + 1) << " " << d[i] << endl;
    }

    return 0;
}