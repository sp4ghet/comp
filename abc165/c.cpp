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

int n, m, q;
int x[55][4];

int rec(int k, vint &a)
{

    // スコア計算
    if (a.size() == n)
    {
        int score = 0;
        rep(i, q)
        {
            auto now = x[i];

            if (a[now[1]] - a[now[0]] == now[2])
            {
                score += now[3];
            }
        }

        return score;
    }

    int ret = 0;
    for (int i = k; i <= m; i++)
    {
        vint newA = a;
        newA.emplace_back(i);
        ret = max(ret, rec(i, newA));
    }

    return ret;
}

int main()
{

    cin >> n >> m >> q;

    rep(i, q)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        x[i][0] = a;
        x[i][1] = b;
        x[i][2] = c;
        x[i][3] = d;
    }

    vint A = vint(1, 1);
    int ans = rec(1, A);

    cout << ans << endl;

    return 0;
}