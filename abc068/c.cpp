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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> paths(n, vector<int>());
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[b].push_back(a);
    }

    string im = "IM";
    for (int a : paths[n - 1])
    {
        for (int start : paths[a])
        {
            im = start == 0 ? "" : im;
        }
    }

    cout << im << "POSSIBLE" << endl;

    return 0;
}