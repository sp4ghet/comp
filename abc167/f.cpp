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
    int n;
    cin >> n;
    vp a, b;
    int tot = 0;
    rep(i, n)
    {
        string s;
        cin >> s;
        int h = 0, bot = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                h++;
            }
            if (c == ')')
            {
                h--;
                bot = min(bot, h);
            }
        }
        if (h > 0)
        {
            a.emplace_back(P(bot, h));
        }
        else
        {
            b.emplace_back(P(bot - h, -h));
        }
        tot += h;
    }
    sort(a.begin(), a.end(), greater<P>());
    sort(b.begin(), b.end(), greater<P>());

    int h = 0;
    bool ok = true;
    for (auto p : a)
    {
        if (h + p.first < 0)
            ok = false;
        h += p.second;
    }
    h = 0;
    for (auto p : b)
    {
        if (h + p.first < 0)
            ok = false;
        h += p.second;
    }
    if (tot != 0)
        ok = false;

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}