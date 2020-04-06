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

int cs[3][1002][1002];
int main()
{
    int h, w, k;
    cin >> h >> w >> k;

    map<char, int> tb;
    tb['J'] = 0;
    tb['O'] = 1;
    tb['I'] = 2;

    rep(y, h)
    {
        string s;
        cin >> s;
        rep(x, w)
        {
            int i = tb[s[x]];
            rep(j, 3) cs[j][y + 1][x + 1] = cs[j][y + 1][x] + cs[j][y][x + 1] - cs[j][y][x];
            cs[i][y + 1][x + 1]++;
        }
    }

    vint ans(3);
    rep(i, k)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;
        x1--;
        rep(j, 3)
        {
            auto c = cs[j];
            ans[j] = c[y2][x2] - c[y2][x1] - c[y1][x2] + c[y1][x1];
        }
        printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    }

    return 0;
}