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
    vector<int> s(n);
    rep(i, n) cin >> s[i];

    int q;
    cin >> q;
    ll c = 0;
    rep(i, q)
    {
        int t;
        cin >> t;
        auto p = lower_bound(s.begin(), s.end(), t);

        if (p[0] == t)
        {
            c++;
        }
    }
    cout << c << endl;

    return 0;
}