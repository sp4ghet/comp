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

int popRow(vvint &g, int y, int w, int k, int p)
{
    vint row = g[y];
    int score = 0;
    int add = pow(2, p);

    int li = 0, l = row[0];
    rep(i, w)
    {
        if (row[i] != l)
        {
            l = row[i];
            li = i;
            continue;
        }

        if (i - li >= k - 1)
        {
            for (int j = i; j >= li && g[y][j]; j--)
            {
                score += add * g[y][j];
                g[y][j] = 0;
            }
        }
    }

    return score;
}

int pop(vvint &g, int h, int w, int k, int p)
{
    int score = 0;
    rep(y, h)
    {
        score += popRow(g, y, w, k, p);
    }
    return score;
}

void shift(vvint &g, int h, int w)
{
    for (int y = h - 2; y >= 0; y--)
        rep(x, w)
        {
            int d = 1;
            while (y + d < h && g[y + d][x] == 0)
            {
                g[y + d][x] = g[y + d - 1][x];
                g[y + d - 1][x] = 0;
                d++;
            }
        }
}

int main()
{
    int h, w, k;
    cin >> h >> w >> k;

    vvint g(h, vint(w));
    rep(i, h)
    {
        string s;
        cin >> s;
        rep(j, w) g[i][j] = s[j] - '0';
    }

    vvint back = g;

    int ans = 0;
    rep(y, h) rep(x, w)
    {
        int now = 0;
        int p = 0;
        g[y][x] = 0;
        while (true)
        {
            shift(g, h, w);
            int newScore = pop(g, h, w, k, p);
            now += newScore;
            ++p;
            if (newScore == 0)
                break;
        }
        g = back;
        ans = max(now, ans);
    }

    cout << ans << endl;

    return 0;
}