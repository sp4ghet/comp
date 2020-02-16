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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    bool ok = true;
    for (auto x : a)
    {
        if (x % 2 != 0)
        {
            continue;
        }
        if (x % 3 == 0 || x % 5 == 0)
        {
            continue;
        }
        ok = false;
        break;
    }

    string ans = ok ? "APPROVED" : "DENIED";
    cout << ans << endl;

    return 0;
}