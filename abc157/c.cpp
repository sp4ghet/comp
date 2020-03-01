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
    vector<int> a(n, -1);
    rep(i, m)
    {
        int s, c;
        cin >> s >> c;
        s--;
        if (a[s] == -1 || a[s] == c)
        {
            a[s] = c;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if (a[0] == 0 && n != 1)
    {
        cout << -1 << endl;
        return 0;
    }
    if (a[0] == -1 && n == 1)
    {
        a[0] = 0;
    }
    if (a[0] == -1)
    {
        a[0] = 1;
    }
    int ans = 0;

    rep(i, n)
    {
        if (a[i] == -1)
        {
            a[i] = 0;
        }
        ans += a[i] * pow(10, n - i - 1);
    }
    cout << ans << endl;

    return 0;
}