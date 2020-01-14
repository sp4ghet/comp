#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
template <typename T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

map<int, vector<int>> dag;
vector<int> max_depth;
int ans = 0;
void dfs(int v, int d = 0)
{
    chmax(max_depth[v], d);
    chmax(ans, max_depth[v]);
    for (auto &child : dag[v])
    {
        dfs(child, d + 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<bool> start(n, true);
    max_depth = vector<int>(n, 0);
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        dag[x].push_back(y);
        start[y] = false;
    }

    rep(i, n)
    {
        if (!start[i])
            continue;

        dfs(i);
    }

    cout << ans << endl;

    return 0;
}