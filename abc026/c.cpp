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

vector<vector<int>> tree(20, vector<int>());

int bfs(int node)
{
    if (tree[node].size() == 0)
    {
        return 1;
    }
    int maxPay = 0, minPay = INT32_MAX;
    for (int &child : tree[node])
    {
        int pay = bfs(child);
        maxPay = max(maxPay, pay);
        minPay = min(minPay, pay);
    }
    return maxPay + minPay + 1;
}

int main()
{
    int n;
    cin >> n;

    rep(i, n - 1)
    {
        int c;
        cin >> c;
        c--;
        tree[c].push_back(i + 1);
    }

    int ans = bfs(0);

    cout << ans << endl;

    return 0;
}