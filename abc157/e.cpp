#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vchar = vector<char>;
using vvchar = vector<vchar>;
using vp = vector<P>;
using vpp = vector<pair<P, P>>;
using vvp = vector<vp>;

#define rep(i, n) for (int i = 0; i < n; ++i)
#pragma region Debug
istream &operator>>(istream &is, P &a)
{
    return is >> a.first >> a.second;
}
ostream &operator<<(ostream &os, const P &a) { return os << "(" << a.first << "," << a.second << ")"; }

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
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<set<int>> m(26);
    rep(i, n) m[s[i] - 'a'].insert(i);
    rep(i, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int j;
            char c;
            cin >> j >> c;
            j--;
            m[s[j] - 'a'].erase(j);
            m[c - 'a'].insert(j);
            s[j] = c;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int ans = 0;
            rep(j, 26)
            {

                auto lb = m[j].lower_bound(l);
                int lbn = lb == m[j].end() ? -1 : *lb;
                if (lbn >= l && lbn <= r)
                {
                    ans++;
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}