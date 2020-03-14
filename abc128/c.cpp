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
    vector<int> s(m);
    vector<int> p(m);
    rep(i, m)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int ss;
            cin >> ss;
            ss--;
            s[i] += (1 << ss);
        }
    }
    rep(i, m) cin >> p[i];

    int ans = 0;
    rep(i, 1 << n)
    {
        bool on = true;
        rep(j, m)
        {
            int pc = __builtin_popcount(s[j] & i);
            if ((pc % 2) != p[j])
            {
                on = false;
                break;
            }
        }
        if (on)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}