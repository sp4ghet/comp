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

vector<int> uft;
int find(int v)
{
    if (uft[v] == v)
    {
        return v;
    }
    int par = find(uft[v]);
    return uft[v] = par;
}
bool unite(int x, int y)
{
    int rx = find(x);
    int ry = find(y);
    if (rx == ry)
        return false;
    uft[rx] = ry;
    return true;
}

int main()
{
    int v, e;
    cin >> v >> e;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> g;
    rep(i, e)
    {
        int s, t, d;
        cin >> s >> t >> d;
        g.push(make_tuple(d, s, t));
    }

    uft = vector<int>(v);
    rep(i, v) uft[i] = i;
    int ans = 0;
    while (g.size())
    {
        auto e = g.top();
        g.pop();
        int d = get<0>(e);
        int s = get<1>(e);
        int t = get<2>(e);

        if (unite(s, t))
        {
            ans += d;
        }
    }

    cout << ans << endl;

    return 0;
}