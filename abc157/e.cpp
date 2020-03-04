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
    vector<set<int>> s(26, set<int>());
    rep(i, n)
    {
        char a;
        cin >> a;
        a -= 'a';
        s[a].insert(i + 1);
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int iq;
            char c;
            cin >> iq >> c;
            c -= 'a';
            rep(j, 26)
            {
                s[j].erase(iq);
            }
            s[c].insert(iq);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            rep(j, 26)
            {
                int lb = *s[j].lower_bound(l);
                if (lb >= l && lb <= r)
                {
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}