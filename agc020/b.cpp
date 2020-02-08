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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    reverse(a.begin(), a.end());

    ll sml = 2,
       big = 2;

    rep(i, n)
    {

        ll mult = (sml + a[i] - 1LL) / a[i];
        ll bigMul = big / a[i];
        sml = mult * a[i];
        big = (bigMul + 1LL) * a[i] - 1LL;
        if (sml > big)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << sml << " " << big << endl;

    return 0;
}