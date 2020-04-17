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
    string s;
    cin >> n >> s;

    vvint rgb(3, vint());
    rep(i, n)
    {
        switch (s[i])
        {
        case 'R':
            rgb[0].emplace_back(i);
            break;
        case 'G':
            rgb[1].emplace_back(i);
            break;
        case 'B':
            rgb[2].emplace_back(i);
            break;
        }
    }

    ll ans = 0;
    for (int r : rgb[0])
    {
        for (int g : rgb[1])
        {

            ans += rgb[2].size();

            if (r > g)
            {
                int ku = r + (r - g);
                int kd = g - (r - g);

                if (ku < n && s[ku] == 'B')
                    ans--;
                if (kd >= 0 && s[kd] == 'B')
                    ans--;
            }
            else
            {
                int ku = g + (g - r);
                int kd = r - (g - r);
                if (ku < n && s[ku] == 'B')
                    ans--;
                if (kd >= 0 && s[kd] == 'B')
                    ans--;
            }

            if ((r + g) % 2)
                continue;
            int km = (r + g) / 2;
            if (s[km] == 'B')
                ans--;
        }
    }

    cout << ans << endl;

    return 0;
}