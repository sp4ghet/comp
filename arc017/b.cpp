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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<bool> g(n - 1);
    rep(i, n - 1)
    {
        g[i] = a[i + 1] > a[i];
    }

    int ans = 0;
    int cnt = 0;
    rep(i, n - 1)
    {
        if (a[i + 1] > a[i])
        {
            cnt++;
        }
        else
        {
            ans += max(0, cnt - k + 2);
            cnt = 0;
        }
    }
    ans += max(0, cnt - k + 2);

    cout << ans << endl;

    return 0;
}